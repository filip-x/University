/********************************************************************************
** Form generated from reading UI file 'Lab10onLab9.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB10ONLAB9_H
#define UI_LAB10ONLAB9_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab10onLab9Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab10onLab9Class)
    {
        if (Lab10onLab9Class->objectName().isEmpty())
            Lab10onLab9Class->setObjectName(QString::fromUtf8("Lab10onLab9Class"));
        Lab10onLab9Class->resize(600, 400);
        menuBar = new QMenuBar(Lab10onLab9Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Lab10onLab9Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab10onLab9Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lab10onLab9Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab10onLab9Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Lab10onLab9Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab10onLab9Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lab10onLab9Class->setStatusBar(statusBar);

        retranslateUi(Lab10onLab9Class);

        QMetaObject::connectSlotsByName(Lab10onLab9Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab10onLab9Class)
    {
        Lab10onLab9Class->setWindowTitle(QCoreApplication::translate("Lab10onLab9Class", "Lab10onLab9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab10onLab9Class: public Ui_Lab10onLab9Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB10ONLAB9_H
