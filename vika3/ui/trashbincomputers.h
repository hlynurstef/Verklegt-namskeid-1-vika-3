#ifndef TRASHBINCOMPUTERS_H
#define TRASHBINCOMPUTERS_H
#include "services/computerservice.h"
#include "ui/mainwindow.h"

#include <QDialog>

namespace Ui {
class TrashBinComputers;
}

class TrashBinComputers : public QDialog
{
    Q_OBJECT

public:
    explicit TrashBinComputers(QWidget *parent = 0);
    ~TrashBinComputers();

private slots:
    void on_table_computers_clicked(const QModelIndex &);
    void on_button_restore_selected_clicked();
    void on_button_take_out_the_trash_clicked();
    void on_button_close_clicked();

private:
    Ui::TrashBinComputers *ui;
    void displayComputers();
        // Displays the computer in the trash bin
    vector<Computer> currentlyDisplayedComputers;
    ComputerService data;
};

#endif // TRASHBINCOMPUTERS_H
