#include "addcomputer.h"
#include "ui_addcomputer.h"
#include <QMessageBox>
#include <QStatusBar>

addComputer::addComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputer)
{
    ui->setupUi(this);
}

addComputer::~addComputer()
{
    delete ui;
}

void addComputer::on_button_add_computer_clicked()
{
    // Empty error messages
    emptyLines();

    // Fill variables with values in input lines
    string name = ui->input_computer_name->text().toStdString();
    string type = ui->input_computer_type->text().toStdString();
    string wasItBuilt = ui->input_computer_was_it_built->text().toStdString();
    string buildYear= ui->input_computer_build_year->text().toStdString();
    string description = ui->input_computer_description->toPlainText().toStdString();

    if(buildYear.empty()){
        buildYear= "0";
    }

    bool error = errorCheck(name, type, wasItBuilt, buildYear, description);
    if(error){
        return;
    }

    int bYear = atoi(buildYear.c_str());
    Computer comp(name, bYear, type, wasItBuilt, description);

    int answer = QMessageBox::question(this, "Warning", "Are you sure you want to add to list?");

    if(answer == QMessageBox::No){
        return;
    }
    else{
        computerService.addComputer(comp);
        int idOfAddedComputer = computerService.getHighestId();

        for(unsigned int i = 0; i < relatedPioneersList.size(); i++){
            Pioneer currentPioneer = relatedPioneersList[i];
            relationService.addRelations(currentPioneer.getId(), idOfAddedComputer);
        }
        this->done(1);
    }
}

void addComputer::emptyLines(){
    ui->label_computer_name_error->setText("");
    ui->label_computer_type_error->setText("");
    ui->label_computer_build_error->setText("");
    ui->label_computer_description_error->setText("");
}

bool addComputer::errorCheck(string name, string type, string wasItBuilt, string buildYear, string description){
    bool error = false;

    if(name.empty()){
        ui->label_computer_name_error->setText("<span style ='color: #ff0000'>Input name</span>");
        error = true;
    }
    if(type != "mechanical" && type != "Mechanical" && type != "electronic" && type != "Electronic" && type != "transistor" && type != "Transistor"){
        ui->label_computer_type_error->setText("<span style ='color: #ff0000'>Wrong input</span>");
        // ui->statusBar->showMessage("Correct type inputs are: Mechanical, Electronic or Transistor", 2000);
        error = true;
    }
    if(type.empty()){
        ui->label_computer_type_error->setText("<span style ='color: #ff0000'>Input type</span>");
        error = true;
    }
    if(wasItBuilt.empty()){
        ui->label_computer_build_error->setText("<span style ='color: #ff0000'>Input y/n</span>");
        error = true;
    }
    if(description.empty()){
        ui->label_computer_description_error->setText("<span style ='color: #ff0000'>Input description</span>");
    }

    if(error == true){
        return true;
    }
    return false;
}

bool addComputer::is_number(string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)){
        ++it;
    }

    return !s.empty() && it == s.end();
}

void addComputer::displayUnrelatedPioneers(vector<Pioneer> unrelatedPioneers){
    ui->list_unrelated_pioneers->clear();

    for(unsigned int i = 0; i < unrelatedPioneers.size(); i++){
        Pioneer currentPioneer = unrelatedPioneers[i];

        ui->list_unrelated_pioneers->addItem(QString::fromStdString(currentPioneer.getName()));
    }
    unrelatedPioneersList = unrelatedPioneers;
}

void addComputer::displayRelatedPioneers(vector<Pioneer> relatedPioneers){
    ui->list_related_pioneers->clear();

    for(unsigned int i = 0; i < relatedPioneers.size(); i++){
        Pioneer currentPioneer = relatedPioneers[i];

        ui->list_related_pioneers->addItem(QString::fromStdString(currentPioneer.getName()));
    }

    relatedPioneersList = relatedPioneers;
}

void addComputer::on_list_unrelated_pioneers_clicked(const QModelIndex &/* unused */){
    ui->button_add_relation->setEnabled(true);
}

void addComputer::on_list_related_pioneers_clicked(const QModelIndex &/* unused */){
    ui->button_remove_relation->setEnabled(true);
}

void addComputer::on_button_add_relation_clicked(){
    int currentlySelectedPioneerIndex = ui->list_unrelated_pioneers->currentIndex().row();

    Pioneer selectedPioneer = unrelatedPioneersList[currentlySelectedPioneerIndex];
    relatedPioneersList.push_back(selectedPioneer);
    unrelatedPioneersList.erase(unrelatedPioneersList.begin() + currentlySelectedPioneerIndex);
    displayUnrelatedPioneers(unrelatedPioneersList);
    displayRelatedPioneers(relatedPioneersList);

    ui->button_add_relation->setEnabled(false);
}

void addComputer::on_button_remove_relation_clicked(){
    int currentlySelectedPioneerIndex = ui->list_related_pioneers->currentIndex().row();

    Pioneer selectedPioneer = relatedPioneersList[currentlySelectedPioneerIndex];
    unrelatedPioneersList.push_back(selectedPioneer);
    relatedPioneersList.erase(relatedPioneersList.begin() + currentlySelectedPioneerIndex);
    displayRelatedPioneers(relatedPioneersList);
    displayUnrelatedPioneers(unrelatedPioneersList);

    ui->button_remove_relation->setEnabled(false);
}

void addComputer::on_button_computer_cancel_clicked(){
    this->done(0);
}
