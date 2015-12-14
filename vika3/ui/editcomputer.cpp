#include "editcomputer.h"
#include "ui_editcomputer.h"
#include "utilities/constants.h"
#include "data_types/computer.h"


editComputer::editComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer)
{
    ui->setupUi(this);

}

editComputer::~editComputer()
{
    delete ui;
}

void editComputer::displayComputer(){
    //Getting the info from selected pioneer
   // mainwindow temp;
    //computer = temp.returnCurrentlySelectedComputer();

    //Printing out info
    //ui->->clearContents();
    //ui->show_single_computer->setLineWidth(5);

    /*QString name = QString::fromStdString(computer.getComputerName());
    QString buildYear = QString::fromStdString(computer.getBuildYear());
    QString wasItBuilt = QString::number(computer.getWasItBuilt());
    QString type = QString::number(computer.getComputerType());
    QString description = QString::fromStdString(computer.getComputerDescription());

    ui->lineEdit_name->setItem(0, 0, new QTableWidgetItem(name));
    ui->lineEdit_buildyear->setItem(1, 0, new QTableWidgetItem(buildYear));
    ui->lineEdit_wasbuilt->setItem(2, 0, new QTableWidgetItem(wasItBuilt));
    ui->lineEdit_type->setItem(3, 0, new QTableWidgetItem(type));
    ui->lineEdit_description->setItem(4, 0, new QTableWidgetItem(description));*/

}

void editComputer::on_pushButton_editcomputer_clicked()
{ 
    this->done(1);
}
