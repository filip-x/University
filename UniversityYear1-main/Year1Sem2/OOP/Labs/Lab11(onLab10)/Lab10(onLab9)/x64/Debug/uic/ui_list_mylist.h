/********************************************************************************
** Form generated from reading UI file 'list_mylist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_MYLIST_H
#define UI_LIST_MYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListMylistForm
{
public:
    QTableWidget *table_list_mylist;

    void setupUi(QWidget *ListMylistForm)
    {
        if (ListMylistForm->objectName().isEmpty())
            ListMylistForm->setObjectName(QString::fromUtf8("ListMylistForm"));
        ListMylistForm->resize(674, 411);
        table_list_mylist = new QTableWidget(ListMylistForm);
        table_list_mylist->setObjectName(QString::fromUtf8("table_list_mylist"));
        table_list_mylist->setGeometry(QRect(90, 80, 431, 251));

        retranslateUi(ListMylistForm);

        QMetaObject::connectSlotsByName(ListMylistForm);
    } // setupUi

    void retranslateUi(QWidget *ListMylistForm)
    {
        ListMylistForm->setWindowTitle(QCoreApplication::translate("ListMylistForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListMylistForm: public Ui_ListMylistForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_MYLIST_H
