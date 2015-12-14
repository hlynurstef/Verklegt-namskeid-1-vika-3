#include "moreinfocomputer.h"
#include "ui_moreinfocomputer.h"
#include "utilities/constants.h"
#include "data_types/computer.h"

using namespace std;

MoreInfoComputer::MoreInfoComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfoComputer)
{
    ui->setupUi(this);

}

MoreInfoComputer::~MoreInfoComputer()
{
    delete ui;
}

void MoreInfoComputer::setComputer(Computer computer){

    // Printing info
    ui->label_name->setText(QString::fromStdString(computer.getComputerName()));
    ui->label_type->setText(QString::fromStdString(computer.getComputerType()));
    ui->label_built->setText(QString::fromStdString(computer.getWasItBuilt()));
    ui->label_buildYear->setText(QString::number(computer.getBuildYear()));
    ui->label_description->setText(QString::fromStdString(computer.getComputerDescription()));
}


