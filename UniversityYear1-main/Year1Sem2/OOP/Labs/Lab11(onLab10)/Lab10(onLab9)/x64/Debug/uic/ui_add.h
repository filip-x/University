/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddForm
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *title_label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *date_of_creation_label;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *access_count_label;
    QLineEdit *footage_preview_label;
    QLineEdit *section_label;
    QPushButton *finish_button;
    QLabel *error;

    void setupUi(QWidget *AddForm)
    {
        if (AddForm->objectName().isEmpty())
            AddForm->setObjectName(QString::fromUtf8("AddForm"));
        AddForm->resize(793, 483);
        formLayoutWidget = new QWidget(AddForm);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(220, 120, 261, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        title_label = new QLineEdit(formLayoutWidget);
        title_label->setObjectName(QString::fromUtf8("title_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, title_label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        date_of_creation_label = new QLineEdit(formLayoutWidget);
        date_of_creation_label->setObjectName(QString::fromUtf8("date_of_creation_label"));

        formLayout->setWidget(2, QFormLayout::FieldRole, date_of_creation_label);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        access_count_label = new QLineEdit(formLayoutWidget);
        access_count_label->setObjectName(QString::fromUtf8("access_count_label"));

        formLayout->setWidget(3, QFormLayout::FieldRole, access_count_label);

        footage_preview_label = new QLineEdit(formLayoutWidget);
        footage_preview_label->setObjectName(QString::fromUtf8("footage_preview_label"));

        formLayout->setWidget(4, QFormLayout::FieldRole, footage_preview_label);

        section_label = new QLineEdit(formLayoutWidget);
        section_label->setObjectName(QString::fromUtf8("section_label"));

        formLayout->setWidget(1, QFormLayout::FieldRole, section_label);

        finish_button = new QPushButton(AddForm);
        finish_button->setObjectName(QString::fromUtf8("finish_button"));
        finish_button->setGeometry(QRect(520, 350, 75, 23));
        error = new QLabel(AddForm);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(200, 280, 321, 21));

        retranslateUi(AddForm);

        QMetaObject::connectSlotsByName(AddForm);
    } // setupUi

    void retranslateUi(QWidget *AddForm)
    {
        AddForm->setWindowTitle(QCoreApplication::translate("AddForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddForm", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("AddForm", "Section", nullptr));
        label_3->setText(QCoreApplication::translate("AddForm", "Date of creation", nullptr));
        label_4->setText(QCoreApplication::translate("AddForm", "Access Count", nullptr));
        label_5->setText(QCoreApplication::translate("AddForm", "Footage Preview", nullptr));
        finish_button->setText(QCoreApplication::translate("AddForm", "Finidh", nullptr));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddForm: public Ui_AddForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
