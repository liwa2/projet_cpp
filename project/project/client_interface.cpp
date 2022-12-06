#include "client_interface.h"
#include "ui_client_interface.h"
#include "client.h"
#include "client_profil.h"
#include "review.h"
#include "replyy.h"

client_interface::client_interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_interface)
{
    ui->setupUi(this);

    replyy r;
    QSqlQueryModel *model =r.afficher_rep();
    ui->reppp->setModel(model);
}

client_interface::~client_interface()
{
    delete ui;
}

void client_interface::on_pushButton_clicked()
{


    QString revieww=ui->reviewSend->text();
    QString nom=ui->name_send->text();

    review c(revieww,nom,"client");
    c.add_review();



}

