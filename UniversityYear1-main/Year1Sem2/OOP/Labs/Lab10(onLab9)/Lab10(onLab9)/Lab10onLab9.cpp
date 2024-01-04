#include "Lab10onLab9.h"
#include <QLayout>
#include <QPushButton>
#include <QFileDialog>
#include "file_repository.h"
#include <QTableWidget>
#include <QHeaderView>
#include "qcustomplot.h"
Lab10onLab9::Lab10onLab9(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	build_screen();
}

void Lab10onLab9::file_location()
{
	QString path = QFileDialog::getOpenFileName(this, "Select a file", "/", "File (*.txt)");
	if (path != "")
	{
		auto repo = new File_Repository(path.toStdString());
		this->controller = new Service(repo);
		this->centralWidget()->layout()->itemAt(0)->widget()->setEnabled(true);
	}
}

void Lab10onLab9::mode_a()
{
	QWidget* widg = new QWidget;
	QVBoxLayout* layout = new QVBoxLayout();// V for vertical and H for horizontal
	widg->setLayout(layout);
	widg->setFixedSize(QSize(200, 300));
	auto add_button = new QPushButton("Add Tape");
	auto delete_button = new QPushButton("Delete Tape");
	auto update_button = new QPushButton("Update Tape");
	auto list_button = new QPushButton("List Tape");
	auto graph_button = new QPushButton("Graph");
	layout->addWidget(graph_button);
	layout->addWidget(add_button);
	layout->addWidget(delete_button);
	layout->addWidget(update_button);
	layout->addWidget(list_button);
	widg->show();
	QObject::connect(list_button, &QPushButton::clicked, this, &Lab10onLab9::list);
	QObject::connect(graph_button, &QPushButton::clicked, this, &Lab10onLab9::show_graph);
}

inline string date_to_string(Date date_to_display)
{
	char string_date[100];
	sprintf(string_date, "%d-%d-%d", date_to_display.tm_mon, date_to_display.tm_mday, date_to_display.tm_year);
	return string(string_date);
}

void Lab10onLab9::list()
{
	QWidget* widget = new QWidget;
	widget->show();
	widget->setFixedSize(500, 300);
	auto table = new QTableWidget;
	QStringList header;
	header.append("Title");
	header.append("Section");
	header.append("Date of creation");
	header.append("Access count");
	header.append("Footage preview");
	table->setColumnCount(5);
	table->setHorizontalHeaderLabels(header);
	table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	int row = 0;
	auto vector_current_element = this->controller->list_function();
	for (auto curent_element : vector_current_element)
	{
		table->insertRow(row);
		auto item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_title()));
		table->setItem(row, 0, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_section()));
		table->setItem(row, 1, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(date_to_string(curent_element->get_date_of_creation())));
		table->setItem(row, 2, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(std::to_string(curent_element->get_access_count())));
		table->setItem(row, 3, item);
		item = new QTableWidgetItem();
		item->setText(QString::fromStdString(curent_element->get_footage_preview()));
		table->setItem(row, 4, item);
		row++;
	}
	auto layout = new QVBoxLayout();
	widget->setLayout(layout);
	layout->addWidget(table);
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
	topbar->addAction(file_location);
	mode_A_button->setEnabled(false);
	mode_B_button->setEnabled(false);
	QObject::connect(file_location, &QAction::triggered, this, &Lab10onLab9::file_location);
	QObject::connect(mode_A_button, &QPushButton::clicked, this, &Lab10onLab9::mode_a);
}
