#ifndef ADDPIONEER_H
#define ADDPIONEER_H
#include <string>
#include <vector>
#include "services/pioneerservice.h"
#include "services/relationservice.h"
#include "data_types/pioneer.h"

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class AddPioneer;
}

class AddPioneer : public QDialog
{
    Q_OBJECT

public:
    explicit AddPioneer(QWidget *parent = 0);
    ~AddPioneer();

    bool errorCheck(string name, string sex, string birthyear, string deathyear, string description);
    void emptyLines();
    void setUnrelatedComputers(vector<Computer> currentlyDisplayedComputers);
        // Gets currently displayed computers and prints them in the unrelated computers list
private slots:
    void on_button_add_pioneer_clicked();

private:
    Ui::AddPioneer *ui;
    PioneerService pioService;
};

#endif // ADDPIONEER_H
