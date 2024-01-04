#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab10onLab9.h"
#include "service.h"
class Lab10onLab9 : public QMainWindow
{
	Q_OBJECT

public:
	Lab10onLab9(QWidget *parent = Q_NULLPTR);
	void build_screen();
	void file_location();
	void mode_a();
	void list();
	void show_graph();
private:
	Ui::Lab10onLab9Class ui;
	Service* controller;
};
