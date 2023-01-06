#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qstackedwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Issue_clicked();

    void on_pushButton_issue_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_Return_clicked();

    void on_pushButton_serach_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_back_3_clicked();

    void on_checkBox_return_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
