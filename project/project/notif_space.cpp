#include "notif_space.h"
#include "ui_notif_space.h"
#include "client.h"
#include "client_interface.h"
#include "client_profil.h"
#include "review.h"
#include "replyy.h"
#include "dialog.h"

notif_space::notif_space(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notif_space)
{
    ui->setupUi(this);

    review r;

    QSqlQueryModel *model =r.afficher_rev();
    ui->disp->setModel(model);

    ui->history->setPlainText("history :        "
                              "firas deleted a client");





}

notif_space::~notif_space()
{
    delete ui;
}

void notif_space::on_reply_clicked()
{
     QString reply=ui->writerep->text();
     replyy c(reply);
     c.add_reply();
}

