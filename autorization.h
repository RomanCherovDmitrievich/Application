#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include <QMainWindow>

#include "mainwindow.h"

namespace Ui {
class Autorization;
}

class Autorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit Autorization(QWidget *parent = nullptr);
    ~Autorization();

private slots:
    void on_ButtonAutorization_clicked();

private:
    Ui::Autorization *ui;
    MainWindow *main_ui;
    SecondWindow *sec_ui;
};

#endif // AUTORIZATION_H
