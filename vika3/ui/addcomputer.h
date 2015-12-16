#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include "data_types/computer.h"
#include "services/computerservice.h"
#include "services/relationservice.h"

#include <QDialog>
#include <QMainWindow>
#include <QPixmap>

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
        // Checks if there are errors in input
    void emptyLines();
        // Clears all lines as soon as the window is opened
    void displayUnrelatedPioneers(vector<Pioneer> unrelatedPioneers);
        // Prints vector of pioneers in the unrelated pioneers list
    void displayRelatedPioneers(vector<Pioneer> relatedPioneers);
        // Prints vector of pioneers in the related pioneers list
    bool is_number(string& s);
        // Returns true if string is only numbers, false otherwise
    string getCurrentType();
        // Returns current chosen item in type dropdown list
    string getCurrentWasItBuilt();
        // Returns current chosen item in was it built dropdown list

private slots:
    void on_button_add_computer_clicked();

    void on_button_computer_cancel_clicked();

    void on_list_related_pioneers_clicked(const QModelIndex &);

    void on_list_unrelated_pioneers_clicked(const QModelIndex &);

    void on_button_add_relation_clicked();

    void on_button_remove_relation_clicked();

    void on_pushButton_image_clicked();

private:
    Ui::addComputer *ui;
    ComputerService computerService;
    RelationService relationService;
    vector<Pioneer> unrelatedPioneersList;    // This vector holds onto every computer that is currently displayed on main window
    vector<Pioneer> relatedPioneersList;      // This vector holds onto every computer related to Pioneer
    QByteArray inByteArray;                   // This vector holds onto the image of the computer
};

#endif // ADDCOMPUTER_H
