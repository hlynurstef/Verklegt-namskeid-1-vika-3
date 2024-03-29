#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "moreinfocomputer.h"
#include "editcomputer.h"
#include "moreinfopioneer.h"
#include "trashbinpioneers.h"
#include "trashbincomputers.h"

#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Pioneer dropdown lists:
    ui->dropdown_pioneers_search_by->addItem("Name");
    ui->dropdown_pioneers_search_by->addItem("Birth Year");
    ui->dropdown_pioneers_order_by->addItem("Name");
    ui->dropdown_pioneers_order_by->addItem("Birth Year");
    ui->dropdown_pioneers_order_direction->addItem("Ascending");
    ui->dropdown_pioneers_order_direction->addItem("Descending");
    ui->dropdown_pioneers_filter_gender->addItem("No filter");
    ui->dropdown_pioneers_filter_gender->addItem("Female");
    ui->dropdown_pioneers_filter_gender->addItem("Male");
    ui->dropdown_pioneers_filter_vital_status->addItem("No filter");
    ui->dropdown_pioneers_filter_vital_status->addItem("Alive");
    ui->dropdown_pioneers_filter_vital_status->addItem("Deceased");

    // Computer dropdown lists:
    ui->dropdown_computers_search_by->addItem("Name");
    ui->dropdown_computers_search_by->addItem("Build Year");
    ui->dropdown_computers_order_by->addItem("Name");
    ui->dropdown_computers_order_by->addItem("Build Year");
    ui->dropdown_computers_order_direction->addItem("Ascending");
    ui->dropdown_computers_order_direction->addItem("Descending");
    ui->dropdown_computers_filter_type->addItem("No filter");
    ui->dropdown_computers_filter_type->addItem("Mechanical");
    ui->dropdown_computers_filter_type->addItem("Electronic");
    ui->dropdown_computers_filter_type->addItem("Transistor");
    ui->dropdown_computers_filter_type->addItem("Other");
    ui->dropdown_computers_filter_built->addItem("No filter");
    ui->dropdown_computers_filter_built->addItem("Was built");
    ui->dropdown_computers_filter_built->addItem("Was not built");

    displayAllPioneers();
    displayAllComputers();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::displayAllPioneers(){
    vector<Pioneer> pioneers = pioneerService.printQuery(getCurrentGenderPioneers(), getCurrentVitalStatusPioneers(), getCurrentOrderByPioneers(), getCurrentDirectionPioneers());
    displayPioneers(pioneers);
}

void MainWindow::displayAllComputers(){
    vector<Computer> computers = computerService.printQuery(getCurrentBuiltComputers(), getCurrentTypeComputers(), getCurrentOrderByComputers(), getCurrentDirectionComputers());
    displayComputers(computers);
}

void MainWindow::displayPioneers(std::vector<Pioneer> pioneers){
    ui->table_pioneers->clearContents();
    ui->table_pioneers->setRowCount(pioneers.size());

    if(pioneers.empty()){
        disableButtonsForPioneer();
    }

    for(unsigned int row = 0; row < pioneers.size(); row++){
        Pioneer currentPioneer = pioneers[row];

        QString name = QString::fromStdString(currentPioneer.getName());
        QString birthYear = QString::number(currentPioneer.getByear());

        ui->table_pioneers->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_pioneers->setItem(row, 1, new QTableWidgetItem(birthYear));
    }

    currentlyDisplayedPioneers = pioneers;
}

void MainWindow::displayComputers(std::vector<Computer> computers){
    ui->table_computers->clearContents();
    ui->table_computers->setRowCount(computers.size());

    if(computers.empty()){
        disableButtonsForComputer();
    }

    for(unsigned int row = 0; row < computers.size(); row++){
        Computer currentComputer = computers[row];
        QString buildYear;

        QString name = QString::fromStdString(currentComputer.getComputerName());
        if(currentComputer.getBuildYear() == 0){
            buildYear = QString::fromStdString("Not built");
        }
        else{
            buildYear = QString::number(currentComputer.getBuildYear());
        }

        ui->table_computers->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(row, 1, new QTableWidgetItem(buildYear));
    }

    currentlyDisplayedComputers = computers;
}

void MainWindow::on_input_search_pioneers_textChanged(){
    string userInput = ui->input_search_pioneers->text().toStdString();

    vector<Pioneer> pioneers = pioneerService.search(userInput, getCurrentSearchByPioneers(), getCurrentGenderPioneers(), getCurrentVitalStatusPioneers(), getCurrentOrderByPioneers(),getCurrentDirectionPioneers());
    displayPioneers(pioneers);
}

void MainWindow::on_input_search_computers_textChanged(){
    string userInput = ui->input_search_computers->text().toStdString();

    vector<Computer> computers = computerService.search(userInput, getCurrentSearchByComputers(), getCurrentBuiltComputers(), getCurrentTypeComputers(), getCurrentOrderByComputers(), getCurrentDirectionComputers());
    displayComputers(computers);
}

void MainWindow::on_dropdown_pioneers_order_by_currentIndexChanged(int /* unused */){
    on_input_search_pioneers_textChanged();
}

void MainWindow::on_dropdown_pioneers_order_direction_currentIndexChanged(int /* unused */){
    on_input_search_pioneers_textChanged();
}

void MainWindow::on_dropdown_pioneers_filter_gender_currentIndexChanged(int /* unused */){
    on_input_search_pioneers_textChanged();
}

void MainWindow::on_dropdown_pioneers_filter_vital_status_currentIndexChanged(int /* unused */){
    on_input_search_pioneers_textChanged();
}

void MainWindow::on_dropdown_computers_order_by_currentIndexChanged(int /* unused */){
    on_input_search_computers_textChanged();
}

void MainWindow::on_dropdown_computers_order_direction_currentIndexChanged(int /* unused */){
    on_input_search_computers_textChanged();
}

void MainWindow::on_dropdown_computers_filter_type_currentIndexChanged(int /* unused */){
    on_input_search_computers_textChanged();
}

void MainWindow::on_dropdown_computers_filter_built_currentIndexChanged(int /* unused */){
    on_input_search_computers_textChanged();
}

string MainWindow::getCurrentOrderByPioneers(){
    string orderBy = ui->dropdown_pioneers_order_by->currentText().toStdString();

    if(orderBy == "Name"){
        return constants::NAME;
    }
    else if(orderBy == "Birth Year"){
        return constants::BIRTH_YEAR;
    }
    else{
        return constants::NAME;
    }
}

string MainWindow::getCurrentOrderByComputers(){
    string orderBy = ui->dropdown_computers_order_by->currentText().toStdString();

    if(orderBy == "Name"){
        return constants::COMP_NAME;
    }
    else if(orderBy == "Build Year"){
        return constants::BUILD_YEAR;
    }
    else{
        return constants::COMP_NAME;
    }
}

string MainWindow::getCurrentDirectionPioneers(){
    string direction = ui->dropdown_pioneers_order_direction->currentText().toStdString();

    if(direction == "Ascending"){
        return constants::ASC;
    }
    else if(direction == "Descending"){
        return constants::DESC;
    }
    else{
        return constants::ASC;
    }
}

string MainWindow::getCurrentDirectionComputers(){
    string direction = ui->dropdown_computers_order_direction->currentText().toStdString();

    if(direction == "Ascending"){
        return constants::ASC;
    }
    else if(direction == "Descending"){
        return constants::DESC;
    }
    else{
        return constants::ASC;
    }
}

string MainWindow::getCurrentTypeComputers(){
    string type = ui->dropdown_computers_filter_type->currentText().toStdString();

    if(type == "No filter"){
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

string MainWindow::getCurrentBuiltComputers(){
    string built = ui->dropdown_computers_filter_built->currentText().toStdString();

    if(built == "No filter"){
        return "";
    }
    else if(built == "Was built"){
        return constants::DB_TRUE;
    }
    else if(built == "Was not built"){
        return constants::DB_FALSE;
    }
    else{
        return "";
    }
}

string MainWindow::getCurrentSearchByComputers(){
    string searchBy = ui->dropdown_computers_search_by->currentText().toStdString();

    if(searchBy == "Name"){
        return constants::COMP_NAME;
    }
    else if(searchBy == "Build Year"){
        return constants::BUILD_YEAR;
    }
    else{
        return constants::NAME;
    }
}

string MainWindow::getCurrentGenderPioneers(){
    string gender = ui->dropdown_pioneers_filter_gender->currentText().toStdString();

    if(gender == "No filter"){
        return "";
    }
    else if(gender == "Female"){
        return constants::FEMALE;
    }
    else if(gender == "Male"){
        return constants::MALE;
    }
    else{
        return "";
    }
}

string MainWindow::getCurrentVitalStatusPioneers(){
    string vitalStats = ui->dropdown_pioneers_filter_vital_status->currentText().toStdString();

    if(vitalStats == "No filter"){
        return "";
    }
    else if(vitalStats == "Alive"){
        return constants::IS_NULL;
    }
    else if(vitalStats == "Deceased"){
        return constants::IS_NOT_NULL;
    }
    else{
        return "";
    }
}

string MainWindow::getCurrentSearchByPioneers(){
    string searchBy = ui->dropdown_pioneers_search_by->currentText().toStdString();

    if(searchBy == "Name"){
        return constants::NAME;
    }
    else if(searchBy == "Birth Year"){
        return constants::BIRTH_YEAR;
    }
    else{
        return constants::NAME;
    }
}

void MainWindow::on_button_pioneer_remove_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Message", "Are you sure?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes){
        int currentlySelectedPioneerIndex = ui->table_pioneers->currentIndex().row();

        Pioneer currentlySelectedPioneer = currentlyDisplayedPioneers[currentlySelectedPioneerIndex];

        int pioID = currentlySelectedPioneer.getId();
        relationService.removePioneerRelation(pioID);

        pioneerService.pioneerToTrash(currentlySelectedPioneer);

        ui->input_search_pioneers->setText("");
        displayAllPioneers();

        disableButtonsForPioneer();

    }
    else{
        return;
    }


}

void MainWindow::on_button_computer_remove_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Message", "Are you sure?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes){
        int currentlySelectedComputerIndex = ui->table_computers->currentIndex().row();

        Computer currentlySelectedComputer = currentlyDisplayedComputers[currentlySelectedComputerIndex];

        computerService.computerToTrash(currentlySelectedComputer);

        ui->input_search_computers->setText("");
        displayAllComputers();

        disableButtonsForComputer();

    }
    else{
        return;
    }
}

void MainWindow::on_table_pioneers_clicked(){
    ui->button_pioneer_remove->setEnabled(true);
    ui->pushButton_pioneers_more_info->setEnabled(true);
    ui->pushButton_pioneers_edit->setEnabled(true);
}

void MainWindow::on_table_computers_clicked(const QModelIndex &/* unused */){
    ui->button_computer_remove->setEnabled(true);
    ui->pushButton_computers_more_info->setEnabled(true);
    ui->pushButton_computers_edit->setEnabled(true);
}

void MainWindow::on_pushButton_pioneers_more_info_clicked(){

    int currentlySelectedPioneerIndex = ui->table_pioneers->currentIndex().row();
    currentlySelectedPio = currentlyDisplayedPioneers[currentlySelectedPioneerIndex];
    MoreInfoPioneer temp;

    temp.setPioneer(currentlySelectedPio);
    temp.setModal(true);
    temp.exec();

}

void MainWindow::on_pushButton_computers_more_info_clicked(){

    int currentlySelectedComputerIndex = ui->table_computers->currentIndex().row();
    currentlySelectedComp = currentlyDisplayedComputers[currentlySelectedComputerIndex];

    MoreInfoComputer temp;

    temp.setComputer(currentlySelectedComp);
    temp.setModal(true);
    temp.exec();
}

Pioneer MainWindow::returnCurrentlySelectedPioneer(){

    QString name = QString::fromStdString(currentlySelectedPio.getName());
    QString sex = QString::fromStdString(currentlySelectedPio.getSex());
    QString birthYear = QString::number(currentlySelectedPio.getByear());
    QString deathYear = QString::number(currentlySelectedPio.getDyear());
    QString description = QString::fromStdString(currentlySelectedPio.getDescription());

    return currentlySelectedPio;
}


Computer MainWindow::returnCurrentlySelectedComputer(){

    QString name = QString::fromStdString(currentlySelectedComp.getComputerName());
    QString type = QString::fromStdString(currentlySelectedComp.getComputerType());
    QString wasbuilt = QString::fromStdString(currentlySelectedComp.getWasItBuilt());
    QString dbuildyear = QString::number(currentlySelectedComp.getBuildYear());
    QString description = QString::fromStdString(currentlySelectedComp.getComputerDescription());

    return currentlySelectedComp;
}

void MainWindow::on_pushButton_pioneers_add_new_entry_clicked(){

    AddPioneer addPio;
    addPio.displayUnrelatedComputers(currentlyDisplayedComputers);
    int returnValue = addPio.exec();

    if (returnValue == 1){
        displayAllPioneers();

        ui->statusBar->showMessage("Pioneer has been added", 2000);
    }
    else{
        ui->statusBar->showMessage("No pioneer was added", 2000);
    }
}

void MainWindow::on_pushButton_computers_add_new_entry_clicked(){

    addComputer addComp;
    addComp.displayUnrelatedPioneers(currentlyDisplayedPioneers);
    int returnValue = addComp.exec();


    if (returnValue == 1){
        displayAllComputers();

        ui->statusBar->showMessage("Computer has been added", 2000);
    }
    else{
        ui->statusBar->showMessage("No computer was added", 2000);
    }
}

void MainWindow::on_pushButton_pioneers_edit_clicked()
{
    int currentlySelectedPioneerIndex = ui->table_pioneers->currentIndex().row();
    currentlySelectedPio = currentlyDisplayedPioneers[currentlySelectedPioneerIndex];

    editPioneer editPio;
    editPio.setPioneer(currentlySelectedPio);
    editPio.setModal(true);
    int returnValue = editPio.exec();

    if (returnValue == 1){
        displayAllPioneers();
        disableButtonsForPioneer();
        ui->statusBar->showMessage("Pioneer has been modified", 2000);
    }
    else{
        ui->statusBar->showMessage("Pioneer has not been modified", 2000);
    }
}

void MainWindow::on_pushButton_computers_edit_clicked(){
    int currentlySelectedComputerIndex = ui->table_computers->currentIndex().row();
    currentlySelectedComp = currentlyDisplayedComputers[currentlySelectedComputerIndex];

    editComputer editComp;
    editComp.setComputer(currentlySelectedComp);
    editComp.setModal(true);
    int returnValue2 = editComp.exec();


    if (returnValue2 == 1){
        displayAllComputers();
        disableButtonsForComputer();
        ui->statusBar->showMessage("Computer has been modified", 2000);
    }
    else{
        ui->statusBar->showMessage("Computer was not modified", 2000);
    }

}

void MainWindow::disableButtonsForPioneer(){
    ui->button_pioneer_remove->setEnabled(false);
    ui->pushButton_pioneers_more_info->setEnabled(false);
    ui->pushButton_pioneers_edit->setEnabled(false);
}

void MainWindow::disableButtonsForComputer(){
    ui->button_computer_remove->setEnabled(false);
    ui->pushButton_computers_more_info->setEnabled(false);
    ui->pushButton_computers_edit->setEnabled(false);
}

void MainWindow::on_trash_button_pioneers_clicked(){
    TrashBinPioneers trash;
    trash.exec();
    displayAllPioneers();
}

void MainWindow::on_trash_button_computers_clicked(){
    TrashBinComputers trash;
    trash.exec();
    displayAllComputers();
}
