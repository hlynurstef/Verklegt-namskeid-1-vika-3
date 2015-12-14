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

    ui->lineEdit_name->setText(QString::fromStdString(computer.getComputerName()));
    ui->lineEdit_type->setText(QString::fromStdString(computer.getComputerType()));
    ui->lineEdit_wasbuilt->setText(QString::fromStdString(computer.getWasItBuilt()));
    ui->lineEdit_buildyear->setText(QString::number(computer.getBuildYear()));
    ui->lineEdit_description->setText(QString::fromStdString(computer.getComputerDescription()));
}

void editComputer::on_pushButton_editcomputer_clicked()
{ 
    this->done(1);
}


