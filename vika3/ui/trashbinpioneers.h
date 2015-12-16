#ifndef TRASHBINPIONEERS_H
#define TRASHBINPIONEERS_H
#include "services/pioneerservice.h"
#include "ui/mainwindow.h"

#include <QDialog>

namespace Ui {
class TrashBinPioneers;
}

class TrashBinPioneers : public QDialog
{
    Q_OBJECT

public:
    explicit TrashBinPioneers(QWidget *parent = 0);
    ~TrashBinPioneers();

private slots:
    void on_table_pioneers_clicked(const QModelIndex &);
    void on_button_restore_selected_clicked();
    void on_button_take_out_the_trash_clicked();
    void on_button_close_clicked();

private:
    Ui::TrashBinPioneers *ui;
    void displayPioneers();
        // Displays the Pioneers in the trash bin
    PioneerService data;
    vector<Pioneer> currentlyDisplayedPioneers;
};

#endif // TRASHBINPIONEERS_H
