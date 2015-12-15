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
    ui->edit_name->setText(QString::fromStdString(comp.getComputerName()));
    ui->edit_type->setText(QString::fromStdString(comp.getComputerType()));
    ui->edit_wasbuilt->setText(QString::fromStdString(comp.getWasItBuilt()));
    ui->edit_buildyear->setText(QString::number(comp.getBuildYear()));
    ui->edit_description->setText(QString::fromStdString(comp.getComputerDescription()));
}




