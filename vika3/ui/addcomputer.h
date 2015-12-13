#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include "data_types/computer.h"
#include "services/computerservice.h"

#include <QDialog>

namespace Ui {
class addComputer;
}

class addComputer : public QDialog
{
    Q_OBJECT

public:
    explicit addComputer(QWidget *parent = 0);
    ~addComputer();

    bool errorCheck(string name, string type, string wasItBuilt, string buildYear, string description);

private slots:
    void on_button_add_computer_clicked();

private:
    Ui::addComputer *ui;
    Computer compService;
};

#endif // ADDCOMPUTER_H
