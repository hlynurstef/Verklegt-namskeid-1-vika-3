#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H
#include "data_types/computer.h"
#include "services/computerservice.h"
#include "ui/mainwindow.h"
#include <QDialog>


namespace Ui {
class editComputer;
}

class editComputer : public QDialog
{
    Q_OBJECT

public:
    explicit editComputer(QWidget *parent = 0);
    ~editComputer();

    void setComputer(Computer computer);

private slots:


    void on_button_cancel_clicked();

private:
    Ui::editComputer *ui;
    Computer computer;
    MainWindow mainwindow;
};

#endif // EDITCOMPUTER_H
