#ifndef HISTORIQUE_H
#define HISTORIQUE_H
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



class historique
{
private:
     QString add_c,del_c,modif_c;
public:
    historique();
    historique(QString add_c,QString del_c,QString modif_c  ){

        this->add_c=add_c;
        this->del_c=del_c;
        this->modif_c=modif_c;

     }

   bool addh();
   //void affiche_add(&QString add_c , &QString del_c ,&QString modif_c);

};

#endif // HISTORIQUE_H
