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

void editComputer::setComputer(Computer comp){

    // Printing info
    ui->lineEdit_name->setText(QString::fromStdString(comp.getComputerName()));
    ui->lineEdit_type->setText(QString::fromStdString(comp.getComputerType()));
    ui->lineEdit_wasbuilt->setText(QString::fromStdString(comp.getWasItBuilt()));
    ui->lineEdit_buildyear->setText(QString::number(comp.getBuildYear()));
    ui->lineEdit_description->setText(QString::fromStdString(comp.getComputerDescription()));
}




