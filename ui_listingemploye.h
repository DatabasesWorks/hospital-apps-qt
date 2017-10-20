/********************************************************************************
** Form generated from reading UI file 'listingemploye.ui'
**
** Created: Tue 16. Dec 03:01:49 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTINGEMPLOYE_H
#define UI_LISTINGEMPLOYE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_listingEmploye
{
public:
    QTableView *tableViewEmploye;

    void setupUi(QDialog *listingEmploye)
    {
        if (listingEmploye->objectName().isEmpty())
            listingEmploye->setObjectName(QString::fromUtf8("listingEmploye"));
        listingEmploye->resize(730, 599);
        tableViewEmploye = new QTableView(listingEmploye);
        tableViewEmploye->setObjectName(QString::fromUtf8("tableViewEmploye"));
        tableViewEmploye->setGeometry(QRect(0, 0, 731, 601));

        retranslateUi(listingEmploye);

        QMetaObject::connectSlotsByName(listingEmploye);
    } // setupUi

    void retranslateUi(QDialog *listingEmploye)
    {
        listingEmploye->setWindowTitle(QApplication::translate("listingEmploye", "Liste des employ\303\251s", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class listingEmploye: public Ui_listingEmploye {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTINGEMPLOYE_H
