#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QODBC");//用odbc驱动
   db.setDatabaseName("test1");//odbc名
    db.setHostName("127.0.0.1");//主机地址
    if (!db.open("root", "root"))//用户名
    {
         QMessageBox::information(NULL, "err", "登陆失败", QMessageBox::Yes);

    }


    p_1.show();
    auto f=[&](){
        this->show();
    };
    connect(&p_1,&LoginPage::sendloginok,this,f);


    ui->treeWidget->setColumnCount(1);

    QStringList l;
    l<<"考生类别";
    QTreeWidgetItem *pf=new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pf);

    l.clear();
    l<<"数学类";
    QTreeWidgetItem *p1=new QTreeWidgetItem(pf,l);
    l.clear();
    l<<"物理类";
    QTreeWidgetItem *p2=new QTreeWidgetItem(pf,l);
    l.clear();
    l<<"文科类";
    QTreeWidgetItem *p3=new QTreeWidgetItem(pf,l);

    pf->addChild(p1);
    pf->addChild(p2);
    pf->addChild(p3);
    ui->treeWidget->expandAll();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    exit(0);
}


void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    //QTreeWidgetItem *item=item;
    if(item->text(column)=="数学类")
    {
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    }
    if(item->text(column)=="物理类")
    {
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }
    if(item->text(column)=="文科类")
    {
        ui->stackedWidget->setCurrentWidget(ui->page_4);
    }
}

//数学类刷新排序
void MainWindow::on_pushButton_9_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from mathgroup order by gmark desc,cmark desc"))
        {
            ui->tableWidget_3->clearContents();
            ui->tableWidget_3->setRowCount(0);


            while(query.next())
            {
                int rowCount = ui->tableWidget_3->rowCount();


                ui->tableWidget_3->insertRow(rowCount);


                QTableWidgetItem *columnItem0 = new QTableWidgetItem(
                    query.value(0).toString());
                QTableWidgetItem *columnItem1 = new QTableWidgetItem(
                    query.value(1).toString());
                QTableWidgetItem *columnItem2 = new QTableWidgetItem(
                    query.value(2).toString());
                QTableWidgetItem *columnItem3 = new QTableWidgetItem(
                    query.value(3).toString());

                ui->tableWidget_3->setItem(rowCount,0, columnItem0);
                ui->tableWidget_3->setItem(rowCount,1, columnItem1);
                ui->tableWidget_3->setItem(rowCount,2, columnItem2);
                ui->tableWidget_3->setItem(rowCount,3, columnItem3);
            }
        }
    }
}

//数学类新增
void MainWindow::on_pushButton_14_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        QString id=ui->lineEdit_3->text();
        QString name=ui->lineEdit_12->text();
        int gmark=ui->lineEdit_11->text().toInt();
        int cmark=ui->lineEdit_13->text().toInt();
        if(query.exec(QString("insert into mathgroup values('%1','%2',%3,%4)").arg(id).arg(name).arg(gmark).arg(cmark)))
        {
            ui->lineEdit_3->clear();
            ui->lineEdit_12->clear();
            ui->lineEdit_11->clear();
            ui->lineEdit_13->clear();
        }
    }
}

//物理类新增
void MainWindow::on_pushButton_16_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        QString id=ui->lineEdit_2->text();
        QString name=ui->lineEdit_9->text();
        int gmark=ui->lineEdit_8->text().toInt();
        int cmark=ui->lineEdit_10->text().toInt();
        if(query.exec(QString("insert into physicsgroup values('%1','%2',%3,%4)").arg(id).arg(name).arg(gmark).arg(cmark)))
        {
            ui->lineEdit_2->clear();
            ui->lineEdit_9->clear();
            ui->lineEdit_8->clear();
            ui->lineEdit_10->clear();
        }
    }
}

//物理类刷新
void MainWindow::on_pushButton_5_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from physicsgroup order by gmark desc,cmark desc"))
        {
            ui->tableWidget_2->clearContents();
            ui->tableWidget_2->setRowCount(0);


            while(query.next())
            {
                int rowCount = ui->tableWidget_2->rowCount();


                ui->tableWidget_2->insertRow(rowCount);


                QTableWidgetItem *columnItem0 = new QTableWidgetItem(
                    query.value(0).toString());
                QTableWidgetItem *columnItem1 = new QTableWidgetItem(
                    query.value(1).toString());
                QTableWidgetItem *columnItem2 = new QTableWidgetItem(
                    query.value(2).toString());
                QTableWidgetItem *columnItem3 = new QTableWidgetItem(
                    query.value(3).toString());

                ui->tableWidget_2->setItem(rowCount,0, columnItem0);
                ui->tableWidget_2->setItem(rowCount,1, columnItem1);
                ui->tableWidget_2->setItem(rowCount,2, columnItem2);
                ui->tableWidget_2->setItem(rowCount,3, columnItem3);
            }
        }
    }
}



//文科新增
void MainWindow::on_pushButton_3_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        QString id=ui->lineEdit_5->text();
        QString name=ui->lineEdit->text();
        int gmark=ui->lineEdit_6->text().toInt();
        int cmark=ui->lineEdit_7->text().toInt();
        if(query.exec(QString("insert into literature values('%1','%2',%3,%4)").arg(id).arg(name).arg(gmark).arg(cmark)))
        {
            ui->lineEdit_5->clear();
            ui->lineEdit->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
        }
    }
}

//文科刷新
void MainWindow::on_pushButton_2_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from literature order by gmark desc,cmark desc"))
        {
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);


            while(query.next())
            {
                int rowCount = ui->tableWidget->rowCount();


                ui->tableWidget->insertRow(rowCount);


                QTableWidgetItem *columnItem0 = new QTableWidgetItem(
                    query.value(0).toString());
                QTableWidgetItem *columnItem1 = new QTableWidgetItem(
                    query.value(1).toString());
                QTableWidgetItem *columnItem2 = new QTableWidgetItem(
                    query.value(2).toString());
                QTableWidgetItem *columnItem3 = new QTableWidgetItem(
                    query.value(3).toString());

                ui->tableWidget->setItem(rowCount,0, columnItem0);
                ui->tableWidget->setItem(rowCount,1, columnItem1);
                ui->tableWidget->setItem(rowCount,2, columnItem2);
                ui->tableWidget->setItem(rowCount,3, columnItem3);
            }
        }
    }
}

//数学类删除
void MainWindow::on_pushButton_10_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        QString id=ui->lineEdit_3->text();


        if(query.exec(QString("delete from mathgroup where id='%1'").arg(id)))
        {
            ui->lineEdit_3->clear();

        }
    }
}

//物理类删除
void MainWindow::on_pushButton_7_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        QString id=ui->lineEdit_2->text();

        if(query.exec(QString("delete from physicsgroup where id='%1'").arg(id)))
        {
            ui->lineEdit_2->clear();

        }
    }
}

//文科类删除
void MainWindow::on_pushButton_17_clicked()
{
    if(true == db.open())
    {
        QSqlQuery query(db);
        QString id=ui->lineEdit_5->text();

        if(query.exec(QString("delete from literature where id='%1'").arg(id)))
        {
            ui->lineEdit_5->clear();

        }
    }
}

