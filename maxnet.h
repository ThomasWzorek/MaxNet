#ifndef MAXNET_H
#define MAXNET_H

#include <QMainWindow>
#include <vector>
#include "tabview.h"

namespace Ui {
class MaxNet;
}

class MaxNet : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MaxNet(QWidget *parent = 0);
    ~MaxNet();
    
private slots:
    void on_actionNew_Window_triggered();
    void on_actionNew_Tab_triggered();
    void on_actionQuit_triggered();
    void on_actionClose_Tab_triggered();
    void on_actionRefresh_triggered();

private:
    Ui::MaxNet *ui;
    std::vector<TabView*> Tabs;
    int TabCount;
};

#endif // MAXNET_H
