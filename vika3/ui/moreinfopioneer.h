#ifndef MOREINFOPIONEER_H
#define MOREINFOPIONEER_H
#include "data_types/pioneer.h"
#include "data_types/relation.h"
#include "services/pioneerservice.h"
#include "services/relationservice.h"
#include "ui/mainwindow.h"

#include <QDialog>

namespace Ui {
class MoreInfoPioneer;
}

class MoreInfoPioneer : public QDialog
{
    Q_OBJECT

public:
    explicit MoreInfoPioneer(QWidget *parent = 0);
    ~MoreInfoPioneer();
    void setPioneer(Pioneer pioneer);
        // Sets information in MoreInfo window to the currently selected Pioneer in the table in main window

private slots:

    void on_pushButton_close_clicked();
    void getRelationList(Pioneer pioneer);

private:
    Ui::MoreInfoPioneer *ui;
    //MainWindow mainwindow;
    RelationService relationService;
    vector<Relation> relation;
};

#endif // MOREINFOPIONEER_H
