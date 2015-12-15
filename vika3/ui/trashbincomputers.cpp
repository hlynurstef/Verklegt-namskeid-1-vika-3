#include "trashbincomputers.h"
#include "ui_trashbincomputers.h"

TrashBinComputers::TrashBinComputers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrashBinComputers)
{
    ui->setupUi(this);
}

TrashBinComputers::~TrashBinComputers()
{
    delete ui;
}
