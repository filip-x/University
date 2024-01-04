/********************************************************************************
** Form generated from reading UI file 'filter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_H
#define UI_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterForm
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *section_filter_label;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLineEdit *access_count_filter_label;
    QLabel *label;
    QPushButton *enter_button;
    QLabel *error;

    void setupUi(QWidget *FilterForm)
    {
        if (FilterForm->objectName().isEmpty())
            FilterForm->setObjectName(QString::fromUtf8("FilterForm"));
        FilterForm->resize(645, 402);
        formLayoutWidget = new QWidget(FilterForm);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(90, 80, 160, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        section_filter_label = new QLineEdit(formLayoutWidget);
        section_filter_label->setObjectName(QString::fromUtf8("section_filter_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, section_filter_label);

        formLayoutWidget_2 = new QWidget(FilterForm);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(310, 80, 201, 80));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        access_count_filter_label = new QLineEdit(formLayoutWidget_2);
        access_count_filter_label->setObjectName(QString::fromUtf8("access_count_filter_label"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, access_count_filter_label);

        label = new QLabel(formLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        enter_button = new QPushButton(FilterForm);
        enter_button->setObjectName(QString::fromUtf8("enter_button"));
        enter_button->setGeometry(QRect(230, 220, 75, 23));
        error = new QLabel(FilterForm);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(150, 250, 141, 16));

        retranslateUi(FilterForm);

        QMetaObject::connectSlotsByName(FilterForm);
    } // setupUi

    void retranslateUi(QWidget *FilterForm)
    {
        FilterForm->setWindowTitle(QCoreApplication::translate("FilterForm", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("FilterForm", "Section", nullptr));
        label->setText(QCoreApplication::translate("FilterForm", "Access Count", nullptr));
        enter_button->setText(QCoreApplication::translate("FilterForm", "Finish", nullptr));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FilterForm: public Ui_FilterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_H
