#include "trashbincomputers.h"
#include "ui_trashbincomputers.h"

TrashBinComputers::TrashBinComputers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrashBinComputers){
    ui->setupUi(this);
    displayComputers();
}

TrashBinComputers::~TrashBinComputers(){
    delete ui;
}

void TrashBinComputers::displayComputers(){

    vector<Computer> comp = data.getTrash();

    ui->table_computers->clearContents();
    ui->table_computers->setRowCount(comp.size());

    if(comp.empty()){
        ui->button_restore_selected->setEnabled(false);
    }

    for(unsigned int row = 0; row < comp.size(); row++){
        Computer currentComputer = comp[row];

        QString name = QString::fromStdString(currentComputer.getComputerName());
        QString buildYear = QString::number(currentComputer.getBuildYear());

        ui->table_computers->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(row, 1, new QTableWidgetItem(buildYear));
    }
    currentlyDisplayedComputers = comp;
}

void TrashBinComputers::on_table_computers_clicked(const QModelIndex &/* unused */){
    ui->button_restore_selected->setEnabled(true);
}

void TrashBinComputers::on_button_restore_selected_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Message", "Are you sure?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes){
        int currentlySelectedComputerIndex = ui->table_computers->currentIndex().row();

        Computer currentlySelectedComputer = currentlyDisplayedComputers[currentlySelectedComputerIndex];

        data.editComputer(currentlySelectedComputer);

        displayComputers();
        ui->button_restore_selected->setEnabled(false);

    }
    else{
        return;
    }
}

void TrashBinComputers::on_button_take_out_the_trash_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Message", "Are you sure?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes){

        data.removeComputer();

        displayComputers();
    }
    else{
        return;
    }
}

void TrashBinComputers::on_button_close_clicked(){
    this->close();
}
