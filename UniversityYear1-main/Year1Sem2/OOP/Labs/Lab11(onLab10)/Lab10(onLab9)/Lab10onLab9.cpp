#include "Lab10onLab9.h"
#include <QLayout>
#include <QPushButton>
#include <QFileDialog>
#include "file_repository.h"
#include <QTableWidget>
#include <QHeaderView>
#include "qcustomplot.h"
#include "ui_Mode A.h"
#include "ui_Mode B.h"
#include "ui_add.h"
#include "ui_delete.h"
#include "ui_update.h"
#include"ui_list.h"
#include"ui_filter.h"
#include"ui_list_mylist.h"
#include "string"
#include "ctime"
#include "ui_save_mylist.h"
#include <fstream>
#include "repository.h"
#include "my_list_inmemory.h"
typedef tm Date;
using namespace std;
Lab10onLab9::Lab10onLab9(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	path_to_file = "";
	path_to_mylist = "";
	controller = NULL;
	build_screen();
}

void Lab10onLab9::file_location()
{
	QString path = QFileDialog::getOpenFileName(this, "Select a file", "/", "File (*.txt)");
	if (path != "")
	{
		path_to_file = path.toStdString();
		if (path_to_mylist != "")
		{
			if (this->controller != NULL)
				delete controller;
			auto repo = new File_Repository(path.toStdString());
			Repo_my_list* my_list;
			if (path_to_mylist.substr(path_to_mylist.rfind('.') + 1, 3) == "csv")
				my_list = new My_list_CSV(path_to_mylist);
			else if (path_to_mylist.substr(path_to_mylist.rfind('.') + 1, 3) == "htm")
				my_list = new My_list_html(path_to_mylist);
			else if (path_to_mylist == "-1")
				my_list = new My_list_InMemory;
			this->controller = new Service(repo, my_list);
			
			this->centralWidget()->layout()->itemAt(0)->widget()->setEnabled(true);
			this->centralWidget()->layout()->itemAt(1)->widget()->setEnabled(true);
		}
	}
}

void Lab10onLab9::mylist_location()
{
	QString path = QFileDialog::getOpenFileName(this, "Select a file", "/", "File (*.html *.csv)");
	if (path != "")
	{
		path_to_mylist = path.toStdString();
		if (path_to_file != "")
		{
			if (this->controller != NULL)
				delete controller;
			Repository_Inherit* repo;
			if (path_to_file == "-1")
				repo = new Repository;
			else
				repo = new File_Repository(path_to_file);
			Repo_my_list* my_list;
			if (path_to_mylist.substr(path_to_mylist.rfind('.') + 1, 3) == "csv")
				my_list = new My_list_CSV(path_to_mylist);
			else if (path_to_mylist.substr(path_to_mylist.rfind('.') + 1, 3) == "htm")
				my_list = new My_list_html(path_to_mylist);
			this->controller = new Service(repo, my_list);
			this->centralWidget()->layout()->itemAt(0)->widget()->setEnabled(true);
			this->centralWidget()->layout()->itemAt(1)->widget()->setEnabled(true);
		}
	}
}

void Lab10onLab9::mode_a()
{

	auto Form = new Ui_ModeAForm;
	QWidget* FormWindow = new QWidget();
	Form->setupUi(FormWindow);
	FormWindow->show();
	QObject::connect(Form->add_tape_button, &QPushButton::clicked, this, &Lab10onLab9::add);
	QObject::connect(Form->delete_tape_button_, &QPushButton::clicked, this, &Lab10onLab9::remove);
	QObject::connect(Form->update_tape_button, &QPushButton::clicked, this, &Lab10onLab9::update);
	QObject::connect(Form->list_tape_button, &QPushButton::clicked, this, &Lab10onLab9::list);
	QObject::connect(Form->graph_button, &QPushButton::clicked, this, &Lab10onLab9::show_graph);
}
inline string date_to_string(Date date_to_display)
{
	char string_date[100];
	sprintf(string_date, "%d-%d-%d", date_to_display.tm_mon, date_to_display.tm_mday, date_to_display.tm_year);
	return string(string_date);
}
void Lab10onLab9::mode_b()
{
	this->controller->creating_the_iterator();
	auto Form = new Ui_ModeBForm;
	QWidget* FormWindow = new QWidget();
	Form->setupUi(FormWindow);
	FormWindow->show();
	QObject::connect(Form->next_button, &QPushButton::clicked, this, [=]() {
		Form->display_label->clear();
		try {
			auto next_element = this->controller->next_tape();
			if (next_element == NULL)
				return;
			Form->display_label->addItem("Title: " + QString::fromStdString(next_element->get_title()));
			Form->display_label->addItem("Section: " + QString::fromStdString(next_element->get_section()));
			Form->display_label->addItem("Date of Creation: " + QString::fromStdString(date_to_string(next_element->get_date_of_creation())));
			Form->display_label->addItem("Access Count: " + QString::fromStdString(std::to_string(next_element->get_access_count())));
			Form->display_label->addItem("Footage Preview: " + QString::fromStdString(next_element->get_footage_preview()));
		}
		catch (exception&)
		{
			
		}
		});
	QObject::connect(Form->save_tape_button, &QPushButton::clicked, this, &Lab10onLab9::save_mylist);
	QObject::connect(Form->print_my_list_button, &QPushButton::clicked, this, &Lab10onLab9::list_mylist);
	QObject::connect(Form->filter_button, &QPushButton::clicked, this, &Lab10onLab9::filter);
	QObject::connect(Form->open_my_list_button, &QPushButton::clicked, this, [=]() {
		this->controller->open_my_list();
		});
	if (path_to_mylist == "-1")
		Form->open_my_list_button->setEnabled(false);
}


void Lab10onLab9::list()
{
	auto Form = new Ui_ListForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QStringList header;
	header.append("Title");
	header.append("Section");
	header.append("Date of creation");
	header.append("Access count");
	header.append("Footage preview");
	Form->table_list->setColumnCount(5);
	Form->table_list->setHorizontalHeaderLabels(header);
	Form->table_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	Form->table_list->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	int row = 0;
	auto vector_current_element = this->controller->list_function();
	for (auto curent_element : vector_current_element)
	{
		Form->table_list->insertRow(row);
		auto item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_title()));
		Form->table_list->setItem(row, 0, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_section()));
		Form->table_list->setItem(row, 1, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(date_to_string(curent_element->get_date_of_creation())));
		Form->table_list->setItem(row, 2, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(std::to_string(curent_element->get_access_count())));
		Form->table_list->setItem(row, 3, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_footage_preview()));
		Form->table_list->setItem(row, 4, item);
		row++;
	}
}

void Lab10onLab9::show_graph()
{
	auto widget = new QWidget();
	//Window->setFixedSize(QSize(1000, 600));
	widget->setFixedSize(QSize(800, 600));
	// Create empty bar chart objects:
	auto custom_plot = new QCustomPlot();
	auto Layout = new QVBoxLayout();
	widget->setLayout(Layout);
	Layout->addWidget(custom_plot);
	auto elements = this->controller->list_function();

	QCPBars* access_count_bar = new QCPBars(custom_plot->xAxis, custom_plot->yAxis);
	access_count_bar->setWidth(0.75);

	// Gives more crisp, pixel aligned bar borders
	access_count_bar->setAntialiased(false);

	// Set names and colors:
	access_count_bar->setName("Access count");
	access_count_bar->setPen(QPen(QColor(255, 0, 0).lighter()));
	access_count_bar->setBrush(QColor(255, 0, 0));

	// prepare x axis with country labels:
	QVector<double> ticks;
	QVector<QString> labels;
	int tick = 1;
	QVector<double> access_count_data;
	for (auto current_element : elements)
	{
		ticks << tick;
		labels << QString::fromStdString(current_element->get_title());
		access_count_data << current_element->get_access_count();
		tick++;
	}
	QSharedPointer<QCPAxisTickerText> text_ticker(new QCPAxisTickerText);
	text_ticker->addTicks(ticks, labels);
	custom_plot->xAxis->setTicker(text_ticker);
	custom_plot->xAxis->setTickLabelRotation(60);
	custom_plot->xAxis->setSubTicks(false);
	custom_plot->xAxis->setTickLength(0, 2);
	custom_plot->xAxis->setRange(0, elements.size() + 1);
	custom_plot->xAxis->setBasePen(QPen(Qt::black));
	custom_plot->xAxis->setTickPen(QPen(Qt::black));
	custom_plot->xAxis->grid()->setVisible(true);
	custom_plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
	custom_plot->xAxis->setTickLabelColor(Qt::black);
	custom_plot->xAxis->setLabelColor(Qt::black);

	// prepare y axis:
	custom_plot->yAxis->setRangeUpper(20);
	custom_plot->yAxis->setPadding(5); // a bit more space to the left border
	custom_plot->yAxis->setLabel("Access count");
	custom_plot->yAxis->setBasePen(QPen(Qt::black));
	custom_plot->yAxis->setTickPen(QPen(Qt::black));
	custom_plot->yAxis->setSubTickPen(QPen(Qt::black));
	custom_plot->yAxis->grid()->setSubGridVisible(true);
	custom_plot->yAxis->setTickLabelColor(Qt::black);
	custom_plot->yAxis->setLabelColor(Qt::black);
	custom_plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
	custom_plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

	// Add data:
	access_count_bar->setData(ticks, access_count_data);

	// setup legend:
	custom_plot->legend->setVisible(true);
	custom_plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignHCenter);
	custom_plot->legend->setBrush(QColor(255, 255, 255, 100));
	custom_plot->legend->setBorderPen(Qt::NoPen);
	QFont legendFont = font();
	legendFont.setPointSize(10);
	custom_plot->legend->setFont(legendFont);

	widget->show();
}

inline Date string_to_date(string date)
{
	int day, year, month;
	int placeholder = sscanf(date.c_str(), "%d-%d-%d", &month, &day, &year);
	Date date_of_creation;
	date_of_creation.tm_mon = month;
	date_of_creation.tm_mday = day;
	date_of_creation.tm_year = year;
	return date_of_creation;
}
void Lab10onLab9::add()
{
	// TO DO ERRORS

	auto Form = new Ui_AddForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QObject::connect(Form->finish_button, &QPushButton::clicked, this, [=](){
		try {
			string title = Form->title_label->text().toStdString();
			string section = Form->section_label->text().toStdString();
			Date date_of_creation = string_to_date(Form->date_of_creation_label->text().toStdString());
			int access_count = stoi(Form->access_count_label->text().toStdString());
			string footage_preview = Form->footage_preview_label->text().toStdString();
			this->controller->append_function(title, section, date_of_creation, access_count, footage_preview);
			widget->close();
		}
		catch (exception& app)
		{
			Form->error->setText(app.what());
		}
	});
	

}


void Lab10onLab9::remove()
{
	auto Form = new Ui_DeleteForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QObject::connect(Form->finish_button, &QPushButton::clicked, this, [=](){
		try
		{
			this->controller->delete_function(Form->title_update_label->text().toStdString());
			widget->close();
		}
		catch (const std::exception& app)
		{
			Form->error->setText(app.what());
		} 
			
	});
}

void Lab10onLab9::update()
{
	auto Form = new Ui_UpdateForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QObject::connect(Form->finish_button, &QPushButton::clicked, this, [=](){
		try
		{
			this->controller->update_function(Form->title_update_label->text().toStdString(), Form->section_update_label->text().toStdString(), string_to_date(Form->date_of_creation_update_label->text().toStdString()), stoi(Form->access_count_update_label->text().toStdString()), Form->footage_preview_update_label->text().toStdString());
			widget->close();
		}
		catch (const std::exception& app)
		{
			Form->error->setText(app.what());
		}
			
	});
}

void Lab10onLab9::filter()
{
	auto Form = new Ui_FilterForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QObject::connect(Form->enter_button, &QPushButton::clicked, this, [=]() {
		try
		{
			finish_filter(this->controller->list_by_section_access(Form->section_filter_label->text().toStdString(), stoi(Form->access_count_filter_label->text().toStdString())));
			//widget->close();
		}
		catch (const std::exception& app)
		{
			Form->error->setText(app.what());
		}

		});
}

void Lab10onLab9::finish_filter(vector<Tape*> list)
{
	auto Form = new Ui_ListMylistForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QStringList header;
	header.append("Title");
	header.append("Section");
	header.append("Date of creation");
	header.append("Access count");
	header.append("Footage preview");
	Form->table_list_mylist->setColumnCount(5);
	Form->table_list_mylist->setHorizontalHeaderLabels(header);
	Form->table_list_mylist->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	Form->table_list_mylist->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	int row = 0;
	auto vector_current_element = list;
	for (auto curent_element : vector_current_element)
	{
		Form->table_list_mylist->insertRow(row);
		auto item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_title()));
		Form->table_list_mylist->setItem(row, 0, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_section()));
		Form->table_list_mylist->setItem(row, 1, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(date_to_string(curent_element->get_date_of_creation())));
		Form->table_list_mylist->setItem(row, 2, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(std::to_string(curent_element->get_access_count())));
		Form->table_list_mylist->setItem(row, 3, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_footage_preview()));
		Form->table_list_mylist->setItem(row, 4, item);
		row++;
	}
}
void Lab10onLab9::list_mylist()
{
	auto Form = new Ui_ListMylistForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QStringList header;
	header.append("Title");
	header.append("Section");
	header.append("Date of creation");
	header.append("Access count");
	header.append("Footage preview");
	Form->table_list_mylist->setColumnCount(5);
	Form->table_list_mylist->setHorizontalHeaderLabels(header);
	Form->table_list_mylist->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	Form->table_list_mylist->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	int row = 0;
	auto vector_current_element = this->controller->list_my_list();
	for (auto curent_element : vector_current_element)
	{
		Form->table_list_mylist->insertRow(row);
		auto item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_title()));
		Form->table_list_mylist->setItem(row, 0, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_section()));
		Form->table_list_mylist->setItem(row, 1, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(date_to_string(curent_element->get_date_of_creation())));
		Form->table_list_mylist->setItem(row, 2, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(std::to_string(curent_element->get_access_count())));
		Form->table_list_mylist->setItem(row, 3, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_footage_preview()));
		Form->table_list_mylist->setItem(row, 4, item);
		row++;
	}
}

void Lab10onLab9::save_mylist()
{
	auto Form = new Ui_SaveForm;
	QWidget* widget = new QWidget;
	Form->setupUi(widget);
	widget->show();
	QObject::connect(Form->enter_button_save_my_list, &QPushButton::clicked, this, [=]() {
		try
		{
			this->controller->save_tape_by_title(Form->title_save_label->text().toStdString());
			widget->close();
		}
		catch (const std::exception& app)
		{
			Form->error->setText(app.what());
		}

		});
}



void Lab10onLab9::build_screen()
{
	QWidget* widg = new QWidget;
	QHBoxLayout* layout = new QHBoxLayout();// V for vertical and H for horizontal
	widg->setLayout(layout);
	auto mode_A_button = new QPushButton;
	auto mode_B_button = new QPushButton;
	layout->addWidget(mode_A_button);
	layout->addWidget(mode_B_button);
	this->setCentralWidget(widg);
	mode_A_button->setText("mode A");
	mode_B_button->setText("mode B");
	mode_A_button->setFixedSize(QSize(200,200));
	mode_B_button->setFixedSize(QSize(200,200));
	auto topbar = this->menuBar()->addMenu("Files");
	auto file_location = new QAction("Open file location");
	auto mylist_location = new QAction("Open mylist location");
	topbar->addAction(file_location);
	topbar->addAction(mylist_location);
	mode_A_button->setEnabled(false);
	mode_B_button->setEnabled(false);
	QObject::connect(file_location, &QAction::triggered, this, &Lab10onLab9::file_location);
	QObject::connect(mylist_location, &QAction::triggered, this, &Lab10onLab9::mylist_location);
	QObject::connect(mode_A_button, &QPushButton::clicked, this, &Lab10onLab9::mode_a);
	QObject::connect(mode_B_button, &QPushButton::clicked, this, &Lab10onLab9::mode_b);
	
	ifstream fin("configuration.config");
	string Line1, Line2;
	getline(fin, Line1);
	getline(fin, Line2);
	fin.close();

	if (Line1.find("true") != string::npos)
	{
		file_location->setEnabled(false);
		path_to_file = "-1";
	}
	if (Line2.find("true") != string::npos)
	{
		mylist_location->setEnabled(false);
		path_to_mylist = "-1";
	}
	if (path_to_file == "-1" && path_to_mylist == "-1")
	{
		mode_A_button->setEnabled(true);
		mode_B_button->setEnabled(true);
		controller = new Service(new Repository, new My_list_InMemory);
	}
}

