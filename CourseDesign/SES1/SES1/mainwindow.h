#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"loginpage.h"
#include<QMessageBox>
#include <QApplication>
#include<QsqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include<QTreeWidget>

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
    void on_pushButton_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::MainWindow *ui;
    LoginPage p_1;
    QSqlDatabase db ;
};
#endif // MAINWINDOW_H
