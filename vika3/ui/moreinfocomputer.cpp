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

    // ------------------- Printing info -------------------

    ui->label_name->setText(QString::fromStdString(computer.getComputerName()));
    ui->label_type->setText(QString::fromStdString(computer.getComputerType()));

    // Check if the computer was built or not and return yes/no
    if(computer.getWasItBuilt() == "true"){
        ui->label_built->setText(QString::fromStdString("yes"));
    }
    else if(computer.getWasItBuilt() == "false"){
        ui->label_built->setText(QString::fromStdString("no"));
    }
    ui->label_buildYear->setText(QString::number(computer.getBuildYear()));
    ui->label_description->setText(QString::fromStdString(computer.getComputerDescription()));
}



void MoreInfoComputer::on_pushButton_clicked()
{
    this->close();
}
