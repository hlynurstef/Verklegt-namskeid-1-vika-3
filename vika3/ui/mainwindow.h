#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "services/pioneerservice.h"
#include "services/computerservice.h"
#include "addpioneer.h"
#include "addcomputer.h"
#include "editpioneer.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Pioneer returnCurrentlySelectedPioneer();
    Computer returnCurrentlySelectedComputer();
    void disableButtonsForPioneer();
    void disableButtonsForComputer();

    vector<Computer> returnAllComputers();
private slots:
    void on_input_search_pioneers_textChanged();
        // Searches for matches as soon as the search string has changed "search as you type"
    void on_input_search_computers_textChanged();
        // Searches for matches as soon as the search string has changed "search as you type"
    void on_dropdown_pioneers_order_by_currentIndexChanged(int index);
        // Orders list by a specific column when user chooses from dropdown list
    void on_dropdown_computers_order_by_currentIndexChanged(int index);
        // Orders list by a specific column when user chooses from dropdown list
    void on_dropdown_pioneers_order_direction_currentIndexChanged(int index);
        // Orders list in ascending or descending fashion when user chooses from dropdown list
    void on_dropdown_computers_order_direction_currentIndexChanged(int index);
        // Orders list in ascending or descending fashion when user chooses from dropdown list
    void on_dropdown_pioneers_filter_gender_currentIndexChanged(int index);
        // Filters pioneers list by gender when user chooses from dropdown list
    void on_dropdown_pioneers_filter_vital_status_currentIndexChanged(int index);
        // Filters pioneers by alive or deceased (or no filter) when user chooses from dropdown list
    void on_dropdown_computers_filter_type_currentIndexChanged(int index);
        // Filters computers by type when user chooses from dropdown list
    void on_dropdown_computers_filter_built_currentIndexChanged(int index);
        // Filters computers by if the computer was built or not when user chooses from dropdown list

    void on_button_pioneer_remove_clicked();
        // Removes selected pioneer from list when Remove button is clicked
    void on_button_computer_remove_clicked();
        // Removes selected computer from list when Remove button is clicked

    void on_table_pioneers_clicked(const QModelIndex &index);
        // Enables the "More Info" and "Remove Selected" buttons when an entry is clicked in table
    void on_table_computers_clicked(const QModelIndex &index);
        // Enables the "More Info" and "Remove Selected" buttons when an entry is clicked in table

    void on_pushButton_pioneers_add_new_entry_clicked();
        // Opens a new window for adding new pioneers
    void on_pushButton_computers_add_new_entry_clicked();
        // Opens a new window for adding new computer

    void on_pushButton_pioneers_more_info_clicked();
        // Opens up a new window that displays more info about the selected pioneer
    void on_pushButton_computers_more_info_clicked();
        // Opens up a new window that displays more info about the selected computer

    void on_pushButton_pioneers_edit_clicked();
        // Opens up a new window that allows the user to edit the selected pioneer
    void on_pushButton_computers_edit_clicked();
        // Opens up a new window that allows the user to edit the selected computer

private:
    std::string getCurrentOrderByPioneers();
        // Returns SQL column name to order pioneers by based on what user has picked in dropdown list
    std::string getCurrentDirectionPioneers();
        // Returns "ASC" or "DESC" based on what user has picked in dropdown list for pioneers
    std::string getCurrentGenderPioneers();
        // Returns "male" or "female" based on what user has picked in dropdown list for pioneers
    std::string getCurrentVitalStatusPioneers();
        // Returns "IS NULL" or "IS NOT NULL" based on what the user has picked in dropdown list
    std::string getCurrentSearchByPioneers();
        // Returns SQL column name to search pioneers by based on what user has picked in dropdown list

    std::string getCurrentOrderByComputers();
        // Returns SQL column name to order computers by based on what user has picked in dropdown list
    std::string getCurrentDirectionComputers();
        // Returns "ASC" or "DESC" based on what user has picked in dropdown list for computers
    std::string getCurrentTypeComputers();
        // Returns "mechanical", "electrical", "transistor" or "other" based on what user has picked in dropdown list for computers
    std::string getCurrentBuiltComputers();
        // Returns "true" or "false" based on what the user has picked in dropdown list
    std::string getCurrentSearchByComputers();
        // Returns SQL column name to search computers by based on what user has picked in dropdown list

    void displayAllPioneers();
        // Displays every single pioneer in SQL database
    void displayAllComputers();
        // Displays every single comptuer in SQL database
    void displayPioneers(std::vector<Pioneer> pioneers);
        // Displays parameter vector in a table with Name and Birth Year
    void displayComputers(std::vector<Computer> computers);
        // Displays parameter vector in a table with Name and Build Year

    Ui::MainWindow *ui;                                     // Pointer to MainWindow object
    PioneerService pioneerService;                          // PioneerService object
    ComputerService computerService;                        // ComputerService object
    std::vector<Pioneer> currentlyDisplayedPioneers;        // Vector that holds onto every pioneer that is currently being displayed on screen
    std::vector<Computer> currentlyDisplayedComputers;      // Vector that holds onto every computer that is currently being displayed on screen
    Pioneer currentlySelectedPio;
    Computer currentlySelectedComp;
};

#endif // MAINWINDOW_H
