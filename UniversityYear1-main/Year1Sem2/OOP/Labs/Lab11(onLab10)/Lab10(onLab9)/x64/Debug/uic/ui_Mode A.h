/********************************************************************************
** Form generated from reading UI file 'Mode A.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_20_A_H
#define UI_MODE_20_A_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModeAForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *add_tape_button;
    QPushButton *update_tape_button;
    QPushButton *delete_tape_button_;
    QPushButton *list_tape_button;
    QPushButton *graph_button;

    void setupUi(QWidget *ModeAForm)
    {
        if (ModeAForm->objectName().isEmpty())
            ModeAForm->setObjectName(QString::fromUtf8("ModeAForm"));
        ModeAForm->resize(809, 582);
        verticalLayoutWidget = new QWidget(ModeAForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 140, 411, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_tape_button = new QPushButton(verticalLayoutWidget);
        add_tape_button->setObjectName(QString::fromUtf8("add_tape_button"));

        verticalLayout->addWidget(add_tape_button);

        update_tape_button = new QPushButton(verticalLayoutWidget);
        update_tape_button->setObjectName(QString::fromUtf8("update_tape_button"));

        verticalLayout->addWidget(update_tape_button);

        delete_tape_button_ = new QPushButton(verticalLayoutWidget);
        delete_tape_button_->setObjectName(QString::fromUtf8("delete_tape_button_"));

        verticalLayout->addWidget(delete_tape_button_);

        list_tape_button = new QPushButton(verticalLayoutWidget);
        list_tape_button->setObjectName(QString::fromUtf8("list_tape_button"));

        verticalLayout->addWidget(list_tape_button);

        graph_button = new QPushButton(verticalLayoutWidget);
        graph_button->setObjectName(QString::fromUtf8("graph_button"));

        verticalLayout->addWidget(graph_button);


        retranslateUi(ModeAForm);

        QMetaObject::connectSlotsByName(ModeAForm);
    } // setupUi

    void retranslateUi(QWidget *ModeAForm)
    {
        ModeAForm->setWindowTitle(QCoreApplication::translate("ModeAForm", "Form", nullptr));
        add_tape_button->setText(QCoreApplication::translate("ModeAForm", "ADD TAPE", nullptr));
        update_tape_button->setText(QCoreApplication::translate("ModeAForm", "UPDATE TAPE", nullptr));
        delete_tape_button_->setText(QCoreApplication::translate("ModeAForm", "DELETE TAPE", nullptr));
        list_tape_button->setText(QCoreApplication::translate("ModeAForm", "LIST TAPE", nullptr));
        graph_button->setText(QCoreApplication::translate("ModeAForm", "GRAPH ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModeAForm: public Ui_ModeAForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_20_A_H
