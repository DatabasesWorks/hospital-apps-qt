/********************************************************************************
** Form generated from reading UI file 'statistiques.ui'
**
** Created: Tue 16. Dec 02:59:51 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUES_H
#define UI_STATISTIQUES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Statistiques
{
public:
    QCustomPlot *widget_Plot;

    void setupUi(QDialog *Statistiques)
    {
        if (Statistiques->objectName().isEmpty())
            Statistiques->setObjectName(QString::fromUtf8("Statistiques"));
        Statistiques->resize(730, 602);
        widget_Plot = new QCustomPlot(Statistiques);
        widget_Plot->setObjectName(QString::fromUtf8("widget_Plot"));
        widget_Plot->setGeometry(QRect(10, 10, 711, 581));

        retranslateUi(Statistiques);

        QMetaObject::connectSlotsByName(Statistiques);
    } // setupUi

    void retranslateUi(QDialog *Statistiques)
    {
        Statistiques->setWindowTitle(QApplication::translate("Statistiques", "Statistiques", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Statistiques: public Ui_Statistiques {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUES_H
