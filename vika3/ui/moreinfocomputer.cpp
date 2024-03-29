#include "moreinfocomputer.h"
#include "ui_moreinfocomputer.h"
#include "utilities/constants.h"
#include "data_types/computer.h"
#include <QDebug>
#include <QPixmap>

using namespace std;

MoreInfoComputer::MoreInfoComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfoComputer){
    ui->setupUi(this);

}

MoreInfoComputer::~MoreInfoComputer(){
    delete ui;
}

void MoreInfoComputer::setComputer(Computer computer){

    // ------------------- Printing info -------------------

    ui->label_name->setText(QString::fromStdString(computer.getComputerName()));
    if(computer.getComputerType() == constants::MECHANICAL){
        ui->label_type->setText(QString::fromStdString("Mechanical"));
    }
    else if(computer.getComputerType() == constants::ELECTRONIC){
        ui->label_type->setText(QString::fromStdString("Electronic"));
    }
    else if(computer.getComputerType() == constants::TRANSISTOR){
        ui->label_type->setText(QString::fromStdString("Transistor"));
    }
    else if(computer.getComputerType() == "other"){
        ui->label_type->setText(QString::fromStdString("Other"));
    }


    // Check if the computer was built or not and return yes/no
    if(computer.getWasItBuilt() == "true"){
        ui->label_built->setText(QString::fromStdString("Yes"));
    }
    else if(computer.getWasItBuilt() == "false"){
        ui->label_built->setText(QString::fromStdString("No"));
    }
    if(computer.getBuildYear() == 0){
        ui->label_buildYear->setText("was not built!");
    }
    else{
    ui->label_buildYear->setText(QString::number(computer.getBuildYear()));
    }
    ui->label_description->setText(QString::fromStdString(computer.getComputerDescription()));

    getRelationList(computer);

    if(!(computer.getImageByteArray().isEmpty())){
        QPixmap pixmap = QPixmap();
        pixmap.loadFromData(computer.getImageByteArray());
        ui->label_image->setPixmap(pixmap);
        ui->label_image->setScaledContents(true);
    }
}

void MoreInfoComputer::getRelationList(Computer computer){

    //---------------- Printing & getting relation info from database ----------------

    string relationList;

    relation = (relationService.relationSearch(computer.getComputerName(), constants::REL_COMP_NAME));

    for(unsigned int i=0; i < relation.size(); i++){
        relationList += relation[i].getPioName();
        if((i+1) < relation.size()){
            relationList += ", ";
        }
    }
    if(relation.size() == 0){
        ui -> label_relation -> setText(QString::fromStdString("Unknown relations"));
    }
    else
        ui -> label_relation -> setText(QString::fromStdString(relationList));
}

void MoreInfoComputer::on_pushButton_clicked(){
    this->close();
}
