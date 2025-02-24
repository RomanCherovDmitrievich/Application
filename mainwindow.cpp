#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QApplication>
#include <QTableView>

#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QWidget>
#include <QSqlQuery>
#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Airport2.db");
    if(db.open()) // открываю базу данных
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
    query = new QSqlQuery(db);

    //Создание модели для таблицы Flights
    modelFlights = new QSqlTableModel(this, db);
    modelFlights->setTable("Flights");
    modelFlights->select();
    ui->tableFlights->setModel(modelFlights);

    //Создание модели для таблицы Tickets
    model_Tickets = new QSqlTableModel(this, db);
    model_Tickets->setTable("Tickets");

    //Названия столбцов
    //model_Flights->setHeaderData(0, Qt::Horizontal, "ID Маршрута");
    //model_Flights->setHeaderData(1, Qt::Horizontal, "Маршрут");
    //model_Flights->setHeaderData(2, Qt::Horizontal, "Количество мест в самолёте");
    //model_Flights->setHeaderData(3, Qt::Horizontal, "Дата вылета");
    //model_Flights->setHeaderData(4, Qt::Horizontal, "Время рейса");
    //model_Flights->setHeaderData(5, Qt::Horizontal, "Цена билета");

    //model_Flights->select();
    //model_Tickets->select();

    /*
    // Объединение моделей с помощью QSortFilterProxyModel
    QSortFilterProxyModel proxyModel;
    proxyModel.setSourceModel(model_Flights);
    proxyModel.setSourceModel(model_Tickets);
  */
    //QSqlRelationalTableModel model;
    //model.setTable("Flights");
    //model.setRelation(1, QSqlRelation("Tickets", "ID_Ticket", "Price")); // Связь с таблицей Tickets по полю TicketID


    //ui->tableFlights->setModel(&model);


    //ui->tableFlights->setModel(model_Flights);
    //ui->tableFlights->setSelectionMode(QAbstractItemView::SingleSelection); // Устанавливаем режим выделения лишь одно строки в таблице
    //ui->tableView->setColumnHidden(3, true);    // Скрываем 3 колонку


    model_Users = new QSqlTableModel(this, db);
    model_Users->setTable("Users");

    //Названия столбцов
    //model_Users->setHeaderData(0, Qt::Horizontal, "ID Пользователя");
    //model_Users->setHeaderData(1, Qt::Horizontal, "Имя пользователя");
    //model_Users->setHeaderData(2, Qt::Horizontal, "Маршрут");
    //model_Users->setHeaderData(3, Qt::Horizontal, "Место в самолёте");
    //model_Users->setHeaderData(4, Qt::Horizontal, "Цена билета");


    model_Users->select();
    ui->tableUsers->setModel(model_Users);
    ui->tableUsers->setEditTriggers(QAbstractItemView::NoEditTriggers);// Блокирую доступ к изменению в таблице

}

void MainWindow::on_AddFlight_clicked()
{
    modelFlights->insertRow(modelFlights->rowCount());
}

void MainWindow::on_DeleteFlight_clicked()
{
    modelFlights->removeRow(row);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void MainWindow::Set_UserName(QString set_name)
{
    name = set_name;
}

void MainWindow::Set_UserFlight(QString set_flightuser)
{
    userflight = set_flightuser;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
    emit signalAutorizationShow();
}

MainWindow::~MainWindow()
{
    delete ui;
}
