#include "maxnet.h"
#include "ui_maxnet.h"
#include <cstdio>
using namespace std;

MaxNet::MaxNet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaxNet)
{
    TabCount = 1;
    Tabs.resize(TabCount*5);
    Tabs.at(TabCount)= new TabView;
    ui->setupUi(this);
    ui->tabWidget->insertTab(TabCount,Tabs[TabCount], Tabs[TabCount]->GetTitle());
    TabCount++;
}

MaxNet::~MaxNet()
{
    delete ui;
}

void MaxNet::on_actionNew_Window_triggered()
{
    MaxNet New;
    New.create();
}

void MaxNet::on_actionNew_Tab_triggered()
{
    if(Tabs.size() >(unsigned) TabCount){
       Tabs[TabCount] = new TabView;
    } else {
        Tabs.resize(TabCount*2);
        Tabs[TabCount] = new TabView;
    }
    ui->tabWidget->insertTab(TabCount,Tabs[TabCount], Tabs[TabCount]->GetTitle());
}

void MaxNet::on_actionQuit_triggered()
{
    delete this;
}

void MaxNet::on_actionClose_Tab_triggered()
{
    int tmp = ui->tabWidget->currentIndex();
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    delete Tabs[tmp];
    TabCount--;
    if(TabCount == 0){
        TabCount++;
        ui->tabWidget->insertTab(TabCount,Tabs[TabCount], Tabs.at(TabCount)->GetTitle());
    }
}

void MaxNet::on_actionRefresh_triggered()
{
    TabView::FLAGS FlagsToSend;
    FlagsToSend.refresh = true;
    FlagsToSend.GoHome = false;
    FlagsToSend.Stop = false;
    Tabs[ui->tabWidget->currentIndex()]->SendSignal(FlagsToSend);
}
