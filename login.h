#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>
#include <QDebug>
#include <QPainter>
#include <QImage>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QFileInfo>
#include "employeui.h"


namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Login *ui;





    QSqlDatabase db;

};

#endif // LOGIN_H
