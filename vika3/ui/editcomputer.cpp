#include "editcomputer.h"
#include "ui_editcomputer.h"
#include "utilities/constants.h"
#include "data_types/computer.h"



editComputer::editComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer){
    ui->setupUi(this);

    // type dropdown list
    ui->edit_dropdown_type->addItem("");
    ui->edit_dropdown_type->addItem("Mechanical");
    ui->edit_dropdown_type->addItem("Electronic");
    ui->edit_dropdown_type->addItem("Transistor");
    ui->edit_dropdown_type->addItem("Other");

    // was it built dropdown list
    ui->edit_dropdown_was_it_built->addItem("");
    ui->edit_dropdown_was_it_built->addItem("Yes");
    ui->edit_dropdown_was_it_built->addItem("No");
}

editComputer::~editComputer(){
    delete ui;
}

void editComputer::setComputer(Computer comp){
    string type;
    string wasBuilt;

    compID = comp.getId();

    if(comp.getComputerType() == constants::MECHANICAL){
        type = "Mechanical";
    }
    else if(comp.getComputerType() == constants::ELECTRONIC){
        type = "Electronic";
    }
    else if(comp.getComputerType() == constants::TRANSISTOR){
        type = "Transistor";
    }
    else{
        type = "Other";
    }

    if(comp.getWasItBuilt() == constants::DB_TRUE){
        wasBuilt = "Yes";
    }
    else{
        wasBuilt = "No";
    }

    // Printing info
    ui->edit_name->setText(QString::fromStdString(comp.getComputerName()));
    ui->edit_dropdown_type->setCurrentText(QString::fromStdString(type));
    ui->edit_dropdown_was_it_built->setCurrentText(QString::fromStdString(wasBuilt));
    if(comp.getBuildYear() == 0){
        ui->edit_buildyear->setText(QString::fromStdString(""));
    }
    else{
        ui->edit_buildyear->setText(QString::number(comp.getBuildYear()));
    }
    ui->edit_description->setText(QString::fromStdString(comp.getComputerDescription()));

    vector<Relation> allRelations = relService.displayRelations();
    vector<Pioneer> allPioneers = pioService.getList();

    for(unsigned int i = 0; i < allRelations.size(); i++){
        Relation relInstance = allRelations[i];

        for(unsigned int j = 0; j < allPioneers.size(); j++){
            Pioneer pioInstance = allPioneers[j];

            if(relInstance.getCompName() == comp.getComputerName() && relInstance.getPioName() == pioInstance.getName()){
                relatedPioneers.push_back(pioInstance);
            }
        }
    }
    bool relatedPioneer = false;
    for(unsigned int i = 0; i < allPioneers.size(); i++){
        Pioneer unrelated = allPioneers[i];
        relatedPioneer = false;
        for(unsigned int j = 0; j < relatedPioneers.size(); j++){
            Pioneer related = relatedPioneers[j];
            if(related.getName() != unrelated.getName()){
                relatedPioneer = false;
            }
            else{
                relatedPioneer = true;
            }
        }
        if(relatedPioneer == false){
            unrelatedPioneers.push_back(unrelated);
        }
    }

    displayRelatedPioneers();
    displayUnrelatedPioneers();

    ui->button_add_relation->setEnabled(false);
    ui->button_remove_relation->setEnabled(false);

}


void editComputer::on_pushButton_editcomputer_clicked(){
    // Clear error messages
    emptyLines();

    string name = ui->edit_name->text().toStdString();
    string built = getCurrentWasItBuilt();
    string type = getCurrentType();
    string buildYear = ui->edit_buildyear->text().toStdString();
    string description = ui->edit_description->toPlainText().toStdString();

    bool error = errorCheck(name, built, buildYear, type, description);
    if(error){
        return;
    }

    if(buildYear.empty()){
        buildYear = "0";
    }

    int bYear = atoi(buildYear.c_str());

    Computer comp(compID, name, bYear, type, built, description, image);

    int answer = QMessageBox::question(this, "Save Changes", "Are you sure you want to save changes?");

    if(answer == QMessageBox::No){
        return;
    }
    else{
        compService.editComputer(comp);

        this->done(1);
    }
}

void editComputer::emptyLines(){
    ui->label_name_error->setText("");
    ui->label_type_error->setText("");
    ui->label_wasbuilt_error->setText("");
    ui->label_description_error->setText("");
    ui->label_build_year_error->setText("");
}

bool editComputer::errorCheck(string name, string wasBuilt, string buildYear, string type, string description){
    bool error = false;

    if(name.empty()){
        ui->label_name_error->setText("<span style ='color: #ff0000'>Input Name!</span>");
        error = true;
    }
    if(type.empty()){
        ui->label_type_error->setText("<span style ='color: #ff0000'>Choose Type!</span>");
        error = true;
    }
    if(wasBuilt.empty()){
        ui->label_wasbuilt_error->setText("<span style ='color: #ff0000'>Choose Yes/No!</span>");
        error = true;
        qDebug() << QString::fromStdString(wasBuilt);
    }

    if((wasBuilt == "" || wasBuilt == "No") && buildYear.empty()){
        // do nothing
    }
    if((wasBuilt == "false") && !buildYear.empty()){
        ui->label_build_year_error->setText("<span style ='color: #ff0000'>Computer Wasn't Built!</span>");
        error = true;
    }
    else if(wasBuilt == "true" && buildYear.empty()){
        ui->label_build_year_error->setText("<span style ='color: #ff0000'>Input Build Year!</span>");
        error = true;
    }
    else if(wasBuilt == "true" && !is_number(buildYear)){
        ui->label_build_year_error->setText("<span style ='color: #ff0000'>Input a Number!</span>");
        error = true;
    }

    if((wasBuilt == "" || wasBuilt == "No") && buildYear.empty()){
        // do nothing
    }
    if((wasBuilt == "false") && !buildYear.empty()){
        ui->label_build_year_error->setText("<span style ='color: #ff0000'>Computer Wasn't Built!</span>");
        error = true;
    }
    else if(wasBuilt == "true" && buildYear.empty()){
        ui->label_build_year_error->setText("<span style ='color: #ff0000'>Input Build Year!</span>");
        error = true;
    }
    else if(wasBuilt == "true" && !is_number(buildYear)){
        ui->label_build_year_error->setText("<span style ='color: #ff0000'>Input a Number!</span>");
        error = true;
    }

    if(description.empty()){
        ui->label_description_error->setText("<span style ='color: #ff0000'>Input Description!</span>");
        error = true;
    }

    int bYear = atoi(buildYear.c_str());

    if(bYear > constants::CURRENT_YEAR){
        ui->label_build_year_error->setText("<span style ='color: #ff0000'>Computers from the future are not allowed!</span>");
        error = true;
    }

    if(error == true){
        return true;
      }
        return false;

}

bool editComputer::is_number(string& s){

    string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)){
            ++it;
        }

        return !s.empty() && it == s.end();
}

void editComputer::on_button_cancel_clicked(){
    this->done(0);
}
void editComputer::displayRelatedPioneers(){
    ui->list_related_pioneers->clear();

    for(unsigned int i = 0; i < relatedPioneers.size(); i++){
        Pioneer instance = relatedPioneers[i];
        ui->list_related_pioneers->addItem(QString::fromStdString(instance.getName()));
    }
}

void editComputer::displayUnrelatedPioneers(){
    ui->list_unrelated_pioneers->clear();

    for(unsigned int i = 0; i < unrelatedPioneers.size(); i++){
        Pioneer instance = unrelatedPioneers[i];
        ui->list_unrelated_pioneers->addItem(QString::fromStdString(instance.getName()));
    }
}

void editComputer::on_list_unrelated_pioneers_clicked(const QModelIndex &/* unused */){
    ui->button_add_relation->setEnabled(true);
}

void editComputer::on_list_related_pioneers_clicked(const QModelIndex &/* unused */){
    ui->button_remove_relation->setEnabled(true);
}

void editComputer::on_button_remove_relation_clicked(){
    int currentlySelectedPioneerIndex = ui->list_related_pioneers->currentIndex().row();

    Pioneer selectedPioneer = relatedPioneers[currentlySelectedPioneerIndex];
    unrelatedPioneers.push_back(selectedPioneer);
    relatedPioneers.erase(relatedPioneers.begin() + currentlySelectedPioneerIndex);
    displayRelatedPioneers();
    displayUnrelatedPioneers();

    int pioID = selectedPioneer.getId();
    relService.removeRelation(pioID, compID);

    ui->button_remove_relation->setEnabled(false);
}

void editComputer::on_button_add_relation_clicked(){
    int currentlySelectedPioneerIndex = ui->list_unrelated_pioneers->currentIndex().row();

    Pioneer selectedPioneer = unrelatedPioneers[currentlySelectedPioneerIndex];
    relatedPioneers.push_back(selectedPioneer);
    unrelatedPioneers.erase(unrelatedPioneers.begin() + currentlySelectedPioneerIndex);
    displayUnrelatedPioneers();
    displayRelatedPioneers();

    int pioID = selectedPioneer.getId();
    relService.addRelations(pioID, compID);

    ui->button_add_relation->setEnabled(false);
}


void editComputer::on_pushButton_image_clicked(){
    QString filePath = QFileDialog::getOpenFileName(
                    this,
                    "Search for images",
                    "/home",
                    "Image files (*.jpg)"
                );

    if (filePath.length()){ // File selected

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

string editComputer::getCurrentType(){
    string type = ui->edit_dropdown_type->currentText().toStdString();

    if(type == ""){
        return "";
    }
    else if(type == "Mechanical"){
        return constants::MECHANICAL;
    }
    else if(type == "Electronic"){
        return constants::ELECTRONIC;
    }
    else if(type == "Transistor"){
        return constants::TRANSISTOR;
    }
    else if(type == "Other"){
        return "other";
    }
    else{
        return "";
    }
}

string editComputer::getCurrentWasItBuilt(){
    string wasBuilt = ui->edit_dropdown_was_it_built->currentText().toStdString();

    if(wasBuilt == ""){
        return "";
    }
    else if(wasBuilt == "Yes"){
        return constants::DB_TRUE;
    }
    else if(wasBuilt == "No"){
        return constants::DB_FALSE;
    }
    else{
        return "";
    }

}
