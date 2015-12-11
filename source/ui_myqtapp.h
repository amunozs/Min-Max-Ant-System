/********************************************************************************
** Form generated from reading UI file 'myqtapp.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQTAPP_H
#define UI_MYQTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myQtAppDLG
{
public:
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *browseBut;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelNumAnts;
    QLabel *labelIterations;
    QLabel *labelMax;
    QLabel *labelIMin;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *antsBox;
    QSpinBox *iterationsBox;
    QDoubleSpinBox *maxBox;
    QDoubleSpinBox *minBox;
    QSpinBox *alphaBox;
    QSpinBox *betaBox;
    QDoubleSpinBox *evapBox;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *solutionText;
    QPushButton *solveBut;
    QPushButton *clearBut;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QWidget *myQtAppDLG)
    {
        if (myQtAppDLG->objectName().isEmpty())
            myQtAppDLG->setObjectName(QStringLiteral("myQtAppDLG"));
        myQtAppDLG->resize(354, 333);
        verticalLayoutWidget_4 = new QWidget(myQtAppDLG);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 20, 331, 301));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit = new QLineEdit(verticalLayoutWidget_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        browseBut = new QPushButton(verticalLayoutWidget_4);
        browseBut->setObjectName(QStringLiteral("browseBut"));

        horizontalLayout_2->addWidget(browseBut);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelNumAnts = new QLabel(verticalLayoutWidget_4);
        labelNumAnts->setObjectName(QStringLiteral("labelNumAnts"));

        verticalLayout->addWidget(labelNumAnts, 0, Qt::AlignHCenter);

        labelIterations = new QLabel(verticalLayoutWidget_4);
        labelIterations->setObjectName(QStringLiteral("labelIterations"));

        verticalLayout->addWidget(labelIterations, 0, Qt::AlignHCenter);

        labelMax = new QLabel(verticalLayoutWidget_4);
        labelMax->setObjectName(QStringLiteral("labelMax"));

        verticalLayout->addWidget(labelMax, 0, Qt::AlignHCenter);

        labelIMin = new QLabel(verticalLayoutWidget_4);
        labelIMin->setObjectName(QStringLiteral("labelIMin"));

        verticalLayout->addWidget(labelIMin, 0, Qt::AlignHCenter);

        label = new QLabel(verticalLayoutWidget_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        label_2 = new QLabel(verticalLayoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        label_3 = new QLabel(verticalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3, 0, Qt::AlignHCenter);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        antsBox = new QSpinBox(verticalLayoutWidget_4);
        antsBox->setObjectName(QStringLiteral("antsBox"));
        antsBox->setMaximum(99999);
        antsBox->setValue(10);

        verticalLayout_2->addWidget(antsBox);

        iterationsBox = new QSpinBox(verticalLayoutWidget_4);
        iterationsBox->setObjectName(QStringLiteral("iterationsBox"));
        iterationsBox->setMaximum(9999);
        iterationsBox->setValue(10);

        verticalLayout_2->addWidget(iterationsBox);

        maxBox = new QDoubleSpinBox(verticalLayoutWidget_4);
        maxBox->setObjectName(QStringLiteral("maxBox"));
        maxBox->setValue(10);

        verticalLayout_2->addWidget(maxBox);

        minBox = new QDoubleSpinBox(verticalLayoutWidget_4);
        minBox->setObjectName(QStringLiteral("minBox"));
        minBox->setValue(1);

        verticalLayout_2->addWidget(minBox);

        alphaBox = new QSpinBox(verticalLayoutWidget_4);
        alphaBox->setObjectName(QStringLiteral("alphaBox"));
        alphaBox->setValue(1);

        verticalLayout_2->addWidget(alphaBox);

        betaBox = new QSpinBox(verticalLayoutWidget_4);
        betaBox->setObjectName(QStringLiteral("betaBox"));
        betaBox->setValue(2);

        verticalLayout_2->addWidget(betaBox);

        evapBox = new QDoubleSpinBox(verticalLayoutWidget_4);
        evapBox->setObjectName(QStringLiteral("evapBox"));
        evapBox->setMaximum(1);
        evapBox->setValue(0.9);

        verticalLayout_2->addWidget(evapBox);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        solutionText = new QTextEdit(verticalLayoutWidget_4);
        solutionText->setObjectName(QStringLiteral("solutionText"));

        verticalLayout_3->addWidget(solutionText);

        solveBut = new QPushButton(verticalLayoutWidget_4);
        solveBut->setObjectName(QStringLiteral("solveBut"));

        verticalLayout_3->addWidget(solveBut);

        clearBut = new QPushButton(verticalLayoutWidget_4);
        clearBut->setObjectName(QStringLiteral("clearBut"));

        verticalLayout_3->addWidget(clearBut);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(myQtAppDLG);

        QMetaObject::connectSlotsByName(myQtAppDLG);
    } // setupUi

    void retranslateUi(QWidget *myQtAppDLG)
    {
        myQtAppDLG->setWindowTitle(QApplication::translate("myQtAppDLG", "Max-Min Ants", 0));
        label_4->setText(QApplication::translate("myQtAppDLG", "Input file:", 0));
        browseBut->setText(QApplication::translate("myQtAppDLG", "Browse", 0));
        labelNumAnts->setText(QApplication::translate("myQtAppDLG", "Num Ants", 0));
        labelIterations->setText(QApplication::translate("myQtAppDLG", "Iterations", 0));
        labelMax->setText(QApplication::translate("myQtAppDLG", "Max Feromone", 0));
        labelIMin->setText(QApplication::translate("myQtAppDLG", "Min Feromone", 0));
        label->setText(QApplication::translate("myQtAppDLG", "Alpha", 0));
        label_2->setText(QApplication::translate("myQtAppDLG", "Beta", 0));
        label_3->setText(QApplication::translate("myQtAppDLG", "Evaporation", 0));
        solveBut->setText(QApplication::translate("myQtAppDLG", "Solve", 0));
        clearBut->setText(QApplication::translate("myQtAppDLG", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class myQtAppDLG: public Ui_myQtAppDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTAPP_H
