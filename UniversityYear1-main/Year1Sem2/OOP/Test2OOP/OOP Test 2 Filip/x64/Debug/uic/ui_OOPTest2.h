/********************************************************************************
** Form generated from reading UI file 'OOPTest2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOPTEST2_H
#define UI_OOPTEST2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OOPTest2Class
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *Display;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Property;
    QLineEdit *Input;
    QPushButton *Action1;
    QPushButton *Action2;
    QLabel *Output;
    QLabel *Error;

    void setupUi(QMainWindow *OOPTest2Class)
    {
        if (OOPTest2Class->objectName().isEmpty())
            OOPTest2Class->setObjectName(QString::fromUtf8("OOPTest2Class"));
        OOPTest2Class->resize(520, 292);
        centralWidget = new QWidget(OOPTest2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 498, 271));
        horizontalLayout_2 = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Display = new QListWidget(verticalLayoutWidget);
        Display->setObjectName(QString::fromUtf8("Display"));

        horizontalLayout_2->addWidget(Display);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        Property = new QLabel(verticalLayoutWidget);
        Property->setObjectName(QString::fromUtf8("Property"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Property);

        Input = new QLineEdit(verticalLayoutWidget);
        Input->setObjectName(QString::fromUtf8("Input"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Input);


        verticalLayout->addLayout(formLayout);

        Action1 = new QPushButton(verticalLayoutWidget);
        Action1->setObjectName(QString::fromUtf8("Action1"));

        verticalLayout->addWidget(Action1);

        Action2 = new QPushButton(verticalLayoutWidget);
        Action2->setObjectName(QString::fromUtf8("Action2"));

        verticalLayout->addWidget(Action2);

        Output = new QLabel(verticalLayoutWidget);
        Output->setObjectName(QString::fromUtf8("Output"));
        Output->setStyleSheet(QString::fromUtf8("color: blue;"));

        verticalLayout->addWidget(Output);

        Error = new QLabel(verticalLayoutWidget);
        Error->setObjectName(QString::fromUtf8("Error"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 127, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(255, 63, 63, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        Error->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        Error->setFont(font);
        Error->setAcceptDrops(false);
        Error->setAutoFillBackground(false);
        Error->setStyleSheet(QString::fromUtf8("color: red;"));
        Error->setScaledContents(false);

        verticalLayout->addWidget(Error);


        horizontalLayout_2->addLayout(verticalLayout);

        OOPTest2Class->setCentralWidget(centralWidget);

        retranslateUi(OOPTest2Class);

        QMetaObject::connectSlotsByName(OOPTest2Class);
    } // setupUi

    void retranslateUi(QMainWindow *OOPTest2Class)
    {
        OOPTest2Class->setWindowTitle(QCoreApplication::translate("OOPTest2Class", "Test OOP", nullptr));
        Property->setText(QCoreApplication::translate("OOPTest2Class", "Property", nullptr));
        Action1->setText(QCoreApplication::translate("OOPTest2Class", "Action 1", nullptr));
        Action2->setText(QCoreApplication::translate("OOPTest2Class", "Action 2", nullptr));
        Output->setText(QCoreApplication::translate("OOPTest2Class", "Extra Output", nullptr));
        Error->setText(QCoreApplication::translate("OOPTest2Class", "Error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOPTest2Class: public Ui_OOPTest2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOPTEST2_H
