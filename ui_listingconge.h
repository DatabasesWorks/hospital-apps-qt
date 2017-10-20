/********************************************************************************
** Form generated from reading UI file 'listingconge.ui'
**
** Created: Tue 16. Dec 03:01:49 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTINGCONGE_H
#define UI_LISTINGCONGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ListingConge
{
public:
    QTableView *tableViewConge;

    void setupUi(QDialog *ListingConge)
    {
        if (ListingConge->objectName().isEmpty())
            ListingConge->setObjectName(QString::fromUtf8("ListingConge"));
        ListingConge->resize(730, 600);
        tableViewConge = new QTableView(ListingConge);
        tableViewConge->setObjectName(QString::fromUtf8("tableViewConge"));
        tableViewConge->setGeometry(QRect(0, 0, 731, 601));

        retranslateUi(ListingConge);

        QMetaObject::connectSlotsByName(ListingConge);
    } // setupUi

    void retranslateUi(QDialog *ListingConge)
    {
        ListingConge->setWindowTitle(QApplication::translate("ListingConge", "Liste des cong\303\251s", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ListingConge: public Ui_ListingConge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTINGCONGE_H
