#include "trashbinpioneers.h"
#include "ui_trashbinpioneers.h"

TrashBinPioneers::TrashBinPioneers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrashBinPioneers)
{
    ui->setupUi(this);
    displayPioneers();
}

TrashBinPioneers::~TrashBinPioneers()
{
    delete ui;
}

void TrashBinPioneers::displayPioneers(){

    vector<Pioneer> pio = data.getTrash();

    ui->table_pioneers->clearContents();
    ui->table_pioneers->setRowCount(pio.size());

    if(pio.empty()){
        ui->button_restore_selected->setEnabled(false);
    }

    for(unsigned int row = 0; row < pio.size(); row++){
        Pioneer currentPioneer = pio[row];

        QString name = QString::fromStdString(currentPioneer.getName());
        QString birthYear = QString::number(currentPioneer.getByear());

        ui->table_pioneers->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_pioneers->setItem(row, 1, new QTableWidgetItem(birthYear));
    }
    currentlyDisplayedPioneers = pio;
}

void TrashBinPioneers::on_table_pioneers_clicked(const QModelIndex &index)
{
    ui->button_restore_selected->setEnabled(true);
}

void TrashBinPioneers::on_button_restore_selected_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Message", "Are you sure?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes){

        int currentlySelectedPioneerIndex = ui->table_pioneers->currentIndex().row();

        Pioneer currentlySelectedPioneer = currentlyDisplayedPioneers[currentlySelectedPioneerIndex];

        data.editPioneer(currentlySelectedPioneer);

        displayPioneers();

        ui->button_restore_selected->setEnabled(false);
    }
    else{
        return;
    }
}

void TrashBinPioneers::on_button_take_out_the_trash_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Message", "Are you sure?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes){

        data.removePioneer();

        displayPioneers();
    }
    else{
        return;
    }
}

void TrashBinPioneers::on_button_close_clicked()
{
    this->close();
}
