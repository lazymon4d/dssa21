#ifndef DESIGN_STRENGTH_H
#define DESIGN_STRENGTH_H

#include <QMainWindow>
#include <QMessageBox>
#include "calculi.h"
QT_BEGIN_NAMESPACE
namespace Ui { class design_strength; }
QT_END_NAMESPACE

class design_strength : public QMainWindow
{
    Q_OBJECT

public:
    design_strength(QWidget *parent = nullptr);
    ~design_strength();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::design_strength *ui;
};
#endif // DESIGN_STRENGTH_H
