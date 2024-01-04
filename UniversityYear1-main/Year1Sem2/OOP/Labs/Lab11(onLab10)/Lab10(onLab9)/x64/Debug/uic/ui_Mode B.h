/********************************************************************************
** Form generated from reading UI file 'Mode B.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_20_B_H
#define UI_MODE_20_B_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModeBForm
{
public:
    QPushButton *next_button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *save_tape_button;
    QPushButton *print_my_list_button;
    QPushButton *filter_button;
    QPushButton *open_my_list_button;
    QListWidget *display_label;

    void setupUi(QWidget *ModeBForm)
    {
        if (ModeBForm->objectName().isEmpty())
            ModeBForm->setObjectName(QString::fromUtf8("ModeBForm"));
        ModeBForm->resize(849, 555);
        next_button = new QPushButton(ModeBForm);
        next_button->setObjectName(QString::fromUtf8("next_button"));
        next_button->setGeometry(QRect(510, 300, 201, 23));
        verticalLayoutWidget = new QWidget(ModeBForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 280, 261, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        save_tape_button = new QPushButton(verticalLayoutWidget);
        save_tape_button->setObjectName(QString::fromUtf8("save_tape_button"));

        verticalLayout->addWidget(save_tape_button);

        print_my_list_button = new QPushButton(verticalLayoutWidget);
        print_my_list_button->setObjectName(QString::fromUtf8("print_my_list_button"));

        verticalLayout->addWidget(print_my_list_button);

        filter_button = new QPushButton(verticalLayoutWidget);
        filter_button->setObjectName(QString::fromUtf8("filter_button"));

        verticalLayout->addWidget(filter_button);

        open_my_list_button = new QPushButton(verticalLayoutWidget);
        open_my_list_button->setObjectName(QString::fromUtf8("open_my_list_button"));

        verticalLayout->addWidget(open_my_list_button);

        display_label = new QListWidget(ModeBForm);
        display_label->setObjectName(QString::fromUtf8("display_label"));
        display_label->setGeometry(QRect(60, 40, 691, 192));

        retranslateUi(ModeBForm);

        QMetaObject::connectSlotsByName(ModeBForm);
    } // setupUi

    void retranslateUi(QWidget *ModeBForm)
    {
        ModeBForm->setWindowTitle(QCoreApplication::translate("ModeBForm", "Form", nullptr));
        next_button->setText(QCoreApplication::translate("ModeBForm", "Next", nullptr));
        save_tape_button->setText(QCoreApplication::translate("ModeBForm", "Save Tape", nullptr));
        print_my_list_button->setText(QCoreApplication::translate("ModeBForm", "Print MyList", nullptr));
        filter_button->setText(QCoreApplication::translate("ModeBForm", "Filter", nullptr));
        open_my_list_button->setText(QCoreApplication::translate("ModeBForm", "Open MyList", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModeBForm: public Ui_ModeBForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_20_B_H
