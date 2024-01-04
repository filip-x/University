#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPTest2.h"
#include "service.h"


class OOPTest2 : public QMainWindow
{
    Q_OBJECT

public:
    OOPTest2(QWidget *parent = Q_NULLPTR);
private:
    service Controller;
    Ui::OOPTest2Class ui;
    void update_buttons();
    static std::string car_to_string(car);
    void Tests();
};
