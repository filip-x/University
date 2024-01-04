#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Final_Exam_Practical.h"
#include "service.h"
#include "modul.h"
class Observer
{
public:
    virtual ~Observer() = 0 {};
    virtual void Update() = 0;
};

class Gui
{
private:
   
    std::vector<Observer*> observers;
public:
    Gui();
    Service service;
    void register_observer(Observer*);
    void unregister_observer(Observer*);
    void notify_all();
    
};


class Final_Exam_Practical : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    Final_Exam_Practical(Astronomer, Gui*, QWidget *parent = Q_NULLPTR);
    ~Final_Exam_Practical();
    void Update() override;
    std::string star_to_string(Stars element);

private:
    Ui::Final_Exam_PracticalClass ui;
    Astronomer principal;
    Gui* main;
    Model* model;
};


