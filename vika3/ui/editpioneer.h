#ifndef EDITPIONEER_H
#define EDITPIONEER_H

#include "data_types/pioneer.h"
#include "data_types/relation.h"
#include "data_types/computer.h"
#include "services/pioneerservice.h"
#include "services/relationservice.h"
#include "services/computerservice.h"

#include <QDialog>
#include <QPixmap>

namespace Ui {
class editPioneer;
}

class editPioneer : public QDialog
{
    Q_OBJECT

public:
    explicit editPioneer(QWidget *parent = 0);
    ~editPioneer();

    void setPioneer(Pioneer pio);
        // Sets the information from pio to the edit window
    bool errorCheck(string name, string sex, string birthyear, string deathyear, string description);
        // Checks for errors and displays them, returns true if error was displayed
    void displayRelatedComputers();
        // Displays vector of Related Computers
    void displayUnrelatedComputers();
        // Displays vector of Unrelated Computers
    string getCurrentSex();
        // Returns currently chosen sex from dropdown_sex
    bool is_number(string& s);
        // Returns true if string is a number, false if there is a nondigit in there somewhere
    void emptyLines();
        // Clears all the error messages

private slots:
    void on_button_edit_pioneer_clicked();
    void on_list_unrelated_computers_clicked(const QModelIndex &);
    void on_list_related_computers_clicked(const QModelIndex &);
    void on_button_cancel_clicked();
    void on_button_remove_relation_clicked();
    void on_button_add_relation_clicked();
    void on_pushButton_browse_image_clicked();

    void on_button_remove_image_clicked();

private:
    Ui::editPioneer *ui;
    PioneerService pioService;
    RelationService relService;
    ComputerService compService;
    Relation rel;
    vector<Computer> relatedComputers, unrelatedComputers;
    QByteArray currentImage;
    QByteArray image;

    int pioID;
};

#endif // EDITPIONEER_H
