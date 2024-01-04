#include "Final_Exam_Practical.h"
#include <QPushButton>
#include <QDebug>
#include <string>
#include <QMessageBox>
#include "exceptions.h"
//search is  not conected 
using namespace std;

Final_Exam_Practical::Final_Exam_Practical(Astronomer principal, Gui* main, QWidget *parent) : principal(principal), main(main), QMainWindow(parent)
{
    this->setWindowTitle(QString::fromStdString(principal.get_name()));
    ui.setupUi(this);
    main->register_observer(this);
    model = new Model(main->service);
    auto Button = this->findChild<QPushButton*>("Button");
    QObject::connect(Button, &QPushButton::clicked, this, [=]() {
        qDebug() << "Clicked!";
        main->notify_all();
        });
    auto Table = this->findChild<QTableView*>("List1");
    auto List = this->findChild<QListWidget*>("List2");
    Table->setModel(model);
 
    auto Name = this->findChild<QLineEdit*>("lable_name");
    auto Const = this->findChild<QLineEdit*>("lable_constelation");
    auto RA = this->findChild<QLineEdit*>("lable_ra");
    auto Dec = this->findChild<QLineEdit*>("lable_dec");
    auto Diameter = this->findChild<QLineEdit*>("lable_diameter");
    auto addb = this->findChild<QPushButton*>("add_button");
    QObject::connect(addb, &QPushButton::clicked, this, [=]() {
        try {
            if (Name->text().size() == 0)
                throw Exception("Name of the star is empty");
            string name = Name->text().toStdString();
            string constellation = Const->text().toStdString();
            int ra = std::stoi(RA->text().toStdString());
            int dec = std::stoi(Dec->text().toStdString());
            int diameter = std::stoi(Diameter->text().toStdString());
            if (Diameter <= 0)
                throw Exception("Diameter can't be smaller or equal to 0");
            main->service.add2(name, constellation, ra, dec, diameter);
            main->notify_all();
        }
        catch(Exception& error)
        {
            QMessageBox msgBox;
            msgBox.setText(error.what());
        }
        });

    auto search_label = this->findChild<QLineEdit*>("label_search");
    QObject::connect(search_label , &QLineEdit::textChanged, [=]() {
        try {
            // We ask the service to retrieve all the matching elements... (check service for extra info)
            List->clear();
            auto Data = main->service.search_stars(search_label->text().toStdString());
            int RowNumber = 0;
            for (auto Element : Data)
            {
                List->insertItem(RowNumber++, QString::fromStdString(star_to_string(Element)));
            }
        }
        catch (Exception& error)
        {
            QMessageBox msgBox;
            msgBox.setText(error.what());
        }
        });
    
}

Gui::Gui()
{
    service.read_file("Data1.txt");
    service.read_file2("Data2.txt");
    auto elements = service.list();
    for (auto element : elements)
    {
        Final_Exam_Practical* w = new Final_Exam_Practical(element, this);
        w->show();
    }
    
}

void Gui::register_observer(Observer* obs)
{
    observers.push_back(obs);
}

void Gui::unregister_observer(Observer* obs)
{
    for (int i = 0; i < observers.size(); i++)
    {
        if (observers[i] == obs)
        {
            observers.erase(observers.begin() + i);
            break;
        }
    }
}

void Gui::notify_all()
{
    for (auto obs : observers)
        obs->Update();
}

Final_Exam_Practical::~Final_Exam_Practical()
{
    main->unregister_observer(this);
}

void Final_Exam_Practical::Update()
{
    this->model->reset();
}

string Final_Exam_Practical::star_to_string(Stars element)
{
    return element.get_name() + " | " + element.get_constelation();
}
