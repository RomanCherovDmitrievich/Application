#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "secondwindow.h"
#include <QSqlRelationalTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalAutorizationShow();
public:
    void Set_UserName(QString set_name);
    void Set_UserFlight(QString set_userflight);
    QSqlQueryModel* executeQuery(const QString& query);

private slots:

    void on_AddFlight_clicked();

    void on_DeleteFlight_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SecondWindow sec_ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *modelFlights;
    //QSqlRelationalTableModel *model_Flights;
    QSqlTableModel *model_Tickets;
    QSqlTableModel *model_Users;

    int row;
    QString name;
    QString userflight;
};
#endif // MAINWINDOW_H
