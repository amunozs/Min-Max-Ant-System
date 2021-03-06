#include <QtGui> 
#include <QFileDialog>
#include <QMessageBox>
#include "myqtapp.h"

#include <iostream>
#include <fstream>
#include "SpaceInformation.hpp"
#include "Ant.hpp"
#include "Solver.hpp"
 
// if we include <QtGui> there is no need to include every class used: <QString>, <QFileDialog>,...
 
myQtApp::myQtApp(QWidget *parent)
{
    setupUi(this); // this sets up GUI
 
    // signals/slots mechanism in action
    connect( browseBut, SIGNAL( clicked() ), this, SLOT( getPath() ) ); 
    connect( solveBut, SIGNAL( clicked() ), this, SLOT( solve() ) ); 
	connect( clearBut, SIGNAL( clicked() ), this, SLOT( clear() ) ); 
}
 
 
void myQtApp::getPath()
{

    QString path;
    path = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        QString::null,
        QString::null);
    path_ = path.toStdString();
 
    lineEdit->setText( path);
}
 
 
void myQtApp::solve()
{
    int num_ants, num_iterations, num_alpha, num_beta;
	double num_max, num_min, num_evap;
    Qt::CheckState state;
    QString str;

 	num_ants 		= antsBox->value();
	num_iterations 	= iterationsBox->value();
	num_alpha 		= alphaBox->value();
	num_beta 		= betaBox->value();
	num_max 		= maxBox->value();
    num_min         = minBox->value();
	num_evap 		= evapBox->value();
 
    //solutionText->append( "Number of ants: " + QString::number(num_ants) );
    //solutionText->append( "Number of iterations: " + QString::number(num_iterations) );

    SpaceInformation* SI = new SpaceInformation;
    if (!SI->readFromFile (path_.c_str()))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Invalid file");
        messageBox.setFixedSize(500,200);
    }

    else
    {
        Solver S(SI, num_ants, num_iterations, num_alpha, num_beta, num_max, num_min, num_evap);
        //Solver S(SI);
        S.solve();
        S.printSol();
        std::cout<<"T="<<S.getTime()<<"ms."<<std::endl;
        solutionText->append("Solution:\n" + QString::fromStdString(S.getPath()) + "\nCost = " + QString::number(S.getFitness() ) + "\nTime = " + QString::number(S.getTime()) + "\n\n\n");
    }
}
 
 
void myQtApp::clear()
{
    solutionText->clear();
}

