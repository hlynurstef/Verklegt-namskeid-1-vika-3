#include "trashbinpioneers.h"
#include "ui_trashbinpioneers.h"

TrashBinPioneers::TrashBinPioneers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrashBinPioneers)
{
    ui->setupUi(this);
}

TrashBinPioneers::~TrashBinPioneers()
{
    delete ui;
}
