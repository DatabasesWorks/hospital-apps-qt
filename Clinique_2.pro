#-------------------------------------------------
#
# Project created by QtCreator 2014-11-15T21:09:18
#
#-------------------------------------------------

QT       += core gui sql widgets printsupport


TARGET = Clinique_2
TEMPLATE = app


SOURCES += main.cpp\
    employe.cpp \
    employeui.cpp \
    login.cpp \
    qcustomplot.cpp \
    statistiques.cpp \
    conge.cpp \
    pointage.cpp \
    statclass.cpp \
    paiement.cpp \
    listingpaiement.cpp \
    listingemploye.cpp \
    listingconge.cpp

HEADERS  += \
    employe.h \
    employeui.h \
    login.h \
    qcustomplot.h \
    statistiques.h \
    conge.h \
    paiement.h \
    pointage.h \
    connection.h \
    statclass.h \
    listingpaiement.h \
    listingemploye.h \
    listingconge.h \
    ui_mainwindow.h

FORMS    += \
    employeui.ui \
    login.ui \
    statistiques.ui \
    listingpaiement.ui \
    listingemploye.ui \
    listingconge.ui

RESOURCES += \
    Icon.qrc

OTHER_FILES += \
    facebook_icon.png
