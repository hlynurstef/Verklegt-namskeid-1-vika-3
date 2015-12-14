#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include "data_types/computer.h"
#include "services/computerservice.h"
#include <QFile>
namespace Ui {
class editComputer;
}

class editComputer : public QDialog
{
    Q_OBJECT

public:
    explicit editComputer(QWidget *parent = 0);
    ~editComputer();

private slots:
    void on_pushButton_editcomputer_clicked();

private:
    Ui::editComputer *ui;
};

#endif // EDITCOMPUTER_H
