#include "secondwindow.h"
#include "ui_secondwindow.h"

#include <QTime>

SecondWindow::SecondWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Airport2.db");
    db.open();

    model = new QSqlTableModel(this, db);
    model->setTable("Flights");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);// Блокирую доступ к изменению в таблице
}

void SecondWindow::UserGetTicket()
{
    query = new QSqlQuery(db);

    //query->exec("SELECT ID_Ticket FROM Flight WHERE "  + iterFlight); // проверка на одинаковый айди билета

    QString comand = "INSERT Users(ID_User, Name, ID_Ticket) VALUES (";
    comand += ID_user + ",'" + name_user + "',12";
    comand += ");";



    query->exec(comand);

}


void SecondWindow::on_pushButton_3_clicked()
{
    this->close();
    emit signalAutorizationShow();
}

void SecondWindow::set_NameUser(QString set_name_user)
{
    name_user = set_name_user;
    ui->loginName->setText(name_user);
}

void SecondWindow::set_IDUser(QString ID)
{
    ID_user = ID;
}

void SecondWindow::on_pushButton_clicked()
{
    iterFlight = ui->iterFlights->text();
    SecondWindow::UserGetTicket();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
