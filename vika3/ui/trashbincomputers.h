#ifndef TRASHBINCOMPUTERS_H
#define TRASHBINCOMPUTERS_H

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

private:
    Ui::TrashBinComputers *ui;
};

#endif // TRASHBINCOMPUTERS_H
