#ifndef MOREINFOCOMPUTER_H
#define MOREINFOCOMPUTER_H
#include "data_types/computer.h"
#include "services/computerservice.h"
#include "ui/mainwindow.h"

#include <QDialog>

namespace Ui {
class MoreInfoComputer;
}

class MoreInfoComputer : public QDialog
{
    Q_OBJECT

public:
    explicit MoreInfoComputer(QWidget *parent = 0);
    ~MoreInfoComputer();

    void displayInfo();

private:
    Ui::MoreInfoComputer *ui;
    Computer computer;
    MainWindow mainwindow;
};

#endif // MOREINFOCOMPUTER_H
