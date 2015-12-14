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
    displayInfo();

}

MoreInfoComputer::~MoreInfoComputer()
{
    delete ui;
}

void MoreInfoComputer::displayInfo(){

   /* // Getting info from selected computer
    computer = mainwindow.returnCurrentlySelectedComputer();

    // Printing info
    ui->label_name->setText(QString::fromStdString(computer.getComputerName()));
*/
}


