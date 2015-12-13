#include "addpioneer.h"
#include "ui_addpioneer.h"

AddPioneer::AddPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPioneer)
{
    ui->setupUi(this);
}

AddPioneer::~AddPioneer()
{
    delete ui;
}


void AddPioneer::on_button_add_pioneer_clicked()
{
    // Empty error messages
    ui->label_name_error->setText("");
    ui->label_sex_error->setText("");
    ui->label_byear_error->setText("");
    ui->label_description_error->setText("");

    // Fill variables with values in input lines
    string name = ui->input_name->text().toStdString();
    string sex = ui->input_sex->text().toStdString();
    string birthyear = ui->input_bYear->text().toStdString();
    string deathyear = ui->input_dYear->text().toStdString();
    string description = ui->input_description->text().toStdString();

    if(deathyear.empty()){
        deathyear = "0";
    }

    bool error = errorCheck(name, sex, birthyear, deathyear, description);
    if(error == true){
        return;
    }

    int byear = stoi(birthyear.c_str());
    int dyear = stoi(deathyear.c_str());
    Pioneer pio(name, sex, byear, dyear, description);

    pioService.addPioneers(pio, 1);

    this->done(1);
}
bool AddPioneer::errorCheck(string name, string sex, string birthyear, string deathyear, string description){
    bool error = false;

    if(name.empty()){
        ui->label_name_error->setText("<span style ='color: #ff0000'>Input name</span>");
        error = true;
    }
    if(sex != "male" || sex != "Male" || sex != "female" || sex != "Female"){
        ui->label_sex_error->setText("<span style ='color: #ff0000'>Wrong input</span>");
        error = true;
    }
    if(sex.empty()){
        ui->label_sex_error->setText("<span style ='color: #ff0000'>Input sex</span>");
        error = true;
    }

    if(birthyear.empty()){
        ui->label_byear_error->setText("<span style ='color: #ff0000'>Input birth year</span>");
        error = true;
    }
    if(description.empty()){
        ui->label_description_error->setText("<span style ='color: #ff0000'>Input description</span>");
    }

    if(error == true){
        return true;
    }
    return false;
}
