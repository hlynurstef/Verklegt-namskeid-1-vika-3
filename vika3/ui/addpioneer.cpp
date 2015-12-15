#include "addpioneer.h"
#include "ui_addpioneer.h"
#include "utilities/constants.h"

#include <QFileDialog>
#include <QMessageBox>
#include <algorithm>

AddPioneer::AddPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPioneer)
{
    ui->setupUi(this);

    // dropdown list for sex
    ui->dropdown_pioneer_sex->addItem("");
    ui->dropdown_pioneer_sex->addItem("Male");
    ui->dropdown_pioneer_sex->addItem("Female");
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
    //vector<Computer> allComp = returnAllComputers();

    // Fill variables with values in input lines
    string name = ui->input_pioneer_name->text().toStdString();
    string sex = getCurrentSex();
    string birthyear = ui->input_pioneer_bYear->text().toStdString();
    string deathyear = ui->input_pioneer_dYear->text().toStdString();
    string description = ui->input_pioneer_description->toPlainText().toStdString();

    if(deathyear.empty()){
        deathyear = "0";
    }

    bool error = errorCheck(name, sex, birthyear, deathyear, description);
    if(error){
        return;
    }

    int byear = atoi(birthyear.c_str());
    int dyear = atoi(deathyear.c_str());
    Pioneer pio(name, sex, byear, dyear, description);

    int answer = QMessageBox::question(this, "Add Pioneer", "Are you sure you want to add " + QString::fromStdString(pio.getName()) + " to the list?");

    if(answer == QMessageBox::No){
        return;
    }
    else{
        pioService.addPioneer(pio);
        int idOfAddedPioneer = pioService.getHighestId();

        for(unsigned int i = 0; i < relatedComputersList.size(); i++){
            Computer currentComputer = relatedComputersList[i];
            relationService.addRelations(idOfAddedPioneer, currentComputer.getId());
        }

        this->done(1);
    }
}

void AddPioneer::emptyLines(){
    ui->label_pioneer_name_error->setText("");
    ui->label_pioneer_sex_error->setText("");
    ui->label_pioneer_byear_error->setText("");
    ui->label_pioneer_description_error->setText("");
}

bool AddPioneer::errorCheck(string name, string sex, string birthyear, string deathyear, string description){
    bool error = false;

    transform(sex.begin(), sex.end(), sex.begin(), ::tolower);

    if(name.empty()){
        ui->label_pioneer_name_error->setText("<span style ='color: #ff0000'>Input Name!</span>");
        error = true;
    }
    if(sex.empty()){
        ui->label_pioneer_sex_error->setText("<span style ='color: #ff0000'>Choose Sex!</span>");
        error = true;
    }
    if(birthyear.empty()){
        ui->label_pioneer_byear_error->setText("<span style ='color: #ff0000'>Input Birth Year!</span>");
        error = true;
    }
    if(!is_number(birthyear)){
        ui->label_pioneer_byear_error->setText("<span style ='color: #ff0000'>Input a Number!</span>");
        error = true;
    }
    if(description.empty()){
        ui->label_pioneer_description_error->setText("<span style ='color: #ff0000'>Input Description</span>");
        error = true;
    }

    int byear = atoi(birthyear.c_str());
    int dyear = atoi(deathyear.c_str());

    if(!is_number(deathyear)){
        ui->label_pioneer_death_year_error->setText("<span style ='color: #ff0000'>Input a Number!</span>");
        error = true;
    }
    else if((byear == dyear || byear > dyear || dyear > constants::CURRENT_YEAR) && dyear != 0){
        ui->label_pioneer_death_year_error->setText("<span style ='color: #ff0000'>Incorrect Input!</span>");
        error = true;
    }

    if(byear > constants::CURRENT_YEAR){
        ui->label_pioneer_byear_error->setText("<span style ='color: #ff0000'>People from the future are not allowed!</span>");
        error = true;
    }

    if(error == true){
        return true;
    }
    return false;
}

bool AddPioneer::is_number(string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)){
        ++it;
    }

    return !s.empty() && it == s.end();
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

void AddPioneer::on_list_unrelated_computers_clicked(const QModelIndex &/* unused */){
    ui->button_pioneer_add_relation->setEnabled(true);
}

void AddPioneer::on_list_related_computers_clicked(const QModelIndex &/* unused */){
    ui->button_pioneer_remove_relation->setEnabled(true);
}

void AddPioneer::on_button_pioneer_add_relation_clicked(){
    int currentlySelectedComputerIndex = ui->list_unrelated_computers->currentIndex().row();

    Computer selectedComputer = unrelatedComputersList[currentlySelectedComputerIndex];
    relatedComputersList.push_back(selectedComputer);
    unrelatedComputersList.erase(unrelatedComputersList.begin() + currentlySelectedComputerIndex);
    displayUnrelatedComputers(unrelatedComputersList);
    displayRelatedComputers(relatedComputersList);

    ui->button_pioneer_add_relation->setEnabled(false);
}

void AddPioneer::on_button_pioneer_remove_relation_clicked(){
    int currentlySelectedComputerIndex = ui->list_related_computers->currentIndex().row();

    Computer selectedComputer = relatedComputersList[currentlySelectedComputerIndex];
    unrelatedComputersList.push_back(selectedComputer);
    relatedComputersList.erase(relatedComputersList.begin() + currentlySelectedComputerIndex);
    displayRelatedComputers(relatedComputersList);
    displayUnrelatedComputers(unrelatedComputersList);

    ui->button_pioneer_remove_relation->setEnabled(false);
}

void AddPioneer::on_pushButton_browse_image_clicked()
{
    string filePath = QFileDialog::getOpenFileName(
                    this,
                    "Search for images",
                    "",
                    "Image files (*.png *.jpg)"
                ).toStdString();

    if (filePath.length()) // File selected
    {
        QPixmap pixmap(QString::fromStdString(filePath));

        ui->input_image->setText(QString::fromStdString(filePath));

    }
}

void AddPioneer::on_button_add_pioneer_cancel_clicked()
{
    this->done(0);
}

string AddPioneer::getCurrentSex()
{
    string sex = ui->dropdown_pioneer_sex->currentText().toStdString();

    if(sex == ""){
        return "";
    }
    else if(sex == "Male"){
        return constants::MALE;
    }
    else if(sex == "Female"){
        return constants::FEMALE;
    }
    else{
        return "";
    }
}
