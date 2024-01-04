/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_H
#define UI_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListForm
{
public:
    QTableWidget *table_list;

    void setupUi(QWidget *ListForm)
    {
        if (ListForm->objectName().isEmpty())
            ListForm->setObjectName(QString::fromUtf8("ListForm"));
        ListForm->resize(677, 430);
        table_list = new QTableWidget(ListForm);
        table_list->setObjectName(QString::fromUtf8("table_list"));
        table_list->setGeometry(QRect(110, 70, 431, 261));

        retranslateUi(ListForm);

        QMetaObject::connectSlotsByName(ListForm);
    } // setupUi

    void retranslateUi(QWidget *ListForm)
    {
        ListForm->setWindowTitle(QCoreApplication::translate("ListForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListForm: public Ui_ListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_H
