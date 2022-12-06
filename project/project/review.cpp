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

review::review()
{
nom=""; revieww="",role="";
}

bool review::add_review(){
    QSqlQuery query;
     query.prepare( "INSERT INTO review (nom,revieww,role) "
                       "VALUES (:nom,:revieww,:role)" );
         query.bindValue(":nom",nom);
         query.bindValue(":revieww",revieww);
         query.bindValue(":role","client");

    return query.exec();

}

QSqlQueryModel* review::afficher_rev(){

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from review order by nom ASC ");
    return model;



}

QString review::getnom(){return  nom;}
QString review::getrevieww(){return revieww;}
QString review::getrole(){return  role;}

void review::setnom(QString nom){this->nom=nom;}
void review::setrevieww(QString revieww){this->revieww=revieww;}
void review::setrole(QString role){this->role=role;}
