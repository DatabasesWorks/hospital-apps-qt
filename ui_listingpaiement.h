/********************************************************************************
** Form generated from reading UI file 'listingpaiement.ui'
**
** Created: Tue 16. Dec 03:01:49 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTINGPAIEMENT_H
#define UI_LISTINGPAIEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ListingPaiement
{
public:
    QTableView *tableViewPaiment;

    void setupUi(QDialog *ListingPaiement)
    {
        if (ListingPaiement->objectName().isEmpty())
            ListingPaiement->setObjectName(QString::fromUtf8("ListingPaiement"));
        ListingPaiement->resize(723, 593);
        tableViewPaiment = new QTableView(ListingPaiement);
        tableViewPaiment->setObjectName(QString::fromUtf8("tableViewPaiment"));
        tableViewPaiment->setGeometry(QRect(0, 0, 731, 601));

        retranslateUi(ListingPaiement);

        QMetaObject::connectSlotsByName(ListingPaiement);
    } // setupUi

    void retranslateUi(QDialog *ListingPaiement)
    {
        ListingPaiement->setWindowTitle(QApplication::translate("ListingPaiement", "Liste des fiches de paie", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ListingPaiement: public Ui_ListingPaiement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTINGPAIEMENT_H
