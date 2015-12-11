#include "moreinfo.h"
#include "ui_moreinfo.h"

MoreInfo::MoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
}

MoreInfo::~MoreInfo()
{
    delete ui;
}
