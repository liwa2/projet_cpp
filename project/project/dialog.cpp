 #include "dialog.h"
#include "ui_dialog.h"
#include "profil.h"
#include "client.h"
#include<QSqlQuery>
#include "payment.h"
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include "employee.h"
#include "reservation.h"
#include "accommodation.h"
#include "client_profil.h"
#include "client_interface.h"
#include "notif_space.h"

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->payment_bill_frame->setVisible(false);
    ui->payment_salary_frame->setVisible(false);
    ui->id_client_line->setValidator(new QIntValidator(0,999999999,this));
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_8_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM userr order by userr_id  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("userr_id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("username"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));

ui->tableView->setModel(model);
}


void Dialog::on_pushButton_9_clicked()
{
ui->stackedWidget->setCurrentIndex(6);

}

void Dialog::on_pushButton_clicked()//client
{
    ui->stackedWidget->setCurrentIndex(0);
    int vip=0,rest=0;
    client c2;

    c2.statpie(vip,rest);



    // pie chart
    QPieSeries *series1 = new QPieSeries();

     series1->append("vip",vip);

     series1->append("normal",rest);

     QChart * chart1=new QChart();

     chart1->addSeries(series1);

     chart1->setTitle("vip clients %");

     QChartView * chartView1=new QChartView(chart1);

     chartView1->setRenderHints(QPainter::Antialiasing);
     QVBoxLayout *layout1 = new QVBoxLayout(ui->piechart_client);
     layout1->addWidget(chartView1);
     //

     QBarSet *set0=new QBarSet("age");


         *set0 <<3<<2<<0<<1;


         QBarSeries *Series=new QBarSeries();
         Series->append(set0);


         QChart *chart=new QChart();
         chart->addSeries(Series);
         chart->setTitle("client age");
         //no animation
         chart->setAnimationOptions(QChart::AllAnimations);
         QStringList categories;
         categories<<"2013"<<"2014"<<"2015"<<"2016"<<"2017";
        QBarCategoryAxis *axis=new  QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        //chart->setAxisX(axis,Series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);


        QChartView *chartview=new QChartView(chart) ;
        chartview->setRenderHint(QPainter::Antialiasing);

        QVBoxLayout *layout2 = new QVBoxLayout(ui->chart_client);
        layout2->addWidget(chartview);

//afficher client
        QString order;
        if(ui->client_order_combobox->currentText()=="Id_client")
        {
         order="id_client";
        }
        if(ui->client_order_combobox->currentText()=="id_payment")
        {
         order="id_payment";

        }
        if(ui->client_order_combobox->currentText()=="age")
        {
         order="age";
        }
        if(ui->client_order_combobox->currentText()=="name")
        {
         order="name";
        }
        if(ui->client_order_combobox->currentText()=="first name")
        {
         order="first_name";
        }

        client c;
        QSqlQueryModel *model =c.afficher_client(order);
        ui->client_tableview->setModel(model);

}


void Dialog::on_pushButton_2_clicked()//payment
{
    ui->stackedWidget->setCurrentIndex(5);

    int bill,salary,s[4],b[4];
    payment p2;
    p2.satistic_1(bill,salary);
    p2.satistic_2(s,b);


     //PIE chart
    QPieSeries *series1 = new QPieSeries();

     series1->append("Revenue ",bill/1000);

     series1->append("Amount spending on employees ",salary/1000);

     QChart * chart1=new QChart();

     chart1->addSeries(series1);

     chart1->setTitle("stats");
     chart1->setAnimationOptions(QChart::AllAnimations);
     QChartView * chartView1=new QChartView(chart1);

     chartView1->setRenderHints(QPainter::Antialiasing);
     QVBoxLayout *layout1 = new QVBoxLayout(ui->piechart_payment);
     layout1->addWidget(chartView1);

     //chart

     QBarSet *set0=new QBarSet("Revenue");
         QBarSet *set1=new QBarSet("Amount spending on employees");

         *set0 <<b[0]/1000<<b[1]/1000<<b[2]/1000<<b[3]/1000;
         *set1 <<s[0]/1000<<s[1]/1000<<s[2]/1000<<s[3]/1000;


         QBarSeries *Series=new QBarSeries();
         Series->append(set0);
         Series->append(set1);

         QChart *chart=new QChart();
         chart->addSeries(Series);
         chart->setTitle("batting avg by year");
         //no animation
         chart->setAnimationOptions(QChart::AllAnimations);
         QStringList categories;
         categories<<"2019"<<"2020"<<"2021"<<"2022";
        QBarCategoryAxis *axis=new  QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->addAxis(axis, Qt::AlignBottom);
           Series->attachAxis(axis);
           Series->attachAxis(axis);


        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);


        QChartView *chartview=new QChartView(chart) ;
        chartview->setRenderHint(QPainter::Antialiasing);

        QVBoxLayout *layout2 = new QVBoxLayout(ui->chart_payment);
        layout2->addWidget(chartview);

//afficher payment
        QString order;
        if(ui->payment_order_combobox->currentText()=="Id")
        {
         order="id_payment";
        }
        if(ui->payment_order_combobox->currentText()=="Salary")
        {
         order="salary_employee";

        }
        if(ui->payment_order_combobox->currentText()=="Bill")
        {
         order="client_bill";
        }
        if(ui->payment_order_combobox->currentText()=="Name")
        {
         order="cardname";
        }
        payment p;
        QSqlQueryModel *model =p.afficher_payment(order);
        ui->payment_tableview->setModel(model);


}


void Dialog::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    int count[4];
    reservation r1;
    r1.satistics(count);
    //chart
    QBarSet *set0=new QBarSet("number of reservation ");


        *set0 <<count[0]<<count[1]<<count[2]<<count[3];



        QBarSeries *Series=new QBarSeries();
        Series->append(set0);

        QChart *chart=new QChart();
        chart->addSeries(Series);
        chart->setTitle("number of reservation by year");
        //no animation
        chart->setAnimationOptions(QChart::AllAnimations);
        QStringList categories;
        categories<<"2019"<<"2020"<<"2021"<<"2022";
       QBarCategoryAxis *axis=new  QBarCategoryAxis();
       axis->append(categories);
       chart->createDefaultAxes();
       chart->addAxis(axis, Qt::AlignBottom);
          Series->attachAxis(axis);
          Series->attachAxis(axis);


       chart->legend()->setVisible(true);
       chart->legend()->setAlignment(Qt::AlignBottom);


       QChartView *chartview=new QChartView(chart) ;
       chartview->setRenderHint(QPainter::Antialiasing);

       QVBoxLayout *layout2 = new QVBoxLayout(ui->chart_reservation);
       layout2->addWidget(chartview);



     //afficher reservation
        QString order;
        if(ui->reservation_order_combobox->currentText()=="id_reservation")
        {
         order="id_reservation";
        }
        if(ui->reservation_order_combobox->currentText()=="places")
        {
         order="nbr_place";

        }
        if(ui->reservation_order_combobox->currentText()=="destination")
        {
         order="destination";
        }

        reservation r;
        QSqlQueryModel *model=r.afficher_reservation(order);
        ui->reservation_tableview->setModel(model);

}


void Dialog::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QPieSeries *series1 = new QPieSeries();

     series1->append("Open Area",300);

     series1->append("Offices",10);

     QChart * chart1=new QChart();

     chart1->addSeries(series1);

     chart1->setTitle("stats");

     QChartView * chartView1=new QChartView(chart1);

     chartView1->setRenderHints(QPainter::Antialiasing);
     QVBoxLayout *layout1 = new QVBoxLayout(ui->piechart_employee);
     layout1->addWidget(chartView1);
     //

     QBarSet *set0=new QBarSet("altuve");
         QBarSet *set1=new QBarSet("martinez");
         QBarSet *set2=new QBarSet("segura");
         QBarSet *set3=new QBarSet("simons");
         QBarSet *set4=new QBarSet("trout");

         *set0 <<283<<341<<313<<338<<346<<335;
         *set1 <<250<<315<<282<<307<<303<<330;
         *set2 <<294<<346<<357<<319<<300<<325;
         *set3 <<248<<244<<265<<281<<278<<313;
         *set4 <<323<<287<<299<<315<<306<<313;

         QBarSeries *Series=new QBarSeries();
         Series->append(set0);
         Series->append(set1);
         Series->append(set2);
         Series->append(set3);
         Series->append(set4);

         QChart *chart=new QChart();
         chart->addSeries(Series);
         chart->setTitle("batting avg by year");
         //no animation
         chart->setAnimationOptions(QChart::AllAnimations);
         QStringList categories;
         categories<<"2013"<<"2014"<<"2015"<<"2016"<<"2017";
        QBarCategoryAxis *axis=new  QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        //chart->setAxisX(axis,Series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);


        QChartView *chartview=new QChartView(chart) ;
        chartview->setRenderHint(QPainter::Antialiasing);

        QVBoxLayout *layout2 = new QVBoxLayout(ui->chart_employee);
        layout2->addWidget(chartview);

        QString order;
        if(ui->employee_order_combobox->currentText()=="id_employee")
        {
         order="id_employee";
        }
        if(ui->employee_order_combobox->currentText()=="name")
        {
         order="name";

        }
        if(ui->employee_order_combobox->currentText()=="age")
        {
         order="age";
        }

        employee e;
        QSqlQueryModel *model=e.afficher_employee(order);
        ui->employee_tableview->setModel(model);
}



void Dialog::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QPieSeries *series1 = new QPieSeries();

     series1->append("Open Area",300);

     series1->append("Offices",10);

     QChart * chart1=new QChart();

     chart1->addSeries(series1);

     chart1->setTitle("stats");

     QChartView * chartView1=new QChartView(chart1);

     chartView1->setRenderHints(QPainter::Antialiasing);
     QVBoxLayout *layout1 = new QVBoxLayout(ui->piechart_accommodation);
     layout1->addWidget(chartView1);
     //

     QString order;
     if(ui->accommodation_order_combobox->currentText()=="accommodation")
     {
      order="ID_ACCOMMODATION";
     }
     if(ui->accommodation_order_combobox->currentText()=="name")
     {
      order="HOTEL_NAME";

     }
     if(ui->accommodation_order_combobox->currentText()=="HOTEL_RATE")
     {
      order="HOTEL_RATE";
     }

     accommodation a;
     QSqlQueryModel *model=a.afficher_accommodation(order);
     ui->accommodation_tableview->setModel(model);
}


void Dialog::on_pushButton_24_clicked()
{
}

//------------------------------------------------------------------------reservation---stylesheet-------input-----------------------------------------------------------------

void Dialog::on_idclient_reservation_line_textChanged(const QString &arg1)
{
    ui->idclient_reservation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF  ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_idclient_reservation_line_editingFinished()
{
    ui->idclient_reservation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}





void Dialog::on_idpayment_reservation_line_textChanged(const QString &arg1)
{
    ui->idpayment_reservation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_idpayment_reservation_line_editingFinished()
{
    ui->idpayment_reservation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_id_reservation_line_textChanged(const QString &arg1)
{
    ui->id_reservation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_id_reservation_line_editingFinished()
{
    ui->id_reservation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_nbrplaces_reservation_line_textChanged(const QString &arg1)
{
    ui->nbrplaces_reservation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600; border-radius:0px;");

}


void Dialog::on_nbrplaces_reservation_line_editingFinished()
{
    ui->nbrplaces_reservation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_cityname_reservation_line_textChanged(const QString &arg1)
{
    ui->cityname_reservation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_cityname_reservation_line_editingFinished()
{
    ui->cityname_reservation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_searsh_reservation_line_textChanged(const QString &arg1)
{
    ui->searsh_reservation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_searsh_reservation_line_editingFinished()
{
    ui->searsh_reservation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}

//------------------------------------------------------------------------client---stylesheet-------input-----------------------------------------------------------------

void Dialog::on_id_client_line_textChanged(const QString &arg1)
{
    ui->id_client_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_id_client_line_editingFinished()
{
    ui->id_client_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_firstname_client_line_textChanged(const QString &arg1)
{
    ui->firstname_client_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_firstname_client_line_editingFinished()
{
    ui->firstname_client_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_name_client_line_textChanged(const QString &arg1)
{
    ui->name_client_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_name_client_line_editingFinished()
{
    ui->name_client_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_email_client_line_textChanged(const QString &arg1)
{
    ui->email_client_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_email_client_line_editingFinished()
{
    ui->email_client_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_age_client_line_textChanged(const QString &arg1)
{
    ui->age_client_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_age_client_line_editingFinished()
{
    ui->age_client_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_phonenumber_client_line_textChanged(const QString &arg1)
{
    ui->phonenumber_client_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_phonenumber_client_line_editingFinished()
{
    ui->phonenumber_client_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_searsh_client_line_textChanged(const QString &arg1)
{
    ui->searsh_client_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_searsh_client_line_editingFinished()
{
    ui->searsh_client_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}

//------------------------------------------------------------------------payment---stylesheet-------input-----------------------------------------------------------------







void Dialog::on_id_payment_line_textChanged(const QString &arg1)
{
    ui->id_payment_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_id_payment_line_editingFinished()
{
    ui->id_payment_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}

void Dialog::on_searsh_payment_line_textChanged(const QString &arg1)
{
    ui->searsh_payment_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_searsh_payment_line_editingFinished()
{
    ui->searsh_payment_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}

//------------------------------------------------------------------------employee---stylesheet-------input-----------------------------------------------------------------

void Dialog::on_id_emloyee_line_textChanged(const QString &arg1)
{
    ui->id_emloyee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_id_emloyee_line_editingFinished()
{
    ui->id_emloyee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_firstname_emloyee_line_textChanged(const QString &arg1)
{
    ui->firstname_emloyee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_firstname_emloyee_line_editingFinished()
{
    ui->firstname_emloyee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_name_employee_line_textChanged(const QString &arg1)
{
    ui->name_employee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_name_employee_line_editingFinished()
{
    ui->name_employee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_age_emloyee_line_textChanged(const QString &arg1)
{
    ui->age_emloyee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_age_emloyee_line_editingFinished()
{
    ui->age_emloyee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_email_emloyee_line_textChanged(const QString &arg1)
{
    ui->email_emloyee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_email_emloyee_line_editingFinished()
{
    ui->email_emloyee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_adress_emloyee_line_textChanged(const QString &arg1)
{
    ui->adress_emloyee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_adress_emloyee_line_editingFinished()
{
    ui->adress_emloyee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_phonenumber_emloyee_line_textChanged(const QString &arg1)
{
    ui->phonenumber_emloyee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_phonenumber_emloyee_line_editingFinished()
{
    ui->phonenumber_emloyee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_searsh_emloyee_line_textChanged(const QString &arg1)
{
    ui->searsh_emloyee_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_searsh_emloyee_line_editingFinished()
{
    ui->searsh_emloyee_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}

//------------------------------------------------------------------------ Accommodation---stylesheet-------input-----------------------------------------------------------------



void Dialog::on_id_accommodation_line_textChanged(const QString &arg1)
{
    ui->id_accommodation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_id_accommodation_line_editingFinished()
{
    ui->id_accommodation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_idreservation_accommodation_line_textChanged(const QString &arg1)
{
    ui->idreservation_accommodation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_idreservation_accommodation_line_editingFinished()
{
    ui->idreservation_accommodation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_hotelname_accommodation_line_textChanged(const QString &arg1)
{
    ui->hotelname_accommodation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_hotelname_accommodation_line_editingFinished()
{
    ui->hotelname_accommodation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_hoteltelph_accommodation_line_textChanged(const QString &arg1)
{
    ui->hoteltelph_accommodation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_hoteltelph_accommodation_line_editingFinished()
{
    ui->hoteltelph_accommodation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_hotelrate_accommodation_line_textChanged(const QString &arg1)
{
    ui->hotelrate_accommodation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_hotelrate_accommodation_line_editingFinished()
{
    ui->hotelrate_accommodation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


void Dialog::on_searsh_accommodation_line_textChanged(const QString &arg1)
{
    ui->searsh_accommodation_line->setStyleSheet("border-bottom: 1.5px solid #6563FF ;color:#6563FF;font-weight:600;border-radius:0px; ");

}


void Dialog::on_searsh_accommodation_line_editingFinished()
{
    ui->searsh_accommodation_line->setStyleSheet("border-bottom: 1px solid #717072 ;color:#717072; ");

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------


void Dialog::on_pushButton_14_clicked()
{
   /* QPainter *painter;
    const QRect rect;
    const QDate date;


        if(date.dayOfWeek() == Qt::Monday)
        {
            painter->save();
            painter->fillRect(rect, Qt::green);
            painter->drawRect(rect);
            painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
            painter->restore();
            ui->calendarWidget->paintCell(painter,rect,date);
        }

    QPainter *painter = new QPainter;

     const QDate date;
     const QRect rect;

      ui->calendarWidget->paintCell(painter,rect,date);
*/
}

//add
void Dialog::on_pushButton_22_clicked()
{

}


void Dialog::on_payment_add_button_clicked()
{
    QString id_payment=ui->id_payment_line->text();
    QString service_type;
    int salary=0;
    int bill=0;

    if(ui->payment_client_service->isChecked())
    {
          service_type="client";
         payment p1;
         bill=p1.client_bill(id_payment);
         QString bill_string= QString::number(bill);
         ui->payment_bill_output->setText(bill_string);
         ui->payment_bill_frame->setVisible(true);
         ui->payment_salary_frame->setVisible(false);
    }
    else if(ui->payment_employee_service->isChecked())
      {
         service_type="employee";
         payment p1;
         salary=p1.employee_salary(id_payment);
         QString salary_string= QString::number(salary);
         ui->payment_salary_output->setText(salary_string);
         ui->payment_bill_frame->setVisible(false);
         ui->payment_salary_frame->setVisible(true);
      }

    QString date=ui->payment_date->text();
    QString cardname=ui->cardname_payment_line->text();
    QString payment_method;
    if(ui->payment_visa_btn->isChecked())
         payment_method="VisaCard";
    else if(ui->payment_mastercard_btn->isChecked())
         payment_method="MasterCard";
    else if(ui->payment_discover_btn->isChecked())
         payment_method="DiscoverCard";
    else if(ui->payment_express_btn->isChecked())
         payment_method="AmericanExpressCard";


    payment p(id_payment,date,service_type,salary,bill,payment_method,cardname);
    bool test=p.add_payment();
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
    }
    else
    {
        QMessageBox::information(this,"sign up","failed !");

    }

}

void Dialog::on_payment_modify_button_clicked()
{
    QString id_payment=ui->id_payment_line->text();
    QString service_type;
    int salary=0;
    int bill=0;

    if(ui->payment_client_service->isChecked())
    {
          service_type="client";
          payment p1;
          bill=p1.client_bill(id_payment);
         QString bill_string= QString::number(bill);
         ui->payment_bill_output->setText(bill_string+" Dt");
         ui->payment_bill_frame->setVisible(true);
         ui->payment_salary_frame->setVisible(false);
    }
    else if(ui->payment_employee_service->isChecked())
      {
         service_type="employee";
         payment p1;
         salary=p1.employee_salary(id_payment);
         QString salary_string= QString::number(salary);
         ui->payment_salary_output->setText(salary_string+" Dt");
         ui->payment_bill_frame->setVisible(false);
         ui->payment_salary_frame->setVisible(true);
      }

    QString date=ui->payment_date->text();
    QString cardname=ui->cardname_payment_line->text();
    QString payment_method;
    if(ui->payment_visa_btn->isChecked())
         payment_method="VisaCard";
    else if(ui->payment_mastercard_btn->isChecked())
         payment_method="MasterCard";
    else if(ui->payment_discover_btn->isChecked())
         payment_method="DiscoverCard";
    else if(ui->payment_express_btn->isChecked())
         payment_method="AmericanExpressCard";


    payment p(id_payment,date,service_type,salary,bill,payment_method,cardname);
    bool test=p.modify_payment();
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
    }
    else
    {
        QMessageBox::information(this,"sign up","failed !");

    }
}

void Dialog::on_payment_search_button_clicked()
{
    QString variable;
    if(ui->payment_search_combobox->currentText()=="Id")
    {
     variable="id_payment";
    }
    if(ui->payment_search_combobox->currentText()=="Salary")
    {
     variable="salary_employee";
    }
    if(ui->payment_search_combobox->currentText()=="Bill")
    {
     variable="client_bill";
    }
    if(ui->payment_search_combobox->currentText()=="Name")
    {
     variable="cardname";
    }
    if(ui->payment_search_combobox->currentText()=="Method")
    {
     variable="payment_method";
    }
    if(ui->payment_search_combobox->currentText()=="Service")
    {
     variable="service_type";
    }
    if(ui->payment_search_combobox->currentText()=="Date")
    {
     variable="date_payment";
    }
    payment p;
    QSqlQueryModel *model =p.search_payment(ui->searsh_payment_line->text(),variable);
    ui->payment_tableview->setModel(model);
}

void Dialog::on_payment_delete_button_clicked()
{
    payment p;
    bool test=p.delete_payment(ui->searsh_payment_line->text());
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
    }
    else{
        QMessageBox::information(this,"sign up","failed !");
    }


}

void Dialog::on_payment_pdf_clicked()
{
    QString id_payment=ui->id_payment_line->text();
    QString service_type;
    int salary=0;
    int bill=0;

    if(ui->payment_client_service->isChecked())
    {
          service_type="client";
         bill=0;
         QString bill_string= QString::number(bill);
         ui->payment_bill_output->setText(bill_string+" Dt");
         ui->payment_bill_frame->setVisible(true);
         ui->payment_salary_frame->setVisible(false);
    }
    else if(ui->payment_employee_service->isChecked())
      {
         service_type="employee";
         salary=0;
         QString salary_string= QString::number(salary);
         ui->payment_salary_output->setText(salary_string+" Dt");
         ui->payment_bill_frame->setVisible(false);
         ui->payment_salary_frame->setVisible(true);
      }

    QString date=ui->payment_date->text();
    QString cardname=ui->cardname_payment_line->text();
    QString payment_method;
    if(ui->payment_visa_btn->isChecked())
         payment_method="VisaCard";
    else if(ui->payment_mastercard_btn->isChecked())
         payment_method="MasterCard";
    else if(ui->payment_discover_btn->isChecked())
         payment_method="DiscoverCard";
    else if(ui->payment_express_btn->isChecked())
         payment_method="AmericanExpressCard";


    payment p(id_payment,date,service_type,salary,bill,payment_method,cardname);
     QString bill_string=QString::number(bill);
     QString salary_string=QString::number(salary);

QPdfWriter pdf("C:/Users/JAXIM/Desktop/Esprit/2eme/project/project (1)/project/payment.pdf");
QPainter painter(&pdf);

painter.setPen(Qt::black);
painter.drawText(4000,400,"receipt N°:  "+id_payment+"" );
painter.setPen(Qt::black);
painter.drawText(3500,1300,"Status: Posting bank payment" );
painter.drawText(3500,1700,"Date :  "+date+"" );
painter.drawText(3500,2100,"I, the undersigned :  LiweEddine Ayari" );
painter.drawText(3500,2500,"Treasurer of: :  Travel Tastic " );
painter.drawText(3500,2900,"Certify having received from (Mr/ Mrs) : "+cardname+"" );
painter.drawText(3500,3300,"The sum is :  "+bill_string+"" );
painter.end();



// /////////////////////////////////////////////////

}

void Dialog::on_client_add_button_clicked()
{

    QString id_c=ui->id_client_line->text();
    QString id_p=ui->idpayment_client_line->text();
    QString name=ui->name_client_line->text();
    QString first_name=ui->firstname_client_line->text();
    QString email=ui->email_client_line->text();
    int age =ui->age_client_line->text().toInt();
    QString phone_number=ui->phonenumber_client_line->text();
    int vip ;
    if(ui->client_vip_yes->isChecked()){vip = 1;}
    if(ui->client_vip_no->isChecked()){vip = 0;}

       client c(id_c,id_p,name,age,phone_number,first_name,email,vip);
    bool test=c.add_client();
    if(test)
    {
        QMessageBox::information(this,"add client","done !");
        QSqlQuery query;
        query.prepare( "UPDATE history SET modee=:modee where modee!=999 "
                           );
             query.bindValue(":modee",1);
             query.exec();
    }
    else
    {
        QMessageBox::information(this,"add client","failed !");

    }
    // ///////////////////////////////////////////////////////////////////////////// create client acc

    QString cuser = name + id_c ;
    QString cpass = phone_number;
    client_profil c1(cuser,cpass);
    c1.add_client_profil();

    // ///////////////////////////////////////////////////////////////////////////// HISTORIQUE





}



void Dialog::on_client_modify_button_clicked()
{
    QString id_c=ui->id_client_line->text();
    QString id_p=ui->idpayment_client_line->text();
    QString name=ui->name_client_line->text();
    QString first_name=ui->firstname_client_line->text();
    QString email=ui->email_client_line->text();
    int age =ui->age_client_line->text().toInt();
    QString phone_number=ui->phonenumber_client_line->text();
    int vip ;
    if(ui->client_vip_yes->isChecked()){vip = 1;}
    if(ui->client_vip_no->isChecked()){vip = 0;}

       client c(id_c,id_p,name,age,phone_number,first_name,email,vip);
    bool test=c.modif_client();
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
        QSqlQuery query;
        query.prepare( "UPDATE history SET modee=:modee where modee!=999 "
                           );
             query.bindValue(":modee",2);
             query.exec();
    }
    else
    {
        QMessageBox::information(this,"sign up","failed !");

    }
}

void Dialog::on_client_search_button_clicked()
{
    QString variable;
    if(ui->client_search_combobox->currentText()=="id_client")
    {
     variable="id_client";
    }
    if(ui->client_search_combobox->currentText()=="id_payment")
    {
     variable="id_payment";
    }
    if(ui->client_search_combobox->currentText()=="name")
    {
     variable="name";
    }
    if(ui->client_search_combobox->currentText()=="first name")
    {
     variable="first_name";
    }
    if(ui->client_search_combobox->currentText()=="email")
    {
     variable="email";
    }
    if(ui->client_search_combobox->currentText()=="age")
    {
     variable="age";
    }
    if(ui->client_search_combobox->currentText()=="phone")
    {
     variable="phone_number";
    }
    if(ui->client_search_combobox->currentText()=="vip")
    {
     variable="vip";
    }
    client c;
    QSqlQueryModel *model =c.search_client(ui->searsh_client_line->text(),variable);
    ui->client_tableview->setModel(model);
}

void Dialog::on_client_delete_button_clicked()
{
    client c;
    QString id=ui->searsh_client_line->text();
    bool test=c.delete_client(id);
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
        QSqlQuery query;
        query.prepare( "UPDATE history SET modee=:modee where modee!=999 "
                           );
             query.bindValue(":modee",3);
             query.exec();
    }
    else{
        QMessageBox::information(this,"sign up","failed !");
    }
}

void Dialog::on_calendarWidget_clicked(const QDate &date)
{

    QString date_string=date.toString();
    ui->calendar_date_label->setText(date_string);


    QString day_string=QString::number(date.day());
    QString month_string=QString::number(date.month());
    QString year_string=QString::number(date.year());

    QString date_selected=month_string+"/"+day_string+"/"+year_string ;
   reservation r;
   r.search_date(date_selected);
   ui->id_reservation_label->setText(" Id_reservation : "+r.getid_reservation());
   ui->date_aller_label->setText("Date de depart : "+r.getdate_aller());
   ui->date_retour_label->setText("Date de sortie : "+r.getdate_retour());
   ui->destination_label->setText("Destination:"+r.getdestination());
  ui->client_name_label->setText("id client :"+r.getid_client());
}

void Dialog::on_client_pdf_clicked()
{

    QString id_c=ui->id_client_line->text();
    QString id_p=ui->idpayment_client_line->text();
    QString name=ui->name_client_line->text();
    QString first_name=ui->firstname_client_line->text();
    QString email=ui->email_client_line->text();
    QString age =ui->age_client_line->text();
    QString phone_number=ui->phonenumber_client_line->text();
    QString vip ;
    if(ui->client_vip_yes->isChecked()){vip = "Yes";}
    if(ui->client_vip_no->isChecked()){vip = "No";}

    QPdfWriter pdf("C:/Users/21690/Desktop/project (1) (1)/project (1)/project/client.pdf");
    QPainter painter(&pdf);

    painter.setPen(Qt::red);
    painter.drawText(4000,400,"Client N°:  "+id_c+"" );
    painter.setPen(Qt::black);
    painter.drawText(3500,1700,"His payment :  "+id_p+"" );
    painter.drawText(3500,2100,"The first name : "+first_name+"" );
    painter.drawText(3500,2500,"The name : "+name+"" );
    painter.drawText(3500,2900,"Email : "+email+"" );
    painter.drawText(3500,3300,"Age :  "+age+"" );
    painter.drawText(3500,3700,"phone number :  "+phone_number+"" );
    painter.drawText(3500,4100,"Vip check :  "+vip+"" );
    painter.end();

}

///add_employee

void Dialog::on_employee_add_button_clicked()
{
    QString id_employee,id_payment;
    QString first_name,name,age,email,adress,phone_number,role;
    id_employee=ui->id_emloyee_line->text();
    id_payment=ui->idpayment_emloyee_line->text();
    first_name=ui->firstname_emloyee_line->text();
    name=ui->name_employee_line->text();
    age=ui->age_emloyee_line->text();
    email=ui->email_emloyee_line->text();
    adress=ui->adress_emloyee_line->text();
    phone_number=ui->phonenumber_emloyee_line->text();

    if(ui->employee_travelagent_btn->isChecked())
        role="travelagent";
    if(ui->employee_economymanager_btn->isChecked())
        role="economymanage";
    if(ui->employee_travelmanager_btn->isChecked())
        role="travelmanager";
    if(ui->employee_marketingmanager_btn->isChecked())
        role="marketingmanager";
    if(ui->employee_administrativemanager_btn->isChecked())
        role="administrativemanager";
    if(ui->employee_softwareengineer_btn->isChecked())
        role="softwareengineer";

employee e(id_employee,id_payment,first_name,name,age,email,adress,phone_number,role);
  bool test=e.add_employee();

  if(test)
      QMessageBox::information(this,"sign up","done !");
  else
     QMessageBox::information(this,"sign up","failed !");






}







///add reservation

void Dialog::on_reservation_add_button_clicked()
{
    int nbr_place;
    QString id_reservation,id_client,id_payment,destination,date_aller,date_retour;

    id_reservation=ui->id_reservation_line->text();

    id_client=ui->idclient_reservation_line->text();
    id_payment=ui->idpayment_reservation_line->text();
    nbr_place=ui->nbrplaces_reservation_line->text().toInt();
    destination=ui->cityname_reservation_line->text();
    date_aller=ui->dateEdit_2->text();
    date_retour=ui->dateEdit_3->text();

    reservation r(id_reservation,id_client,id_payment,destination,date_aller,date_retour,nbr_place);

    bool test=r.add_reservation();

    if(test)
        QMessageBox::information(this,"sign up","done !");
    else
       QMessageBox::information(this,"sign up","failed !");

}

void Dialog::on_reservation_modify_button_clicked()
{

    int nbr_place;
    QString id_reservation,id_client,id_payment,destination,date_aller,date_retour;

    id_reservation=ui->id_reservation_line->text();

    id_client=ui->idclient_reservation_line->text();
    id_payment=ui->idpayment_reservation_line->text();
    nbr_place=ui->nbrplaces_reservation_line->text().toInt();
    destination=ui->cityname_reservation_line->text();
    date_aller=ui->dateEdit_2->text();
    date_retour=ui->dateEdit_3->text();

    reservation r(id_reservation,id_client,id_payment,destination,date_aller,date_retour,nbr_place);

    bool test=r.modify_reservation();

    if(test)
        QMessageBox::information(this,"sign up","done !");
    else
       QMessageBox::information(this,"sign up","failed !");

}

void Dialog::on_reservation_search_button_clicked()
{
    QString variable;
    if(ui->reservation_search_combobox->currentText()=="id_reservation")
    {
     variable="id_reservation";
    }
    if(ui->reservation_search_combobox->currentText()=="id_payment")
    {
     variable="id_payment";
    }
    if(ui->reservation_search_combobox->currentText()=="id_client")
    {
     variable="id_client";
    }
    if(ui->reservation_search_combobox->currentText()=="places")
    {
     variable="nbr_place";
    }
    if(ui->reservation_search_combobox->currentText()=="name of the city")
    {
     variable="destination";
    }
    if(ui->reservation_search_combobox->currentText()=="Departure date")
    {
     variable="date_aller";
    }
    if(ui->reservation_search_combobox->currentText()=="Return date")
    {
     variable="date_retour";
    }

    reservation r;
    QSqlQueryModel *model =r.search_reservation(ui->searsh_reservation_line->text(),variable);
    ui->reservation_tableview->setModel(model);
}

void Dialog::on_reservation_delete_button_clicked()
{
    reservation r;
    QString id=ui->searsh_reservation_line->text();
    bool test=r.delete_reservation(id);
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
    }
    else{
        QMessageBox::information(this,"sign up","failed !");
    }
}

void Dialog::on_employee_modify_button_clicked()
{
    QString id_employee,id_payment;
    QString first_name,name,age,email,adress,phone_number,role;
    id_employee=ui->id_emloyee_line->text();
    id_payment=ui->idpayment_emloyee_line->text();
    first_name=ui->firstname_emloyee_line->text();
    name=ui->name_employee_line->text();
    age=ui->age_emloyee_line->text();
    email=ui->email_emloyee_line->text();
    adress=ui->adress_emloyee_line->text();
    phone_number=ui->phonenumber_emloyee_line->text();

    if(ui->employee_travelagent_btn->isChecked())
        role="Travel agent";
    if(ui->employee_economymanager_btn->isChecked())
        role="Economy manager";
    if(ui->employee_travelmanager_btn->isChecked())
        role="Travel manager";
    if(ui->employee_marketingmanager_btn->isChecked())
        role="Marketing manager";
    if(ui->employee_administrativemanager_btn->isChecked())
        role="Administrative manager";
    if(ui->employee_softwareengineer_btn->isChecked())
        role="Software engineer";

employee e(id_employee,id_payment,first_name,name,age,email,adress,phone_number,role);
  bool test=e.modify_employee();

  if(test)
      QMessageBox::information(this,"sign up","done !");
  else
     QMessageBox::information(this,"sign up","failed !");
}

void Dialog::on_employee_search_button_clicked()
{
    QString variable;
    if(ui->employee_search_combobox->currentText()=="id_employee")
    {
     variable="ID_EMPLOYEE";
    }
    if(ui->employee_search_combobox->currentText()=="id_payment")
    {
     variable="ID_PAYMENT";
    }
    if(ui->employee_search_combobox->currentText()=="first_name")
    {
     variable="FIRST_NAME";
    }
    if(ui->employee_search_combobox->currentText()=="name")
    {
     variable="NAME";
    }
    if(ui->employee_search_combobox->currentText()=="age")
    {
     variable="AGE";
    }
    if(ui->employee_search_combobox->currentText()=="email")
    {
     variable="EMAIL";
    }
    if(ui->employee_search_combobox->currentText()=="adress")
    {
     variable="ADRESS";
    }
    if(ui->employee_search_combobox->currentText()=="phone_number")
    {
     variable="PHONE_NUMBER";
    }
    if(ui->employee_search_combobox->currentText()=="role")
    {
     variable="ROLE";
    }


    employee e;
    QSqlQueryModel *model =e.search_employee(ui->searsh_emloyee_line->text(),variable);
    ui->employee_tableview->setModel(model);
}

void Dialog::on_employee_delete_button_clicked()
{
    employee e;
    QString id=ui->searsh_emloyee_line->text();
    bool test=e.delete_employee(id);
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
    }
    else{
        QMessageBox::information(this,"sign up","failed !");
    }
}

void Dialog::on_accommodation_add_button_clicked()
{
    QString  id_reservation;
    QString  id_accommodation,hotel_telph;
    QString hotel_name,MOTransport ;
    int hotel_rate;

    id_accommodation=ui->id_accommodation_line->text();
    id_reservation=ui->idreservation_accommodation_line->text();
    hotel_name=ui->hotelname_accommodation_line->text();
    hotel_telph=ui->hoteltelph_accommodation_line->text();
    hotel_rate=ui->hotelrate_accommodation_line->text().toInt();

    if(ui->accommodation_publictransport_button->isChecked())
        MOTransport="Public transport";
    if(ui->accommodation_taxis_button->isChecked())
        MOTransport="Taxis";
    if(ui->accommodation_boltbuisnesscar_button->isChecked())
        MOTransport="Bolt Buisness car";

    accommodation a(id_accommodation,id_reservation,hotel_name,hotel_telph,hotel_rate,MOTransport);
    bool test=a.add_accommodation();

    if(test)
        QMessageBox::information(this,"sign up","done !");
    else
       QMessageBox::information(this,"sign up","failed !");



}

void Dialog::on_accommodation_modify_button_clicked()
{
    QString  id_reservation;
    QString  id_accommodation,hotel_telph;
    QString hotel_name,MOTransport ;
    int hotel_rate;

    id_accommodation=ui->id_accommodation_line->text();
    id_reservation=ui->idreservation_accommodation_line->text();
    hotel_name=ui->hotelname_accommodation_line->text();
    hotel_telph=ui->hoteltelph_accommodation_line->text();
    hotel_rate=ui->hotelrate_accommodation_line->text().toInt();

    if(ui->accommodation_publictransport_button->isChecked())
        MOTransport="Public transport";
    if(ui->accommodation_taxis_button->isChecked())
        MOTransport="Taxis";
    if(ui->accommodation_boltbuisnesscar_button->isChecked())
        MOTransport="Bolt Buisness car";

    accommodation a(id_accommodation,id_reservation,hotel_name,hotel_telph,hotel_rate,MOTransport);
    bool test=a.modify_accommodation();

    if(test)
        QMessageBox::information(this,"sign up","done !");
    else
       QMessageBox::information(this,"sign up","failed !");
}

void Dialog::on_accommodation_search_button_clicked()
{
    QString variable;
    if(ui->accommodation_search_combobox->currentText()=="accommodation")
    {
     variable="ID_ACCOMMODATION";
    }
    if(ui->accommodation_search_combobox->currentText()=="reservation")
    {
     variable="ID_RESERVATION";
    }
    if(ui->accommodation_search_combobox->currentText()=="name")
    {
     variable="HOTEL_NAME";
    }
    if(ui->accommodation_search_combobox->currentText()=="tel")
    {
     variable="HOTEL_TELPH";
    }
    if(ui->accommodation_search_combobox->currentText()=="rate")
    {
     variable="HOTEL_RATE";
    }
    if(ui->accommodation_search_combobox->currentText()=="transport")
    {
     variable="MOTRANSPORT";
    }

    accommodation a;
    QSqlQueryModel *model =a.search_accommodation(ui->searsh_accommodation_line->text(),variable);
    ui->accommodation_tableview->setModel(model);
}

void Dialog::on_accommodation_delete_button_clicked()
{
    accommodation a;
    QString id=ui->searsh_accommodation_line->text();
    bool test=a.delete_accommodation(id);
    if(test)
    {
        QMessageBox::information(this,"sign up","done !");
    }
    else{
        QMessageBox::information(this,"sign up","failed !");
    }
}



void Dialog::on_reservation_pdf_clicked()
{
    QString nbr_place;
    QString id_reservation,id_client,id_payment,destination,date_aller,date_retour;

    id_reservation=ui->id_reservation_line->text();

    id_client=ui->idclient_reservation_line->text();
    id_payment=ui->idpayment_reservation_line->text();
    nbr_place=ui->nbrplaces_reservation_line->text();
    destination=ui->cityname_reservation_line->text();
    date_aller=ui->dateEdit_2->text();
    date_retour=ui->dateEdit_3->text();

    QPdfWriter pdf("C:/Users/JAXIM/Desktop/Esprit/2eme/project/project (1)/project/reservation.pdf");
    QPainter painter(&pdf);

    painter.setPen(Qt::red);
    painter.drawText(4000,400,"Resevation N°:  "+id_reservation+"" );
    painter.setPen(Qt::black);
    painter.drawText(3500,1700,"The payment :  "+id_payment+"" );
    painter.drawText(3500,2100,"The client : "+id_client+"" );
    painter.drawText(3500,2500,"The number of places : "+nbr_place+"" );
    painter.drawText(3500,2900,"destination : "+destination+"" );
    painter.drawText(3500,3300,"Departure date :  "+date_aller+"" );
    painter.drawText(3500,3700,"Return date :  "+date_retour+"" );
    painter.end();
}

void Dialog::on_employe_pdf_clicked()
{
    QString id_employee,id_payment;
    QString first_name,name,age,email,adress,phone_number,role;
    id_employee=ui->id_emloyee_line->text();
    id_payment=ui->idpayment_emloyee_line->text();
    first_name=ui->firstname_emloyee_line->text();
    name=ui->name_employee_line->text();
    age=ui->age_emloyee_line->text();
    email=ui->email_emloyee_line->text();
    adress=ui->adress_emloyee_line->text();
    phone_number=ui->phonenumber_emloyee_line->text();

    if(ui->employee_travelagent_btn->isChecked())
        role="travelagent";
    if(ui->employee_economymanager_btn->isChecked())
        role="economymanage";
    if(ui->employee_travelmanager_btn->isChecked())
        role="travelmanager";
    if(ui->employee_marketingmanager_btn->isChecked())
        role="marketingmanager";
    if(ui->employee_administrativemanager_btn->isChecked())
        role="administrativemanager";
    if(ui->employee_softwareengineer_btn->isChecked())
        role="softwareengineer";
    QPdfWriter pdf("C:/Users/JAXIM/Desktop/Esprit/2eme/project/project (1)/project/employee.pdf");
    QPainter painter(&pdf);

    painter.setPen(Qt::red);
    painter.drawText(4000,400,"Employee N°:  "+id_employee+"" );
    painter.setPen(Qt::black);
    painter.drawText(3500,1700,"The payment :  "+id_payment+"" );
    painter.drawText(3500,2100,"The first name : "+first_name+"" );
    painter.drawText(3500,2500,"The name : "+name+"" );
    painter.drawText(3500,2900,"Age : "+age+"" );
    painter.drawText(3500,3300,"The email :  "+email+"" );
    painter.drawText(3500,3700,"Adress:  "+adress+"" );
    painter.drawText(3500,4100,"Phone_number :  "+phone_number+"" );
    painter.drawText(3500,4500,"role :  "+role+"" );

    painter.end();
}

void Dialog::on_accommodation_pdf_clicked()
{
    QString  id_reservation;
    QString  id_accommodation,hotel_telph;
    QString hotel_name,MOTransport ;
    QString hotel_rate;

    id_accommodation=ui->id_accommodation_line->text();
    id_reservation=ui->idreservation_accommodation_line->text();
    hotel_name=ui->hotelname_accommodation_line->text();
    hotel_telph=ui->hoteltelph_accommodation_line->text();
    hotel_rate=ui->hotelrate_accommodation_line->text();

    if(ui->accommodation_publictransport_button->isChecked())
        MOTransport="Public transport";
    if(ui->accommodation_taxis_button->isChecked())
        MOTransport="Taxis";
    if(ui->accommodation_boltbuisnesscar_button->isChecked())
        MOTransport="Bolt Buisness car";

    QPdfWriter pdf("C:/Users/JAXIM/Desktop/Esprit/2eme/project/project (1)/project/accommodation.pdf");
    QPainter painter(&pdf);

    painter.setPen(Qt::red);
    painter.drawText(4000,400,"Accommodation N°:  "+id_accommodation+"" );
    painter.setPen(Qt::black);
    painter.drawText(3500,1700,"reservation :  "+id_reservation+"" );
    painter.drawText(3500,2100,"The hotel name : "+hotel_name+"" );
    painter.drawText(3500,2500,"The hotel telph : "+hotel_telph+"" );
    painter.drawText(3500,2900,"The hotel_rate : "+hotel_rate+"" );
    painter.drawText(3500,3300,"Means of transport :  "+MOTransport+"" );

    painter.end();
}

void Dialog::on_notif_clicked()
{
    notif = new notif_space(this);
    notif->show();
    QSqlQuery q;
    q.prepare("select * from history");

}

void Dialog::on_chat_clicked()
{
    chat = new chatbox(this);
    chat->show();
}




