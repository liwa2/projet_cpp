#include "connexion.h"

connexion::connexion()
{}

bool connexion::ouvrirConnexion()
{
    db=QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("projet2A");//inserer le nom de la source de donnÃ©es ODBC
    db.setUserName("liwa");//inserer nom de l'utilisateur
    db.setPassword("liwa");//inserer mot de passe de cet utilisateur


if (db.open())
return true;
    return  false;
}

void connexion::fermerConnexion()
{db.close();}
