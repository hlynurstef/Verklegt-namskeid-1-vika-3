#include "moreinfocomputer.h"
#include "ui_moreinfocomputer.h"

MoreInfoComputer::MoreInfoComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfoComputer)
{
    ui->setupUi(this);
}

MoreInfoComputer::~MoreInfoComputer()
{
    delete ui;
}
