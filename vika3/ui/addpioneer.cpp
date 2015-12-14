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
    // Empty all lines
    emptyLines();

    // Display list of all computers
    // vector<Computer> allComp = returnAllComputers();

    // Fill variables with values in input lines
    string name = ui->input_name->text().toStdString();
    string sex = ui->input_sex->text().toStdString();
    string birthyear = ui->input_bYear->text().toStdString();
    string deathyear = ui->input_dYear->text().toStdString();
    string description = ui->input_description->toPlainText().toStdString();

    if(deathyear.empty()){
        deathyear = "0";
    }

    bool error = errorCheck(name, sex, birthyear, deathyear, description);
    if(error == true){
        return;
    }

    int byear = atoi(birthyear.c_str());
    int dyear = atoi(deathyear.c_str());
    Pioneer pio(name, sex, byear, dyear, description);

    pioService.addPioneers(pio, 1);

    this->done(1);
}

void AddPioneer::emptyLines(){
    ui->label_name_error->setText("");
    ui->label_sex_error->setText("");
    ui->label_byear_error->setText("");
    ui->label_description_error->setText("");
}

bool AddPioneer::errorCheck(string name, string sex, string birthyear, string deathyear, string description){
    bool error = false;

    if(name.empty()){
        ui->label_name_error->setText("<span style ='color: #ff0000'>Input name</span>");
        error = true;
    }
    if(sex != "male" && sex != "Male" && sex != "female" && sex != "Female"){
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

void AddPioneer::displayUnrelatedComputers(vector<Computer> unrelatedComputers){
    ui->list_unrelated_computers->clear();

    for(unsigned int i = 0; i < unrelatedComputers.size(); i++){
        Computer currentComputer = unrelatedComputers[i];

        ui->list_unrelated_computers->addItem(QString::fromStdString(currentComputer.getComputerName()));
    }
    unrelatedComputersList = unrelatedComputers;
}

void AddPioneer::displayRelatedComputers(vector<Computer> relatedComputers){
    ui->list_related_computers->clear();

    for(unsigned int i = 0; i < relatedComputers.size(); i++){
        Computer currentComputer = relatedComputers[i];

        ui->list_related_computers->addItem(QString::fromStdString(currentComputer.getComputerName()));
    }
    relatedComputersList = relatedComputers;
}

void AddPioneer::on_list_unrelated_computers_clicked(){
    ui->button_add_relation->setEnabled(true);
}

void AddPioneer::on_list_related_computers_clicked(const QModelIndex &index){
    ui->button_remove_relation->setEnabled(true);
}

void AddPioneer::on_button_add_relation_clicked(){
    int currentlySelectedComputerIndex = ui->list_unrelated_computers->currentIndex().row();

    Computer selectedComputer = unrelatedComputersList[currentlySelectedComputerIndex];
    relatedComputersList.push_back(selectedComputer);
    unrelatedComputersList.erase(unrelatedComputersList.begin() + currentlySelectedComputerIndex);
    displayUnrelatedComputers(unrelatedComputersList);
    displayRelatedComputers(relatedComputersList);

    ui->button_add_relation->setEnabled(false);
}

void AddPioneer::on_button_remove_relation_clicked(){
    int currentlySelectedComputerIndex = ui->list_related_computers->currentIndex().row();

    Computer selectedComputer = relatedComputersList[currentlySelectedComputerIndex];
    unrelatedComputersList.push_back(selectedComputer);
    relatedComputersList.erase(relatedComputersList.begin() + currentlySelectedComputerIndex);
    displayRelatedComputers(relatedComputersList);
    displayUnrelatedComputers(unrelatedComputersList);

    ui->button_remove_relation->setEnabled(false);
}
