/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_chatbox
{
public:

    void setupUi(QDialog *chatbox)
    {
        if (chatbox->objectName().isEmpty())
            chatbox->setObjectName(QStringLiteral("chatbox"));
        chatbox->resize(1152, 853);

        retranslateUi(chatbox);

        QMetaObject::connectSlotsByName(chatbox);
    } // setupUi

    void retranslateUi(QDialog *chatbox)
    {
        chatbox->setWindowTitle(QApplication::translate("chatbox", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chatbox: public Ui_chatbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
