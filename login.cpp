#include "login.h"
#include "ui_login.h"
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix("password_icone.jpg"),pix2("username_icone.jpg"),
            pixMain("fusion_ERP.png"),pixMainDie("fusion_ERP_die.png");
    ui->label_password_icone->setPixmap(pix);
    ui->label_username_icone->setPixmap(pix2);



    db = QSqlDatabase::addDatabase("QSQLITE");
    QFileInfo info_database("clinique.sqlite");
    if (info_database.isFile())
    {
        db.setDatabaseName("clinique.sqlite");
        if (db.open())
        {
            ui->label_mainIcon->setPixmap(pixMain);
        }

    }
    else
    {
        ui->label_mainIcon->setPixmap(pixMainDie);
    }



}




Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username,password;
    QSqlQuery qry;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    if (!db.isOpen()){


        qDebug()<<"Failed to open the database";
        return;
    }

    qry.prepare("Select * from Employe where login=:login");
    qry.bindValue(":login",username);
    qry.exec();
    while (qry.next())
    {
        if (username=="111111" && qry.value(3).toString()==password)
        {
            this->hide();
            employeui employe;
            employe.setModal(true);
            employe.exec();
            break;
        }









    }



}







