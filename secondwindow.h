#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

//#include "mainwindow.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void set_NameUser(QString set_name_user);
private:
    void UserGetTicket();
    void set_IDUser(QString ID);

signals:
    void signalAutorizationShow();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui;
    //MainWindow *main_ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQuery *query;

    QString name_user;
    QString iterFlight;
    QString ID_user;

};

#endif // SECONDWINDOW_H
