#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QCheckBox>
#include<QMessageBox>
#include<QDebug>
#include<QDateTime>
#include<QDate>
#include<QDateEdit>
#include<QTextStream>
#include<QVector>
#include "qstackedwidget.h"
#include<QVector>
QVector<QString>dt1;
QVector<QString>dt2;
QDate d1;
QDate d2;
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



void MainWindow::on_pushButton_issue_clicked()
{
    QString BookName = ui->lineEdit_bookname->text();
    QString StudentId =ui->comboBox_ib->currentText();
    QDate d1= ui->dateEdit->date();
    qDebug()<<d1;

    if(BookName == " " && StudentId == " ")
    {
    QMessageBox::warning(this," ","Book Is Issue");
    }
    else
    {
        QMessageBox::warning(this,"Warning","Please Select studentid and bookname and date");
    }
}


void MainWindow::on_pushButton_Issue_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_back_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_Return_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_serach_clicked()
{
    QString StudentId=ui->lineEdit_studentid->text();
    QString SelectBook = ui->comboBox_selectbook->currentText();
    QDate d2= ui->dateEdit_2->date();
    qDebug()<<d2;
    QTextStream(stdout);
    QString out;
//   auto date1 = (d1 == d2);

//   auto date2 = (d1 >= d2);
//   d2 = d2.addDays(-5);
//   QMessageBox::warning(this,"Warning ","Book is not return Valid Time ");

//  {
//      QMessageBox::QMessageBox::warning(this,"Warning ","Book is return Valid Time ");
//  }

     QString dt1= d1;
}

void MainWindow::on_pushButton_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_return_clicked()
{
    QString checkBox;
    QString amount = ui->lineEdit_amountReturn->text();
    if(ui->checkBox_return->isCheckable())
    {
        QMessageBox::warning(this,"Notice","No Fine");
    }
        else if(amount == " " && checkBox == " ")
        {
            QMessageBox::warning(this,"Notice","Fine Is Paid");
        }
        else
    {
        QMessageBox::warning(this,"Notice ","Fine is not paid");
    }
}


