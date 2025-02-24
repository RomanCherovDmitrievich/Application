#include "mainwindow.h"
#include "secondwindow.h"
#include "autorization.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TestAplication_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    a.setOrganizationName("Polyteh");
    a.setApplicationName("Airport");
    a.setApplicationVersion("1.0.0");

    QSqlDatabase db;
    QSqlQuery *query;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Airport2.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }


    query = new QSqlQuery(db);
    //Очистка таблиц
    query->exec("DELETE FROM Flights;");
    query->exec("DELETE FROM Tickets;");
    query->exec("DELETE FROM Users;");
    //Создание таблиц
    query->exec("CREATE TABLE Flights(ID_Flights INTEGER, Route TEXT, Number_Place INTEGER, Time TEXT);");
    query->exec("CREATE TABLE Tickets(ID_Ticket INTEGER, Route TEXT, ID_Fligths INTEGER, Price TEXT, Time TEXT, Place_in_Plane TEXT);");
    query->exec("CREATE TABLE Users(ID_User INTEGER, Name TEXT, ID_Ticket TEXT);");
    //Заполнене данных в таблицы
    query->exec("INSERT INTO Flights(ID_Flights, Route, Number_Place, Time) VALUES (1, 'London', 120, '12.01.2024'), (2, 'USA', 100, '13.01.2024'), (3, 'Russia', 100, '13.01.2024');");
    query->exec("INSERT INTO Tickets(ID_Ticket, Route, Price, Time, Place_in_Plane) VALUES (1003, 'London', '13:20', '7B'), (2001, 'USA', '19:40', '4A'), (3002, 'Russia', '20:15', '5C');");
    query->exec("INSERT INTO Users(ID_User, Name, ID_Ticket) VALUES (1, 'Kirill', 1), (2, 'Roma', 2), (3, 'Ivan', 3);");

    QSqlTableModel model_Flights;
    model_Flights.setTable("Flights");
    model_Flights.select();

    //QMainWindow *window = new QMainWindow();
    //QTableView *tableView = new QTableView();
    //tableView->setModel(&model_Flights);
    //window->setCentralWidget(tableView);
    //window->show();


    QSqlTableModel model_Tickets;
    model_Tickets.setTable("Tickets");
    model_Tickets.select();
    QSqlTableModel model_Users;
    model_Users.setTable("Users");
    model_Users.select();

    MainWindow w;
    //w.show();

    SecondWindow sw;
    //sw.show();

    Autorization au;
    au.show();


    return a.exec();
}
