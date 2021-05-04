#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>
#include<QFileDialog>
#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"sweetlin 4168","Do you want to submit the form?",QMessageBox::Ok|QMessageBox::Cancel);
    if(reply==QMessageBox::Ok)
    {
        QMessageBox::information(this,"sweetlin 4168","Submitted successfully!");
    }
    if(reply==QMessageBox::Cancel)
    {
        qDebug()<<"Nothing is submitted..";
    }
}

void MainWindow::on_lineEdit_4_returnPressed()
{
    QRegularExpression re("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
    QRegularExpressionMatch match = re.match(ui->lineEdit_3->text());
    bool hasMatch = match.hasMatch();
    if (!hasMatch)
    {
       QMessageBox::information(this,"vimal 4176","Invalid Format");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString picpath=QFileDialog::getOpenFileName(this,tr("Open file"),"C://","PDF File(*.pdf)");

}


