#include "client_profil.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include <iostream>
#include"client_interface.h"

using namespace std;

client_profil::client_profil()
{
cuser=""; cpass="";
}

bool client_profil::add_client_profil(){
    QSqlQuery query;
     query.prepare( "INSERT INTO client_user (cusername, cpassword) "
                       "VALUES (:cusername, :cpassword)" );
         query.bindValue(":cusername",cuser);
         query.bindValue(":cpassword",cpass);


    return query.exec();

}




QString client_profil::getcuser(){return  cuser;}
QString client_profil::getcpass(){return cpass;}

void client_profil::setcuser(QString cuser){this->cuser=cuser;}
void client_profil::setcpass(QString cpass){this->cpass=cpass;}

