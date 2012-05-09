#include "tabview.h"
#include "ui_tabview.h"
#include <QtWebKit/QWebView>

TabView::TabView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabView)
{
    Title = "This is my title";
    ui->setupUi(this);
    ui->TabMainView->load(QUrl(HOMEPAGE));
    ui->TabMainView->show();
    Title = ui->TabMainView->title();
}

TabView::~TabView()
{
    delete ui;
}

QString TabView::GetTitle()
{
    return Title;
}

void TabView::Reload()
{
    ui->TabMainView->setUrl(ui->TabMainView->url());
    Title = ui->TabMainView->title();
}

void TabView::Stop()
{
    ui->TabMainView->stop();
    Title = ui->TabMainView->title();
}

void TabView::Home()
{
    ui->TabMainView->load(QUrl(HOMEPAGE));
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
        ui->Address_Bar->setText(ui->TabMainView->url().toString());
    } else if(ui->Address_Bar->text().contains("https://")) {
        ui->TabMainView->load(QUrl(ui->Address_Bar->text()));
        ui->Address_Bar->setText(ui->TabMainView->url().toString());
    } else if(ui->Address_Bar->text().contains("ftp://")){
        ui->TabMainView->load(QUrl(ui->Address_Bar->text()));
        ui->Address_Bar->setText(ui->TabMainView->url().toString());
    } else if(ui->Address_Bar->text().contains("file://")){
        ui->TabMainView->load(QUrl(ui->Address_Bar->text()));
        ui->Address_Bar->setText(ui->TabMainView->url().toString());
    } else {
        ui->TabMainView->load(QUrl(QString("http://") +
                                   ui->Address_Bar->text()));
        ui->Address_Bar->setText(ui->TabMainView->url().toString());
    }
}

void TabView::on_TabMainView_urlChanged(const QUrl &arg1)
{
    ui->Address_Bar->setText(ui->TabMainView->url().toString());
    Title = ui->TabMainView->title();
}
