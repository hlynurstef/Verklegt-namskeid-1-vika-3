#include "moreinfopioneer.h"
#include "ui_moreinfopioneer.h"
#include "utilities/constants.h"

using namespace std;

MoreInfoPioneer::MoreInfoPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfoPioneer)
{
    ui->setupUi(this);

}

MoreInfoPioneer::~MoreInfoPioneer()
{
    delete ui;
}
