#include "autorization.h"
#include "ui_autorization.h"



Autorization::Autorization(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Autorization)
{
    ui->setupUi(this);

    main_ui = new MainWindow();
    connect(main_ui, &MainWindow::signalAutorizationShow,this, &MainWindow::show);

    sec_ui = new SecondWindow();
    connect(sec_ui, &SecondWindow::signalAutorizationShow,this, &MainWindow::show);
}

Autorization::~Autorization()
{
    delete ui;
}

void Autorization::on_ButtonAutorization_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    if(login == "admin")
    {
        hide();
        main_ui->show();

    }
    else if(login == "Roma")
    {
        hide();
        sec_ui->show();
        sec_ui->set_NameUser(login);
    }
    else if(login == "Kirill")
    {
        hide();
        sec_ui->show();
        sec_ui->set_NameUser(login);
    }
    else if(login == "Ivan")
    {
        hide();
        sec_ui->show();
        sec_ui->set_NameUser(login);
    }
    else
    {
        hide();
        QApplication::quit();
    }
}


