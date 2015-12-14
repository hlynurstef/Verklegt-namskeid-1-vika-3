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
    void displayUnrelatedComputers(vector<Computer> unrelatedComputers);
        // Prints vector of computers in the unrelated computers list
    void displayRelatedComputers(vector<Computer> relatedComputers);
        // Prints vector of computers in the unrelated computers list
private slots:
    void on_button_add_pioneer_clicked();
    void on_list_unrelated_computers_clicked();
    void on_button_add_relation_clicked();
    void on_button_remove_relation_clicked();
    void on_list_related_computers_clicked();

private:
    Ui::AddPioneer *ui;
    PioneerService pioService;
    vector<Computer> unrelatedComputersList;    // This vector holds onto every computer that is currently displayed on main window
    vector<Computer> relatedComputersList;      // This vector holds onto every computer related to Pioneer
};

#endif // ADDPIONEER_H
