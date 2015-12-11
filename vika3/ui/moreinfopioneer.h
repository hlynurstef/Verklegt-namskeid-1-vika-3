#ifndef MOREINFOPIONEER_H
#define MOREINFOPIONEER_H

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

private:
    Ui::MoreInfoPioneer *ui;
};

#endif // MOREINFOPIONEER_H
