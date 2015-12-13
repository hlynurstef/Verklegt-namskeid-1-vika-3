#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "services/pioneerservice.h"
#include "services/computerservice.h"
#include "addpioneer.h"
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

private slots:
    void on_input_search_pioneers_textChanged();
    void on_input_search_computers_textChanged();
    void on_dropdown_pioneers_order_by_currentIndexChanged(int index);
    void on_dropdown_computers_order_by_currentIndexChanged(int index);
    void on_dropdown_pioneers_order_direction_currentIndexChanged(int index);
    void on_dropdown_computers_order_direction_currentIndexChanged(int index);
    void on_dropdown_pioneers_filter_gender_currentIndexChanged(int index);
    void on_dropdown_pioneers_filter_vital_status_currentIndexChanged(int index);
    void on_dropdown_computers_filter_type_currentIndexChanged(int index);
    void on_dropdown_computers_filter_built_currentIndexChanged(int index);
    void on_button_pioneer_remove_clicked();
    void on_button_computer_remove_clicked();
    void on_table_pioneers_clicked(const QModelIndex &index);

    void on_table_computers_clicked(const QModelIndex &index);

    void on_pushButton_pioneers_add_new_entry_clicked();

    void on_pushButton_computers_add_new_entry_clicked();

private:
    std::string getCurrentOrderByPioneers();
    std::string getCurrentDirectionPioneers();
    std::string getCurrentGenderPioneers();
    std::string getCurrentVitalStatusPioneers();
    std::string getCurrentSearchByPioneers();

    std::string getCurrentOrderByComputers();
    std::string getCurrentDirectionComputers();
    std::string getCurrentTypeComputers();
    std::string getCurrentBuiltComputers();
    std::string getCurrentSearchByComputers();

    void displayAllPioneers();
    void displayAllComputers();
    void displayPioneers(std::vector<Pioneer> pioneers);
    void displayComputers(std::vector<Computer> computers);
    Ui::MainWindow *ui;
    PioneerService pioneerService;
    ComputerService computerService;
    std::vector<Pioneer> currentlyDisplayedPioneers;
    std::vector<Computer> currentlyDisplayedComputers;
};

#endif // MAINWINDOW_H
