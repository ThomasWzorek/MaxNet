#include "tabview.h"
#include "ui_tabview.h"
#include <QtWebKit/QWebView>

TabView::TabView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabView)
{
    ui->setupUi(this);
    ui->TabMainView->load(QUrl("http://www.google.com"));
    ui->TabMainView->show();
    Title = ui->TabMainView->url().toString();
}

TabView::~TabView()
{
    delete ui;
}

QString TabView::GetTitle() {
    return Title;
}

void TabView::on_BackButton_clicked()
{
    ui->TabMainView->back();
    ui->Address_Bar->setText(ui->TabMainView->url().toString());
}

void TabView::on_Forward_Button_clicked()
{
    ui->TabMainView->forward();
    ui->Address_Bar->setText(ui->TabMainView->url().toString());
}


void TabView::on_Go_Button_clicked()
{
    if(ui->Address_Bar->text().contains("http://")){
        ui->TabMainView->load(QUrl(ui->Address_Bar->text()));
    } else if(ui->Address_Bar->text().contains("https://")) {
        ui->TabMainView->load(QUrl(ui->Address_Bar->text()));
    } else if(ui->Address_Bar->text().contains("ftp://")){
        ui->TabMainView->load(QUrl(ui->Address_Bar->text()));
    } else if(ui->Address_Bar->text().contains("file://")){
        ui->TabMainView->load(QUrl(ui->Address_Bar->text()));
    } else {
        ui->TabMainView->load(QUrl(QString("http://") +
                                   ui->Address_Bar->text()));
    }
        ui->Address_Bar->setText(ui->TabMainView->url().toString());
}
