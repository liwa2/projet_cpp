/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_2;
    QStackedWidget *loginWidgets;
    QWidget *page;
    QFrame *frame;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLineEdit *username_line;
    QLineEdit *password_line;
    QLabel *label_2;
    QWidget *page_2;
    QFrame *frame_4;
    QLabel *label;
    QLineEdit *username_signup_line;
    QLineEdit *password_signup_line;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1210, 602);
        MainWindow->setStyleSheet(QLatin1String("*{\n"
"font-family:century gothic ;\n"
"font-size:24px;\n"
"\n"
"\n"
"}\n"
"QMainWindow{\n"
"background:white;\n"
"border-radius:15px ;\n"
"}\n"
"QFrame{\n"
"background-color:#a9a8ff;\n"
"border-radius:15px ;\n"
"}\n"
"\n"
"#loginWidgets{\n"
"background:white;\n"
"border-radius:15px ;\n"
"box-shadow: 10px 10px;\n"
"}\n"
"\n"
"QToolButton{\n"
"background:white;\n"
"border-radius:60px;\n"
"}\n"
"QLabel{\n"
"color:black;\n"
"}\n"
"QPushButton{\n"
"color:#918FFF;\n"
"background:white;\n"
"border-radius:15px ;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color:#6563FF;\n"
"background:#EBEBEB;\n"
"border-radius:15px ;\n"
"}\n"
"QLineEdit{\n"
"background:transparent;\n"
"border-radius:14px;\n"
"border:none;\n"
"color:white;\n"
"border-bottom:1px solid white;\n"
"}\n"
"QLineEdit:hover{\n"
"color:black;\n"
"border-bottom:1px solid black;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 20, 601, 531));
        frame_2->setStyleSheet(QLatin1String("background-image: url(:/login res/loggooo.png);\n"
"border-radius:15px;\n"
"  box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        loginWidgets = new QStackedWidget(centralwidget);
        loginWidgets->setObjectName(QStringLiteral("loginWidgets"));
        loginWidgets->setGeometry(QRect(610, 10, 591, 541));
        loginWidgets->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        frame = new QFrame(page);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 571, 531));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 400, 141, 41));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 400, 141, 41));
        username_line = new QLineEdit(frame);
        username_line->setObjectName(QStringLiteral("username_line"));
        username_line->setGeometry(QRect(80, 230, 211, 41));
        password_line = new QLineEdit(frame);
        password_line->setObjectName(QStringLiteral("password_line"));
        password_line->setGeometry(QRect(80, 310, 211, 41));
        password_line->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 130, 171, 61));
        label_2->setStyleSheet(QLatin1String("font-size:40px;\n"
"font-weight: 700;\n"
"color:white;"));
        loginWidgets->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        frame_4 = new QFrame(page_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 10, 571, 531));
        frame_4->setStyleSheet(QStringLiteral(""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 130, 171, 61));
        label->setStyleSheet(QLatin1String("font-size:40px;\n"
"font-weight: 700;\n"
"color:white;"));
        username_signup_line = new QLineEdit(frame_4);
        username_signup_line->setObjectName(QStringLiteral("username_signup_line"));
        username_signup_line->setGeometry(QRect(80, 230, 211, 41));
        password_signup_line = new QLineEdit(frame_4);
        password_signup_line->setObjectName(QStringLiteral("password_signup_line"));
        password_signup_line->setGeometry(QRect(80, 310, 211, 41));
        password_signup_line->setEchoMode(QLineEdit::Password);
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 400, 141, 41));
        pushButton_4 = new QPushButton(frame_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 400, 51, 41));
        QIcon icon;
        icon.addFile(QStringLiteral(":/feather (3)/arrow-left.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(28, 28));
        loginWidgets->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1210, 35));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        loginWidgets->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Sign up", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        username_line->setPlaceholderText(QApplication::translate("MainWindow", "User name", Q_NULLPTR));
        password_line->setText(QString());
        password_line->setPlaceholderText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Log in", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Sign up", Q_NULLPTR));
        username_signup_line->setPlaceholderText(QApplication::translate("MainWindow", "User name", Q_NULLPTR));
        password_signup_line->setPlaceholderText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Sign up", Q_NULLPTR));
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
