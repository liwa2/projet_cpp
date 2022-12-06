#ifndef REPLYY_H
#define REPLYY_H
#include <string.h>
#include <iostream>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<vector>
#include <QSqlQueryModel>
#include <QList>
#include <list>
#include "dialog.h"

class replyy
{

private:
     QString reply;



public:
    replyy();

    replyy(QString reply ){

        this->reply=reply;

     }
    bool add_reply();
    QSqlQueryModel* afficher_rep();
};

#endif // REPLYY_H
