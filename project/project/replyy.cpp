#include "replyy.h"
#include "review.h"
#include "client_profil.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include <iostream>
#include"client_interface.h"
#include"notif_space.h"

replyy::replyy()
{
reply="";
}

bool replyy::add_reply(){
    QSqlQuery query;
     query.prepare( "INSERT INTO reply_admin (reply) "
                       "VALUES (:reply)" );
         query.bindValue(":reply",reply);


    return query.exec();

}


QSqlQueryModel* replyy::afficher_rep(){

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from reply_admin order by reply ASC ");
    return model;



}
