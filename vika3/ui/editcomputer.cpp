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

editComputer::~editComputer(){
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

    if(buildYear.empty()){
        buildYear = "0";
    }

    bool error = errorCheck(name, built, buildYear, type, description);
    if(error == true){
        return;
    }
    int bYear = atoi(buildYear.c_str());

    Computer comp(compID, name, bYear, type, built, description);

    compService.editComputer(comp);

    this->done(1);
}

bool editComputer::errorCheck(string name, string wasBuilt, string buildYear, string type, string description)
{
    bool error = false;

    if(name.empty()){
        ui->label_name_error->setText("<span style ='color: #ff0000'>Input computer name</span>");
        error = true;
    }

    if(type.empty()){
        ui->label_type_error->setText("<span style ='color: #ff0000'>Input type</span>");
        error = true;
    }
    if(description.empty()){
        ui->label_description_error->setText("<span style ='color: #ff0000'>Input description</span>");
    }

    if(wasBuilt.empty()){
        ui->label_wasbuilt_error->setText("<span style ='color: #ff0000'>was it built?</span>");
            error = true;
    }
    //if(buildYear.empty()){
       // buildYear == '0';
    //}

    if(error == true){
        return true;
    }
    return false;
}

void editComputer::on_button_cancel_clicked(){
    this->done(0);
}
