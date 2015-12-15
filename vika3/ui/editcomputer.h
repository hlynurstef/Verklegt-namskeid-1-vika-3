#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H
#include "data_types/computer.h"
#include "services/computerservice.h"
#include "services/relationservice.h"
#include "data_types/relation.h"
#include "data_types/pioneer.h"
#include "ui/mainwindow.h"
#include <QDialog>


namespace Ui {
class editComputer;
}

class editComputer : public QDialog
{
    Q_OBJECT

public:
    explicit editComputer(QWidget *parent = 0);
    ~editComputer();

    void setComputer(Computer computer);
    bool errorCheck(string name, string wasBuilt, string buildYear, string type, string description);

    void displayUnrelatedPioneers();
    void displayRelatedPioneers();
private slots:


    void on_pushButton_editcomputer_clicked();

    void on_button_cancel_clicked();

    void on_list_related_pioneers_clicked(const QModelIndex &);
    void on_list_unrelated_pioneers_clicked(const QModelIndex &);
private:
    Ui::editComputer *ui;
    Computer computer;
    MainWindow mainwindow;
    ComputerService compService;
    RelationService relService;
    PioneerService pioService;
    Relation rel;
    vector<Pioneer> relatedPioneers, unrelatedPioneers;

    int compID;
};

#endif // EDITCOMPUTER_H
