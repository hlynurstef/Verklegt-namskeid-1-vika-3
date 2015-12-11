#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Pioneer dropdown lists:
    ui->dropdown_pioneers_order_by->addItem("Name");
    ui->dropdown_pioneers_order_by->addItem("Birth Year");
    ui->dropdown_pioneers_order_direction->addItem("Ascending");
    ui->dropdown_pioneers_order_direction->addItem("Descending");
    ui->dropdown_pioneers_filter_gender->addItem("No filter");
    ui->dropdown_pioneers_filter_gender->addItem("Female");
    ui->dropdown_pioneers_filter_gender->addItem("Male");
    ui->dropdown_pioneers_filter_vital_status->addItem("No filter");
    ui->dropdown_pioneers_filter_vital_status->addItem("Alive");
    ui->dropdown_pioneers_filter_vital_status->addItem("Deceased");

    // Computer dropdown lists:
    ui->dropdown_computers_order_by->addItem("Name");
    ui->dropdown_computers_order_by->addItem("Build Year");
    ui->dropdown_computers_order_direction->addItem("Ascending");
    ui->dropdown_computers_order_direction->addItem("Descending");
    ui->dropdown_computers_filter_type->addItem("No filter");
    ui->dropdown_computers_filter_type->addItem("Mechanical");
    ui->dropdown_computers_filter_type->addItem("Electrical");
    ui->dropdown_computers_filter_type->addItem("Transistor");
    ui->dropdown_computers_filter_type->addItem("Other");
    ui->dropdown_computers_filter_built->addItem("No filter");
    ui->dropdown_computers_filter_built->addItem("Was built");
    ui->dropdown_computers_filter_built->addItem("Was not built");

    displayAllPioneers();
    displayAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllPioneers()
{
    vector<Pioneer> pioneers = pioneerService.getList();
    displayPioneers(pioneers);
}

void MainWindow::displayAllComputers()
{
    vector<Computer> computers = computerService.getList();
    displayComputers(computers);
}

void MainWindow::displayPioneers(std::vector<Pioneer> pioneers)
{
    ui->list_pioneers->clear();

    for(unsigned int i = 0; i < pioneers.size(); i++){
        Pioneer currentPioneer = pioneers[i];

        ui->list_pioneers->addItem(QString::fromStdString(currentPioneer.getName()));
    }

    currentlyDisplayedPioneers = pioneers;
}

void MainWindow::displayComputers(std::vector<Computer> computers)
{
    ui->list_computers->clear();

    for(unsigned int i = 0; i < computers.size(); i++){
        Computer currentComputer = computers[i];

        ui->list_computers->addItem(QString::fromStdString(currentComputer.getComputerName()));
    }
}

void MainWindow::on_input_search_pioneers_textChanged()
{
    string userInput = ui->input_search_pioneers->text().toStdString();

    // TO DO: change search function to take in name of column to search for instead of integer
    vector<Pioneer> pioneers = pioneerService.search(userInput, 1);
    displayPioneers(pioneers);
}

void MainWindow::on_input_search_computers_textChanged()
{
    string userInput = ui->input_search_computers->text().toStdString();

    // TO DO: change search function to take in name of column to search for instead of integer
    vector<Computer> computers = computerService.search(userInput, 1);
    displayComputers(computers);
}

void MainWindow::on_dropdown_pioneers_order_by_currentIndexChanged(int index)
{

}

void MainWindow::on_dropdown_computers_order_by_currentIndexChanged(int index)
{

}

void MainWindow::on_dropdown_pioneers_order_direction_currentIndexChanged(int index)
{

}

void MainWindow::on_dropdown_computers_order_direction_currentIndexChanged(int index)
{

}

string MainWindow::getCurrentOrderByPioneers()
{
    string orderBy = ui->dropdown_pioneers_order_by->currentText().toStdString();

    if(orderBy == "Name"){
        return constants::NAME;
    }
    else if(orderBy == "Birth Year"){
        return constants::BIRTH_YEAR;
    }
    else{
        return constants::NAME;
    }

}

string MainWindow::getCurrentOrderByComputers()
{
    string orderBy = ui->dropdown_computers_order_by->currentText().toStdString();

    if(orderBy == "Name"){
        return constants::COMP_NAME;
    }
    else if(orderBy == "Build Year"){
        return constants::BUILD_YEAR;
    }
    else{
        return constants::COMP_NAME;
    }
}

void MainWindow::on_dropdown_pioneers_filter_gender_currentIndexChanged(int index)
{

}

void MainWindow::on_dropdown_pioneers_filter_vital_status_currentIndexChanged(int index)
{

}

void MainWindow::on_dropdown_computers_filter_type_currentIndexChanged(int index)
{

}

void MainWindow::on_dropdown_computers_filter_built_currentIndexChanged(int index)
{

}

void MainWindow::on_list_pioneers_clicked(const QModelIndex &index)
{
    ui->button_remove_pioneer->setEnabled(true);
}

void MainWindow::on_button_remove_pioneer_clicked()
{
    int currentlySelectedPioneerIndex = ui->list_pioneers->currentIndex().row();

    Pioneer currentlySelectedPioneer = currentlyDisplayedPioneers[currentlySelectedPioneerIndex];

    bool success = pioneerService.removePioneer(currentlySelectedPioneer);

    if(success){
        ui->input_search_pioneers->setText("");
        displayAllPioneers();

        ui->button_remove_pioneer->setEnabled(false);

    }
    else{
        //some error
    }
}
