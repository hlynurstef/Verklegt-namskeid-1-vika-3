#ifndef ADDPIONEER_H
#define ADDPIONEER_H
#include <string>
#include <vector>
#include "services/pioneerservice.h"
#include "services/relationservice.h"
#include "data_types/pioneer.h"

#include <QDialog>
#include <QMainWindow>
#include <QPixmap>

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
        // Displays error messages and returns true if there were any error messages displayed
    void emptyLines();
        // Clears all error messages from the window
    void displayUnrelatedComputers(vector<Computer> unrelatedComputers);
        // Prints vector of computers in the unrelated computers list
    void displayRelatedComputers(vector<Computer> relatedComputers);
        // Prints vector of computers in the unrelated computers list
    bool is_number(string& s);
        // Returns true if inputted string is a number, false if there is a letter or symbol in there
    string getCurrentSex();
        // Returns what is chosen in dropdown_sex

private slots:
    void on_button_add_pioneer_clicked();
    void on_list_unrelated_computers_clicked(const QModelIndex &);
    void on_list_related_computers_clicked(const QModelIndex &);
    void on_button_pioneer_add_relation_clicked();
    void on_button_pioneer_remove_relation_clicked();
    void on_button_add_pioneer_cancel_clicked();
    void on_pushButton_browse_image_clicked();

private:
    Ui::AddPioneer *ui;
    PioneerService pioService;
    RelationService relationService;
    vector<Computer> unrelatedComputersList;    // This vector holds onto every computer that is currently displayed on main window
    vector<Computer> relatedComputersList;      // This vector holds onto every computer related to Pioneer
    QByteArray inByteArray;                     // This vector holds onto the image of the pioneer
};

#endif // ADDPIONEER_H
