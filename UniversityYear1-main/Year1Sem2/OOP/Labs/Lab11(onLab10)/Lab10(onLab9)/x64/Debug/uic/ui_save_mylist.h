/********************************************************************************
** Form generated from reading UI file 'save_mylist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_MYLIST_H
#define UI_SAVE_MYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveForm
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *title_save_label;
    QPushButton *enter_button_save_my_list;
    QLabel *error;

    void setupUi(QWidget *SaveForm)
    {
        if (SaveForm->objectName().isEmpty())
            SaveForm->setObjectName(QString::fromUtf8("SaveForm"));
        SaveForm->resize(625, 431);
        formLayoutWidget = new QWidget(SaveForm);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(200, 130, 160, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        title_save_label = new QLineEdit(formLayoutWidget);
        title_save_label->setObjectName(QString::fromUtf8("title_save_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, title_save_label);

        enter_button_save_my_list = new QPushButton(SaveForm);
        enter_button_save_my_list->setObjectName(QString::fromUtf8("enter_button_save_my_list"));
        enter_button_save_my_list->setGeometry(QRect(370, 260, 141, 41));
        error = new QLabel(SaveForm);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(120, 270, 161, 16));

        retranslateUi(SaveForm);

        QMetaObject::connectSlotsByName(SaveForm);
    } // setupUi

    void retranslateUi(QWidget *SaveForm)
    {
        SaveForm->setWindowTitle(QCoreApplication::translate("SaveForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("SaveForm", "Title", nullptr));
        enter_button_save_my_list->setText(QCoreApplication::translate("SaveForm", "Finish", nullptr));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SaveForm: public Ui_SaveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_MYLIST_H
