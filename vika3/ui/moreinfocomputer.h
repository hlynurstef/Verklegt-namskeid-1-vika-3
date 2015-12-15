#ifndef MOREINFOCOMPUTER_H
#define MOREINFOCOMPUTER_H
#include "data_types/computer.h"
#include "data_types/relation.h"
#include "services/computerservice.h"
#include "services/relationservice.h"
#include "ui/mainwindow.h"

#include <QDialog>

/*  ------------------------------------------------------------
 *                  This window is only displaying
 *              information about the selected computer
 *  ------------------------------------------------------------
 */

namespace Ui {
class MoreInfoComputer;
}

class MoreInfoComputer : public QDialog
{
    Q_OBJECT

public:
    explicit MoreInfoComputer(QWidget *parent = 0);
    ~MoreInfoComputer();
    void setComputer(Computer computer);
        // Sets information in MoreInfo window to the currently selected computer

private slots:

    void on_pushButton_clicked();
        // Close window
    void getRelationList(Computer computer);
        // Sets relation info in MoreInfo window to the currently selected computer


private:
    Ui::MoreInfoComputer *ui;
    RelationService relationService;
    vector<Relation> relation;
};

#endif // MOREINFOCOMPUTER_H
