#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "services/pioneerservice.h"
#include "services/computerservice.h"
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

private:
    void displayAllPioneers();
    void displayAllComputers();
    void displayPioneers(std::vector<Pioneer> pioneers);
    void displayComputers(std::vector<Computer> computers);

    Ui::MainWindow *ui;
    PioneerService pioneerService;
    ComputerService computerService;
};

#endif // MAINWINDOW_H
