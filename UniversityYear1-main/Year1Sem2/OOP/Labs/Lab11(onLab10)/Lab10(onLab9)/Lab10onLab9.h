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
	void mylist_location();
	void mode_a();
	void mode_b();
	void list();
	void show_graph();
	void add();
	void remove();
	void update();
	void filter();
	void list_mylist();
	void save_mylist();
	void finish_filter(vector<Tape*>);


private:
	Ui::Lab10onLab9Class ui;
	Service* controller;
	string path_to_file;
	string path_to_mylist;
};
