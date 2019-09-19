/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 10 10:44:48 2019
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *client;
    QPushButton *download;
    QScrollBar *roll;
    QPushButton *upload;
    QListWidget *server;
    QLabel *clientdir;
    QLineEdit *client_edit;
    QLabel *serverdir;
    QLineEdit *server_edit;
    QLabel *serverip;
    QLineEdit *ip_edit;
    QLabel *username;
    QLineEdit *name_edit;
    QLabel *passwd;
    QLineEdit *pass_edit;
    QLabel *port;
    QLineEdit *port_edit;
    QPushButton *connect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 532);
        Widget->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background-color: rgb(240,245,229);\n"
"}\n"
"QPushButton\n"
"{\n"
"background-color:rgb(198,223,200);\n"
"}"));
        client = new QListWidget(Widget);
        client->setObjectName(QString::fromUtf8("client"));
        client->setGeometry(QRect(20, 160, 350, 350));
        download = new QPushButton(Widget);
        download->setObjectName(QString::fromUtf8("download"));
        download->setGeometry(QRect(390, 260, 40, 30));
        roll = new QScrollBar(Widget);
        roll->setObjectName(QString::fromUtf8("roll"));
        roll->setGeometry(QRect(370, 160, 20, 350));
        roll->setOrientation(Qt::Vertical);
        upload = new QPushButton(Widget);
        upload->setObjectName(QString::fromUtf8("upload"));
        upload->setGeometry(QRect(390, 380, 40, 30));
        server = new QListWidget(Widget);
        server->setObjectName(QString::fromUtf8("server"));
        server->setGeometry(QRect(430, 160, 350, 350));
        clientdir = new QLabel(Widget);
        clientdir->setObjectName(QString::fromUtf8("clientdir"));
        clientdir->setGeometry(QRect(20, 100, 60, 30));
        clientdir->setStyleSheet(QString::fromUtf8(""));
        client_edit = new QLineEdit(Widget);
        client_edit->setObjectName(QString::fromUtf8("client_edit"));
        client_edit->setGeometry(QRect(80, 100, 290, 30));
        serverdir = new QLabel(Widget);
        serverdir->setObjectName(QString::fromUtf8("serverdir"));
        serverdir->setGeometry(QRect(430, 100, 65, 30));
        serverdir->setStyleSheet(QString::fromUtf8(""));
        server_edit = new QLineEdit(Widget);
        server_edit->setObjectName(QString::fromUtf8("server_edit"));
        server_edit->setGeometry(QRect(495, 100, 285, 30));
        serverip = new QLabel(Widget);
        serverip->setObjectName(QString::fromUtf8("serverip"));
        serverip->setGeometry(QRect(20, 30, 60, 30));
        serverip->setStyleSheet(QString::fromUtf8(""));
        ip_edit = new QLineEdit(Widget);
        ip_edit->setObjectName(QString::fromUtf8("ip_edit"));
        ip_edit->setGeometry(QRect(80, 30, 120, 30));
        username = new QLabel(Widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(220, 30, 68, 30));
        username->setStyleSheet(QString::fromUtf8(""));
        name_edit = new QLineEdit(Widget);
        name_edit->setObjectName(QString::fromUtf8("name_edit"));
        name_edit->setGeometry(QRect(290, 30, 113, 30));
        passwd = new QLabel(Widget);
        passwd->setObjectName(QString::fromUtf8("passwd"));
        passwd->setGeometry(QRect(430, 30, 54, 30));
        passwd->setStyleSheet(QString::fromUtf8(""));
        pass_edit = new QLineEdit(Widget);
        pass_edit->setObjectName(QString::fromUtf8("pass_edit"));
        pass_edit->setGeometry(QRect(485, 30, 113, 30));
        pass_edit->setEchoMode(QLineEdit::Password);
        port = new QLabel(Widget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(610, 30, 33, 30));
        port->setStyleSheet(QString::fromUtf8(""));
        port_edit = new QLineEdit(Widget);
        port_edit->setObjectName(QString::fromUtf8("port_edit"));
        port_edit->setGeometry(QRect(645, 30, 50, 30));
        connect = new QPushButton(Widget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(700, 30, 78, 30));
        connect->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        download->setText(QApplication::translate("Widget", "<<", 0, QApplication::UnicodeUTF8));
        upload->setText(QApplication::translate("Widget", ">>", 0, QApplication::UnicodeUTF8));
        clientdir->setText(QApplication::translate("Widget", "clientdir:", 0, QApplication::UnicodeUTF8));
        serverdir->setText(QApplication::translate("Widget", "serverdir:", 0, QApplication::UnicodeUTF8));
        serverip->setText(QApplication::translate("Widget", "serverip:", 0, QApplication::UnicodeUTF8));
        ip_edit->setText(QApplication::translate("Widget", "172.20.10.2", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("Widget", "username:", 0, QApplication::UnicodeUTF8));
        name_edit->setText(QApplication::translate("Widget", "zhizhen", 0, QApplication::UnicodeUTF8));
        passwd->setText(QApplication::translate("Widget", "passwd:", 0, QApplication::UnicodeUTF8));
        pass_edit->setText(QApplication::translate("Widget", "zzxx", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("Widget", "port:", 0, QApplication::UnicodeUTF8));
        port_edit->setText(QApplication::translate("Widget", "21", 0, QApplication::UnicodeUTF8));
        connect->setText(QApplication::translate("Widget", "connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
