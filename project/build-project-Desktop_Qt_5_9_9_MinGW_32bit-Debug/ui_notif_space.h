/********************************************************************************
** Form generated from reading UI file 'notif_space.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIF_SPACE_H
#define UI_NOTIF_SPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_notif_space
{
public:
    QPushButton *reply;
    QLineEdit *writerep;
    QTableView *disp;
    QLabel *label;
    QPlainTextEdit *history;

    void setupUi(QDialog *notif_space)
    {
        if (notif_space->objectName().isEmpty())
            notif_space->setObjectName(QStringLiteral("notif_space"));
        notif_space->resize(1210, 845);
        reply = new QPushButton(notif_space);
        reply->setObjectName(QStringLiteral("reply"));
        reply->setGeometry(QRect(360, 590, 271, 34));
        QFont font;
        font.setPointSize(10);
        reply->setFont(font);
        writerep = new QLineEdit(notif_space);
        writerep->setObjectName(QStringLiteral("writerep"));
        writerep->setGeometry(QRect(10, 520, 621, 51));
        disp = new QTableView(notif_space);
        disp->setObjectName(QStringLiteral("disp"));
        disp->setGeometry(QRect(10, 60, 621, 441));
        disp->setStyleSheet(QLatin1String("background:#EDEDED;\n"
"color:#6563FF;\n"
"font-size:16px;\n"
""));
        label = new QLabel(notif_space);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-380, -250, 1621, 1101));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/wp8552433-white-pc-wallpapers.jpg")));
        history = new QPlainTextEdit(notif_space);
        history->setObjectName(QStringLiteral("history"));
        history->setGeometry(QRect(660, 60, 421, 601));
        label->raise();
        reply->raise();
        writerep->raise();
        disp->raise();
        history->raise();

        retranslateUi(notif_space);

        QMetaObject::connectSlotsByName(notif_space);
    } // setupUi

    void retranslateUi(QDialog *notif_space)
    {
        notif_space->setWindowTitle(QApplication::translate("notif_space", "notification", Q_NULLPTR));
        reply->setText(QApplication::translate("notif_space", "reply", Q_NULLPTR));
        label->setText(QString());
        history->setPlainText(QApplication::translate("notif_space", "history : \n"
"", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class notif_space: public Ui_notif_space {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIF_SPACE_H
