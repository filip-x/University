/********************************************************************************
** Form generated from reading UI file 'update.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_H
#define UI_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateForm
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *section_update_label;
    QLabel *label_5;
    QLineEdit *date_of_creation_update_label;
    QLabel *label_3;
    QLineEdit *access_count_update_label;
    QLabel *label_2;
    QLineEdit *footage_preview_update_label;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *title_update_label;
    QPushButton *finish_button;
    QLabel *error;

    void setupUi(QWidget *UpdateForm)
    {
        if (UpdateForm->objectName().isEmpty())
            UpdateForm->setObjectName(QString::fromUtf8("UpdateForm"));
        UpdateForm->resize(805, 300);
        formLayoutWidget = new QWidget(UpdateForm);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(390, 40, 160, 126));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        section_update_label = new QLineEdit(formLayoutWidget);
        section_update_label->setObjectName(QString::fromUtf8("section_update_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, section_update_label);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        date_of_creation_update_label = new QLineEdit(formLayoutWidget);
        date_of_creation_update_label->setObjectName(QString::fromUtf8("date_of_creation_update_label"));

        formLayout->setWidget(1, QFormLayout::FieldRole, date_of_creation_update_label);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        access_count_update_label = new QLineEdit(formLayoutWidget);
        access_count_update_label->setObjectName(QString::fromUtf8("access_count_update_label"));

        formLayout->setWidget(2, QFormLayout::FieldRole, access_count_update_label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        footage_preview_update_label = new QLineEdit(formLayoutWidget);
        footage_preview_update_label->setObjectName(QString::fromUtf8("footage_preview_update_label"));

        formLayout->setWidget(3, QFormLayout::FieldRole, footage_preview_update_label);

        formLayoutWidget_2 = new QWidget(UpdateForm);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(70, 60, 160, 41));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        title_update_label = new QLineEdit(formLayoutWidget_2);
        title_update_label->setObjectName(QString::fromUtf8("title_update_label"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, title_update_label);

        finish_button = new QPushButton(UpdateForm);
        finish_button->setObjectName(QString::fromUtf8("finish_button"));
        finish_button->setGeometry(QRect(550, 240, 75, 23));
        error = new QLabel(UpdateForm);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(230, 190, 211, 21));

        retranslateUi(UpdateForm);

        QMetaObject::connectSlotsByName(UpdateForm);
    } // setupUi

    void retranslateUi(QWidget *UpdateForm)
    {
        UpdateForm->setWindowTitle(QCoreApplication::translate("UpdateForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("UpdateForm", "Section", nullptr));
        label_5->setText(QCoreApplication::translate("UpdateForm", "Date of creation", nullptr));
        label_3->setText(QCoreApplication::translate("UpdateForm", "Access Count", nullptr));
        label_2->setText(QCoreApplication::translate("UpdateForm", "Footage Preview", nullptr));
        label_4->setText(QCoreApplication::translate("UpdateForm", "Title", nullptr));
        finish_button->setText(QCoreApplication::translate("UpdateForm", "Finish", nullptr));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UpdateForm: public Ui_UpdateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_H
