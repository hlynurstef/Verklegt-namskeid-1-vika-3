#include "editpioneer.h"
#include "ui_editpioneer.h"
#include "utilities/constants.h"
#include <QMessageBox>

editPioneer::editPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPioneer)
{
    ui->setupUi(this);

    // dropdown list for sex
    ui->edit_dropdown_sex->addItem("");
    ui->edit_dropdown_sex->addItem("Male");
    ui->edit_dropdown_sex->addItem("Female");
}

editPioneer::~editPioneer()
{
    delete ui;
}

void editPioneer::setPioneer(Pioneer pio){

//    string birthyear = std::to_string(pio.getByear());
//    string deathyear = std::to_string(pio.getDyear());
    string sex;

    pioID = pio.getId();

    if(pio.getSex() == constants::MALE){
        sex = "Male";
    }
    else{
        sex = "Female";
    }

    ui->edit_name->setText(QString::fromStdString(pio.getName()));
    ui->edit_dropdown_sex->setCurrentText(QString::fromStdString(sex));
    ui->edit_birth_year->setText(QString::number(pio.getByear()));
    if(pio.getDyear() == 0){
        ui->edit_death_year->setText(QString::fromStdString(""));
    }
    else{
        ui->edit_death_year->setText(QString::number(pio.getDyear()));
    }
    ui->edit_description->setText(QString::fromStdString(pio.getDescription())); 
    if(!pio.getImageByteArray().isEmpty()){
            ui->lineEdit_image->setText(QString::fromStdString("There is an image selected to " + pio.getName()));
    }

    vector<Relation> allRelations = relService.displayRelations();
    vector<Computer> allComputers = compService.getList();


    for(unsigned int i = 0; i < allRelations.size(); i++){
        Relation relInstance = allRelations[i];

        for(unsigned int j = 0; j < allComputers.size(); j++){
            Computer compInstance = allComputers[j];

            if(relInstance.getPioName() == pio.getName() && relInstance.getCompName() == compInstance.getComputerName()){
                relatedComputers.push_back(compInstance);
            }
        }
    }

    bool relatedComputer = false;
    for(unsigned int i = 0; i < allComputers.size(); i++){
        Computer unrelated = allComputers[i];
        relatedComputer = false;
        for(unsigned int j = 0; j < relatedComputers.size(); j++){
            Computer related = relatedComputers[j];
            if(related.getComputerName() != unrelated.getComputerName()){
                relatedComputer = false;
            }
            else{
                relatedComputer = true;
            }
        }
        if(relatedComputer == false){
            unrelatedComputers.push_back(unrelated);
        }
    }

    displayRelatedComputers();
    displayUnrelatedComputers();

    ui->button_add_relation->setEnabled(false);
    ui->button_remove_relation->setEnabled(false);

}


void editPioneer::on_button_edit_pioneer_clicked()
{
    string name = ui->edit_name->text().toStdString();
    string sex = getCurrentSex();
    string birthyear = ui->edit_birth_year->text().toStdString();
    string deathyear = ui->edit_death_year->text().toStdString();
    string description = ui->edit_description->toPlainText().toStdString();

    if(deathyear.empty()){
        deathyear = "0";
    }

    bool error = errorCheck(name, sex, birthyear, deathyear, description);
    if(error == true){
        return;
    }

    int byear = atoi(birthyear.c_str());
    int dyear = atoi(deathyear.c_str());
    Pioneer pio(pioID, name, sex, byear, dyear, description, image);

    int answer = QMessageBox::question(this, "Save Changes", "Are you sure you want to save changes?");

    if(answer == QMessageBox::No){
        return;
    }
    else{
        pioService.editPioneer(pio);

        this->done(1);
    }
}

bool editPioneer::errorCheck(string name, string sex, string birthyear, string deathyear, string description){
    bool error = false;

    if(name.empty()){
        ui->label_name_error->setText("<span style ='color: #ff0000'>Input Name!</span>");
        error = true;
    }
    if(sex.empty()){
        ui->label_sex_error->setText("<span style ='color: #ff0000'>Choose Sex!</span>");
        error = true;
    }
    if(birthyear.empty()){
        ui->label_birth_year_error->setText("<span style ='color: #ff0000'>Input Birth Year!</span>");
        error = true;
    }
    if(!is_number(birthyear)){
        ui->label_birth_year_error->setText("<span style ='color: #ff0000'>Input a Number!</span>");
        error = true;
    }
    if(description.empty()){
        ui->label_description_error->setText("<span style ='color: #ff0000'>Input description</span>");
    }

    int byear = atoi(birthyear.c_str());
    int dyear = atoi(deathyear.c_str());

    if(!is_number(deathyear)){
        ui->label_death_year_error->setText("<span style ='color: #ff0000'>Input a Number!</span>");
        error = true;
    }
    else if((byear == dyear || byear > dyear) && dyear != 0){
        ui->label_death_year_error->setText("<span style ='color: #ff0000'>Incorrect Input!</span>");
        error = true;
    }
    else if(dyear > constants::CURRENT_YEAR){
        ui->label_death_year_error->setText("<span style ='color: #ff0000'>Are you trying to predict the future?</span>");
        error = true;
    }

    if(byear > constants::CURRENT_YEAR){
        ui->label_birth_year_error->setText("<span style ='color: #ff0000'>People from the future are not allowed!</span>");
        error = true;
    }

    if(error == true){
        return true;
    }
    return false;
}

bool editPioneer::is_number(string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)){
        ++it;
    }

    return !s.empty() && it == s.end();
}

void editPioneer::on_button_cancel_clicked()
{
    this->done(0);
}

void editPioneer::displayRelatedComputers(){
    ui->list_related_computers->clear();

    for(unsigned int i = 0; i < relatedComputers.size(); i++){
        Computer instance = relatedComputers[i];
        ui->list_related_computers->addItem(QString::fromStdString(instance.getComputerName()));
    }
}

void editPioneer::displayUnrelatedComputers(){
    ui->list_unrelated_computers->clear();
    for(unsigned int i = 0; i < unrelatedComputers.size(); i++){
        Computer instance = unrelatedComputers[i];
        ui->list_unrelated_computers->addItem(QString::fromStdString(instance.getComputerName()));
    }
}

void editPioneer::on_list_unrelated_computers_clicked(const QModelIndex &/* unused */){
    ui->button_add_relation->setEnabled(true);
}

void editPioneer::on_list_related_computers_clicked(const QModelIndex &/* unused */){
    ui->button_remove_relation->setEnabled(true);
}

void editPioneer::on_button_remove_relation_clicked()
{
    int currentlySelectedComputerIndex = ui->list_related_computers->currentIndex().row();

    Computer selectedComputer = relatedComputers[currentlySelectedComputerIndex];
    unrelatedComputers.push_back(selectedComputer);
    relatedComputers.erase(relatedComputers.begin() + currentlySelectedComputerIndex);
    displayRelatedComputers();
    displayUnrelatedComputers();

    int compID = selectedComputer.getId();
    relService.removeRelation(pioID, compID);

    ui->button_remove_relation->setEnabled(false);
}

void editPioneer::on_button_add_relation_clicked()
{
    int currentlySelectedComputerIndex = ui->list_unrelated_computers->currentIndex().row();

    Computer selectedComputer = unrelatedComputers[currentlySelectedComputerIndex];
    relatedComputers.push_back(selectedComputer);
    unrelatedComputers.erase(unrelatedComputers.begin() + currentlySelectedComputerIndex);
    displayUnrelatedComputers();
    displayRelatedComputers();

    int compID = selectedComputer.getId();
    relService.addRelations(pioID, compID);

    ui->button_add_relation->setEnabled(false);
}

void editPioneer::on_pushButton_browse_image_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
                    this,
                    "Search for images",
                    "/home",
                    "Image files (*.jpg)"
                );

    if (filePath.length()) // File selected
    {
        QPixmap pixmap(filePath);

        ui->lineEdit_image->setText(filePath);

        QBuffer inBuffer( &image );
        inBuffer.open( QIODevice::WriteOnly );
        pixmap.save( &inBuffer, "JPG" );
    }
    else{

        //didn't open file
    }

}

string editPioneer::getCurrentSex(){
    string sex = ui->edit_dropdown_sex->currentText().toStdString();

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
