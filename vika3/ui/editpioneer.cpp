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
    string sex = ui->edit_sex->text().toStdString();
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

    pioService.editPioneer(pio);

    this->done(1);

}

bool editPioneer::errorCheck(string name, string sex, string birthyear, string deathyear, string description){
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
        ui->label_birth_year_error->setText("<span style ='color: #ff0000'>Input birth year</span>");
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
