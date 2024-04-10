#include "loginpage.h"
#include "ui_loginpage.h"
#include<QMessageBox>

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_clicked()
{
    //正确密码登录
    if(ui->lineEdit->text()=="hitwh")
    {
    emit sendloginok();
    this->close();
    }
    else
    {
    QMessageBox::warning(this,tr("登录失败"),tr("密码错误"),QMessageBox::Ok);
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
    }

}


void LoginPage::on_pushButton_2_clicked()
{
    exit(0);
}

