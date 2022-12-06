/********************************************************************************
** Form generated from reading UI file 'client_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_INTERFACE_H
#define UI_CLIENT_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_client_interface
{
public:
    QPushButton *pushButton;
    QLineEdit *reviewSend;
    QTableView *reppp;
    QLineEdit *name_send;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *client_interface)
    {
        if (client_interface->objectName().isEmpty())
            client_interface->setObjectName(QStringLiteral("client_interface"));
        client_interface->resize(1062, 808);
        QFont font;
        font.setPointSize(14);
        client_interface->setFont(font);
        pushButton = new QPushButton(client_interface);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(690, 730, 331, 34));
        reviewSend = new QLineEdit(client_interface);
        reviewSend->setObjectName(QStringLiteral("reviewSend"));
        reviewSend->setGeometry(QRect(360, 560, 661, 91));
        reppp = new QTableView(client_interface);
        reppp->setObjectName(QStringLiteral("reppp"));
        reppp->setGeometry(QRect(360, 100, 651, 331));
        reppp->setStyleSheet(QLatin1String("background:#EDEDED;\n"
"color:#6563FF;\n"
"font-size:16px;\n"
""));
        name_send = new QLineEdit(client_interface);
        name_send->setObjectName(QStringLiteral("name_send"));
        name_send->setGeometry(QRect(360, 500, 113, 25));
        label = new QLabel(client_interface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 460, 69, 20));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);
        label_2 = new QLabel(client_interface);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 530, 211, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(client_interface);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-240, -320, 1461, 1161));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/wp8552433-white-pc-wallpapers.jpg")));
        label_3->raise();
        pushButton->raise();
        reviewSend->raise();
        reppp->raise();
        name_send->raise();
        label->raise();
        label_2->raise();

        retranslateUi(client_interface);

        QMetaObject::connectSlotsByName(client_interface);
    } // setupUi

    void retranslateUi(QDialog *client_interface)
    {
        client_interface->setWindowTitle(QApplication::translate("client_interface", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("client_interface", "send", Q_NULLPTR));
        label->setText(QApplication::translate("client_interface", "name :", Q_NULLPTR));
        label_2->setText(QApplication::translate("client_interface", "your comment :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class client_interface: public Ui_client_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_INTERFACE_H
