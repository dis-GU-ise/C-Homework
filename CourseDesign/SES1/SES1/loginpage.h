#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void sendloginok();
private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
