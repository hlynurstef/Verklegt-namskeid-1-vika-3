#ifndef MOREINFOCOMPUTER_H
#define MOREINFOCOMPUTER_H

#include <QDialog>

namespace Ui {
class MoreInfoComputer;
}

class MoreInfoComputer : public QDialog
{
    Q_OBJECT

public:
    explicit MoreInfoComputer(QWidget *parent = 0);
    ~MoreInfoComputer();

private:
    Ui::MoreInfoComputer *ui;
};

#endif // MOREINFOCOMPUTER_H
