#ifndef TABVIEW_H
#define TABVIEW_H

#include <QWidget>
#include <QtWebKit/QWebView>

#define HOMEPAGE "http://www.google.com"

namespace Ui {
class TabView;
}

class TabView : public QWidget
{
    Q_OBJECT
    
public:
    explicit TabView(QWidget *parent = 0);
    QString GetTitle();
    void Reload();
    void Stop();
    void Home();
    ~TabView();
    
private slots:
    void on_BackButton_clicked();
    void on_Forward_Button_clicked();
    void on_Go_Button_clicked();
    void on_TabMainView_urlChanged(const QUrl &arg1);

private:
    Ui::TabView *ui;
    QString Title;
};

#endif // TABVIEW_H
