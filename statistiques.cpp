#include "statistiques.h"
#include "ui_statistiques.h"
#include "employe.h"
#include "employeui.h"
#include <QVector>
Statistiques::Statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistiques)
{
    ui->setupUi(this);

    QVector <double> x(100),y(100);

    vector <QString> vectStat;
    vectStat=statClass.GetVectStat();


    for (int i=0;i<vectStat.size();i++)
    {
        qDebug()<<vectStat[i];
    }

    int j=-1;


    for (int i=0;i<vectStat.size();i++)
    {
        j++;
        y[j]=j;
        QString timeString=vectStat[i];
        QDateTime time=QDateTime::fromString(timeString,"dd/MM/yyyy");
        qDebug()<<time;
        x[j]=time.toTime_t();
        qDebug()<<x[j];
    }









    ui->widget_Plot->addGraph();
    ui->widget_Plot->graph(0)->setData(x,y);
    ui->widget_Plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->widget_Plot->xAxis->setDateTimeFormat("dd/MM/yyyy");
    ui->widget_Plot->xAxis->setLabel("Date d'embauche");
    ui->widget_Plot->yAxis->setLabel("Nombre des employés");
    ui->widget_Plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));

    ui->widget_Plot->xAxis->setRange(x.first(),x.last());
    ui->widget_Plot->yAxis->setRange(0,10);




}

Statistiques::~Statistiques()
{
    delete ui;
}
