/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Tue 16. Dec 03:35:43 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *frame_sigin;
    QPushButton *pushButton;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLabel *label_username_icone;
    QLabel *label_password_icone;
    QLabel *label_mainIcon;
    QPushButton *pushButton_facebook;
    QPushButton *pushButton_twitter;
    QLabel *label_needHelp;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(321, 409);
        frame_sigin = new QFrame(Login);
        frame_sigin->setObjectName(QString::fromUtf8("frame_sigin"));
        frame_sigin->setGeometry(QRect(-40, 0, 391, 411));
        frame_sigin->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(frame_sigin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 300, 261, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"#pushButton {\n"
"	-moz-box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	-webkit-box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	background:-webkit-gradient(linear, left top, left bottom, color-stop(0.05, #ffffff), color-stop(1, #f6f6f6));\n"
"	background:-moz-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-webkit-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-o-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-ms-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:linear-gradient(to bottom, #ffffff 5%, #f6f6f6 100%);\n"
"	background-color:#ffffff;\n"
"	-moz-border-radius:6px;\n"
"	-webkit-border-radius:6px;\n"
"	border-radius:6px;\n"
"	border:1px solid #dcdcdc;\n"
"	display:inline-block;\n"
"	cursor:pointer;\n"
"	color:#666666;\n"
"	font-family:arial;\n"
"	font-size:15px;\n"
"	font-weight:bold;\n"
"	padding:6px 24px;\n"
"	text-decoration:none;\n"
"	text-shadow:0px 1px 0px #ffffff;\n"
"}\n"
"#pus"
                        "hButton:hover {\n"
"	background:-webkit-gradient(linear, left top, left bottom, color-stop(0.05, #f6f6f6), color-stop(1, #ffffff));\n"
"	background:-moz-linear-gradient(top, #f6f6f6 5%, #ffffff 100%);\n"
"	background:-webkit-linear-gradient(top, #f6f6f6 5%, #ffffff 100%);\n"
"	background:-o-linear-gradient(top, #f6f6f6 5%, #ffffff 100%);\n"
"	background:-ms-linear-gradient(top, #f6f6f6 5%, #ffffff 100%);\n"
"	background:linear-gradient(to bottom, #f6f6f6 5%, #ffffff 100%);\n"
"	background-color:#f6f6f6;\n"
"}\n"
"#pushButton:active {\n"
"	position:relative;\n"
"	top:1px;\n"
"}\n"
""));
        lineEdit_username = new QLineEdit(frame_sigin);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(70, 200, 261, 41));
        lineEdit_username->setStyleSheet(QString::fromUtf8("#lineEdit_username{\n"
"	-moz-box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	-webkit-box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	background:-webkit-gradient(linear, left top, left bottom, color-stop(0.05, #ffffff), color-stop(1, #f6f6f6));\n"
"	background:-moz-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-webkit-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-o-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-ms-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:linear-gradient(to bottom, #ffffff 5%, #f6f6f6 100%);\n"
"	background-color:#ffffff;\n"
"	-moz-border-radius:6px;\n"
"	-webkit-border-radius:6px;\n"
"	border-radius:6px;\n"
"	border:1px solid #dcdcdc;\n"
"	display:inline-block;\n"
"	cursor:pointer;\n"
"	color:#666666;\n"
"	font-family:arial;\n"
"	font-size:15px;\n"
"	padding:5px 28px;\n"
"	text-decoration:none;\n"
"	text-shadow:0px 1px 0px #ffffff;\n"
"}"));
        lineEdit_username->setEchoMode(QLineEdit::Normal);
        lineEdit_username->setCursorPosition(0);
        lineEdit_username->setReadOnly(false);
        lineEdit_password = new QLineEdit(frame_sigin);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(70, 250, 261, 41));
        lineEdit_password->setStyleSheet(QString::fromUtf8("#lineEdit_password{\n"
"\n"
"	-moz-box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	-webkit-box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	box-shadow:inset 0px 1px 0px 0px #ffffff;\n"
"	background:-webkit-gradient(linear, left top, left bottom, color-stop(0.05, #ffffff), color-stop(1, #f6f6f6));\n"
"	background:-moz-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-webkit-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-o-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:-ms-linear-gradient(top, #ffffff 5%, #f6f6f6 100%);\n"
"	background:linear-gradient(to bottom, #ffffff 5%, #f6f6f6 100%);\n"
"	background-color:#ffffff;\n"
"	-moz-border-radius:6px;\n"
"	-webkit-border-radius:6px;\n"
"	border-radius:6px;\n"
"	border:1px solid #dcdcdc;\n"
"	display:inline-block;\n"
"	cursor:pointer;\n"
"	color:#666666;\n"
"	font-family:arial;\n"
"	font-size:15px;\n"
"	padding:5px 28px;\n"
"	text-decoration:none;\n"
"	text-shadow:0px 1px 0px #ffffff;\n"
"}\n"
"\n"
"\n"
""));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        label_username_icone = new QLabel(frame_sigin);
        label_username_icone->setObjectName(QString::fromUtf8("label_username_icone"));
        label_username_icone->setGeometry(QRect(80, 210, 31, 21));
        label_password_icone = new QLabel(frame_sigin);
        label_password_icone->setObjectName(QString::fromUtf8("label_password_icone"));
        label_password_icone->setGeometry(QRect(80, 260, 31, 21));
        label_mainIcon = new QLabel(frame_sigin);
        label_mainIcon->setObjectName(QString::fromUtf8("label_mainIcon"));
        label_mainIcon->setGeometry(QRect(30, 30, 341, 131));
        pushButton_facebook = new QPushButton(frame_sigin);
        pushButton_facebook->setObjectName(QString::fromUtf8("pushButton_facebook"));
        pushButton_facebook->setGeometry(QRect(70, 350, 31, 31));
        pushButton_facebook->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_facebook->setStyleSheet(QString::fromUtf8("border-image: url(:/facebook_icon.png);"));
        pushButton_facebook->setCheckable(false);
        pushButton_twitter = new QPushButton(frame_sigin);
        pushButton_twitter->setObjectName(QString::fromUtf8("pushButton_twitter"));
        pushButton_twitter->setGeometry(QRect(110, 350, 31, 31));
        pushButton_twitter->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_twitter->setStyleSheet(QString::fromUtf8("border-image: url(:/twitter_icon.png);"));
        label_needHelp = new QLabel(frame_sigin);
        label_needHelp->setObjectName(QString::fromUtf8("label_needHelp"));
        label_needHelp->setGeometry(QRect(250, 360, 81, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        label_needHelp->setFont(font);
        label_needHelp->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        lineEdit_username->setText(QString());
        lineEdit_password->setText(QString());
        label_username_icone->setText(QApplication::translate("Login", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_password_icone->setText(QApplication::translate("Login", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_mainIcon->setText(QApplication::translate("Login", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_facebook->setText(QString());
        pushButton_facebook->setShortcut(QString());
        pushButton_twitter->setText(QString());
        label_needHelp->setText(QApplication::translate("Login", "Need help ?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
