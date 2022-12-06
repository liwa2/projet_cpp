#ifndef REVIEW_H
#define REVIEW_H
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlDatabase>


class review
{

private:
     QString nom,revieww,role;



public:
    review();

    review(QString revieww ,QString nom,QString role ){

        this->revieww=revieww;
        this->nom=nom;
        this->role=role;
     }
    bool add_review();
    QSqlQueryModel* afficher_rev();



    QString getnom();
    QString getrevieww();
    QString getrole();
    void setnom(QString);
    void setrevieww(QString);
    void setrole(QString);
};

#endif // REVIEW_H
