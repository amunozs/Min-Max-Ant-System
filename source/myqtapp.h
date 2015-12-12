#ifndef MYQTAPP_H
#define MYQTAPP_H
 
#include "ui_myqtapp.h"
 
 
class myQtApp : public QWidget, private Ui::myQtAppDLG
{
    Q_OBJECT
 
public:
    myQtApp(QWidget *parent = 0);
 
private:
    std::string path_;
 
public slots:
    void getPath();
    void solve();
	void clear();
    //void clear();
    //void about();
};
 
 
#endif
