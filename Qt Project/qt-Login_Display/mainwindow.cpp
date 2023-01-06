#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "Delta" && password == "1234")
    {
        QMessageBox::information(this,"Login","Username and Password is correct");
        hide();
        secDialog=new SecDialog(this);
        secDialog->show();
    }
    else {
        QMessageBox::warning(this,"Login","Username and Password Is not correct");
    }
}
