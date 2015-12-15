#include "editpioneer.h"
#include "ui_editpioneer.h"

editPioneer::editPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPioneer)
{
    ui->setupUi(this);
}

editPioneer::~editPioneer()
{
    delete ui;
}

void editPioneer::setPioneer(Pioneer pio){

    string birthyear = std::to_string(pio.getByear());
    string deathyear = std::to_string(pio.getDyear());

    pioID = pio.getId();

    ui->edit_name->setText(QString::fromStdString(pio.getName()));
    ui->edit_sex->setText(QString::fromStdString(pio.getSex()));
    ui->edit_birth_year->setText(QString::fromStdString(birthyear));
    ui->edit_death_year->setText(QString::fromStdString(deathyear));
    ui->edit_description->setText(QString::fromStdString(pio.getDescription()));
}


void editPioneer::on_button_edit_pioneer_clicked()
{
    string name = ui->edit_name->text().toStdString();
    string sex = ui->edit_sex->text().toStdString();
    string birthyear = ui->edit_birth_year->text().toStdString();
    string deathyear = ui->edit_death_year->text().toStdString();
    string description = ui->edit_description->toPlainText().toStdString();

    if(deathyear.empty()){
        deathyear = "0";
    }

    /*
    bool error = errorCheck(name, sex, birthyear, deathyear, description);
    if(error == true){
        return;
    }
    */

    int byear = atoi(birthyear.c_str());
    int dyear = atoi(deathyear.c_str());

    Pioneer pio(pioID, name, sex, byear, dyear, description);

    pioService.editPioneer(pio);

    this->done(1);

}
/*
bool editPioneer::errorCheck(string name, string sex, string birthyear, string deathyear, string description){
    bool error = false;

    if(name.empty()){
        ui->label_pioneer_name_error->setText("<span style ='color: #ff0000'>Input name</span>");
        error = true;
    }
    if(sex != "male" && sex != "Male" && sex != "female" && sex != "Female"){
        ui->label_pioneer_sex_error->setText("<span style ='color: #ff0000'>Wrong input</span>");
        error = true;
    }
    if(sex.empty()){
        ui->label_pioneer_sex_error->setText("<span style ='color: #ff0000'>Input sex</span>");
        error = true;
    }

    if(birthyear.empty()){
        ui->label_pioneer_byear_error->setText("<span style ='color: #ff0000'>Input birth year</span>");
        error = true;
    }
    if(description.empty()){
        ui->label_pioneer_description_error->setText("<span style ='color: #ff0000'>Input description</span>");
    }

    if(error == true){
        return true;
    }
    return false;
}
*/

