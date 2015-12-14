#include "moreinfopioneer.h"
#include "ui_moreinfopioneer.h"
#include "utilities/constants.h"

using namespace std;

MoreInfoPioneer::MoreInfoPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfoPioneer)
{
    ui->setupUi(this);
    displayPioneer();
}

MoreInfoPioneer::~MoreInfoPioneer()
{
    delete ui;
}

void MoreInfoPioneer::displayPioneer(){
    //Getting the info from selected pioneer
    MainWindow temp;
    pioneer = temp.returnCurrentlySelectedPioneer();

    //Printing out info
    ui->show_single_pioneer->clearContents();
    ui->show_single_pioneer->setLineWidth(5);

    QString name = QString::fromStdString(pioneer.getName());
    QString sex = QString::fromStdString(pioneer.getSex());
    QString birthYear = QString::number(pioneer.getByear());
    QString deathYear = QString::number(pioneer.getDyear());
    QString description = QString::fromStdString(pioneer.getDescription());

    ui->show_single_pioneer->setItem(0, 0, new QTableWidgetItem(name));
    ui->show_single_pioneer->setItem(1, 0, new QTableWidgetItem(sex));
    ui->show_single_pioneer->setItem(2, 0, new QTableWidgetItem(birthYear));
    ui->show_single_pioneer->setItem(3, 0, new QTableWidgetItem(deathYear));
    ui->show_single_pioneer->setItem(4, 0, new QTableWidgetItem(description));
}


void MoreInfoPioneer::on_pushButton_clicked()
{
    this->done(1);
}
