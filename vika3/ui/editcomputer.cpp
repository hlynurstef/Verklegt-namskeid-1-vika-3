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





void editComputer::on_pushButton_editcomputer_clicked()
{
    string name = ui->edit_name->text().toStdString();
    string built = ui->edit_wasbuilt->text().toStdString();
    string type = ui->edit_type->text().toStdString();
    string buildYear = ui->edit_buildyear->text().toStdString();
    string description = ui->edit_description->toPlainText().toStdString();

    int bYear = atoi(buildYear.c_str());

    Computer comp(compID, name, bYear, type, built, description);

    compService.editComputer(comp);

    this->done(1);

}
