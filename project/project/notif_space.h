#ifndef NOTIF_SPACE_H
#define NOTIF_SPACE_H
#include"client.h"
#include <QDialog>
#include"client_profil.h"
#include"client_interface.h"
#include"review.h"

namespace Ui {
class notif_space;
}

class notif_space : public QDialog
{
    Q_OBJECT

public:
    explicit notif_space(QWidget *parent = nullptr);
    ~notif_space();
    QString histo;

private slots:
    void on_reply_clicked();

private:
    Ui::notif_space *ui;

};

#endif // NOTIF_SPACE_H
