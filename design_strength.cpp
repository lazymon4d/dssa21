#include "design_strength.h"
#include "ui_design_strength.h"
#include <QtCore>
#include <QtGui>

design_strength::design_strength(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::design_strength)
{
    ui->setupUi(this);
}

design_strength::~design_strength()
{
    delete ui;
}


void design_strength::on_pushButton_clicked()
{
    double fy = ui->lineEdit->text().toDouble();
    double l = ui->lineEdit_2->text().toDouble();
    double k = ui->lineEdit_3->text().toDouble();
    QString qsec  = ui->lineEdit_4->text();
    std::string sec = qsec.toStdString();
    double e = ui->lineEdit_5->text().toDouble();

    double res=calc(sec, e, fy, k*l);

    QString str = "The design strength is ";
    str.append(QString::number(res, 'f', 3));
    str.append(" N/mm2.");

    QMessageBox::information(this, "Title", str);
}

void design_strength::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}
