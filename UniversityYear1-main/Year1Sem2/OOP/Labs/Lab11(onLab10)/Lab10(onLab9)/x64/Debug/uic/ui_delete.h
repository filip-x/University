/********************************************************************************
** Form generated from reading UI file 'delete.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_H
#define UI_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteForm
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *title_update_label;
    QLabel *label;
    QPushButton *finish_button;
    QLabel *error;

    void setupUi(QWidget *DeleteForm)
    {
        if (DeleteForm->objectName().isEmpty())
            DeleteForm->setObjectName(QString::fromUtf8("DeleteForm"));
        DeleteForm->resize(630, 395);
        formLayoutWidget = new QWidget(DeleteForm);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(210, 130, 160, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        title_update_label = new QLineEdit(formLayoutWidget);
        title_update_label->setObjectName(QString::fromUtf8("title_update_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, title_update_label);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        finish_button = new QPushButton(DeleteForm);
        finish_button->setObjectName(QString::fromUtf8("finish_button"));
        finish_button->setGeometry(QRect(440, 280, 75, 23));
        error = new QLabel(DeleteForm);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(210, 230, 191, 16));

        retranslateUi(DeleteForm);

        QMetaObject::connectSlotsByName(DeleteForm);
    } // setupUi

    void retranslateUi(QWidget *DeleteForm)
    {
        DeleteForm->setWindowTitle(QCoreApplication::translate("DeleteForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("DeleteForm", "Title", nullptr));
        finish_button->setText(QCoreApplication::translate("DeleteForm", "Finish", nullptr));
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeleteForm: public Ui_DeleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_H
