#include "mainwindow.h"
#include "ui_mainwindow.h"

bool add=false;
bool sub=false;
bool divis=false;
bool mul=false;

int old=0;
int newval=0;

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


void MainWindow::on_pushButton0_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("0");
    else
        ui->label_display->setText(DisplayNum + "0");

}


void MainWindow::on_pushButton1_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("1");
    else
        ui->label_display->setText(DisplayNum + "1");
}


void MainWindow::on_pushButton2_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("2");
    else
        ui->label_display->setText(DisplayNum + "2");
}


void MainWindow::on_pushButton3_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("3");
    else
        ui->label_display->setText(DisplayNum + "3");
}

void MainWindow::on_pushButton4_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("4");
    else
        ui->label_display->setText(DisplayNum + "4");
}


void MainWindow::on_pushButton5_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("5");
    else
        ui->label_display->setText(DisplayNum + "5");
}


void MainWindow::on_pushButton6_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("6");
    else
        ui->label_display->setText(DisplayNum + "6");
}


void MainWindow::on_pushButton7_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("7");
    else
        ui->label_display->setText(DisplayNum + "7");
}


void MainWindow::on_pushButton8_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("8");
    else
        ui->label_display->setText(DisplayNum + "8");
}


void MainWindow::on_pushButton9_clicked()
{
    QString DisplayNum=ui->label_display->text();
    if(DisplayNum.toInt(0,10)==0)
        ui->label_display->setText("9");
    else
        ui->label_display->setText(DisplayNum + "9");
}


void MainWindow::on_pushButtonC_clicked()
{
    ui->label_display->setText("0");
}


void MainWindow::on_pushButtonMul_clicked()
{
    old=ui->label_display->text().toInt(0,10);
    add=false;
    mul=true;
    sub=false;
    divis=false;
    ui->label_display->setText("0");
}


void MainWindow::on_pushButtonSub_clicked()
{
    old=ui->label_display->text().toInt(0,10);
    add=false;
    mul=false;
    sub=true;
    divis=false;
    ui->label_display->setText("0");
}


void MainWindow::on_pushButtonAdd_clicked()
{
    old=ui->label_display->text().toInt(0,10);
    add=true;
    mul=false;
    sub=false;
    divis=false;
    ui->label_display->setText("0");
}

void MainWindow::on_pushButtonDiv_clicked()
{
    old=ui->label_display->text().toInt(0,10);
    add=false;
    mul=false;
    sub=false;
    divis=true;
    ui->label_display->setText("0");
}



void MainWindow::on_pushButtonEqual_clicked()
{
    int result=0;
    newval=ui->label_display->text().toInt(0,10);
    if(add==true)
        result=old + newval;
    else
        if(sub==true)
            result=old - newval;
    else
            if(mul==true)
                result=old * newval;
    else
                if(divis==true)
                    result=old / newval;
        ui->label_display->setText(QString::number(result,10));

}
