#include "OOPTest2.h"
#include <QLabel>
#include <algorithm>
#include "Definitions.h"
using namespace std;

OOPTest2::OOPTest2(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    update_buttons();
}

void OOPTest2::update_buttons()
{
    // Finding all of the widgets...
    auto ErrorOutput = this->findChild<QLabel*>("Error");
    auto ExtraOutput = this->findChild<QLabel*>("Output");
    auto DisplayList = this->findChild<QListWidget*>("Display");
    auto ActionButton1 = this->findChild<QPushButton*>("Action1");
    auto ActionButton2 = this->findChild<QPushButton*>("Action2");
    auto PropertyLabel = this->findChild<QLabel*>("Property");
    auto Input = this->findChild<QLineEdit*>("Input");

    // Setting them up initially...
    ErrorOutput->setText("");
    ExtraOutput->setText("");
    ActionButton1->setText("Show number cars");
    ActionButton2->setText("Action 2");
    ActionButton2->setVisible(false);
    PropertyLabel->setText("Manufacture");

    // the Data
    vector<car> Data;

    // Loading the list...
    try {
        Controller.ReadFile("filip.txt");
        Tests();
        Data = Controller.list();
        // A sorting just in case...
        sort(Data.begin(), Data.end(), [&](car left_element, car right_element) {
            return left_element.getter_manufacture() < right_element.getter_manufacture();
        });

        int RoleNumber = 0;
        for (auto vehicle : Data)
        {
            DisplayList->insertItem(RoleNumber++, QString::fromStdString(car_to_string(vehicle)));
            DisplayList->item(RoleNumber - 1)->setForeground(QColor(QString::fromStdString(vehicle.getter_color())));
        }
    }
    catch (AppException& Error)
    {
        ErrorOutput->setText(Error.what());
    }
    // Connecting events to buttons...
    QObject::connect(ActionButton1, &QPushButton::clicked, this, [=]() {
        try {
            // Number of cars function
            // we iterate through the list of cars
            // and count all the cars that have the same 
            int count = 0;
            for (auto vehicle : Data)
            {
                if (vehicle.getter_manufacture() == Input->text().toStdString())
                    count++;
            }
            ExtraOutput->setText(QString::fromStdString("There are " + to_string(count) + " from that manufacture"));
        }
        catch (AppException& Error)
        {
            ErrorOutput->setText(Error.what());
        }
        });
}

string OOPTest2::car_to_string(car vehicle)
{
    return vehicle.getter_manufacture() + " | " + vehicle.getter_model();
}

void OOPTest2::Tests()
{
    assert(Controller.nr_of_cars("Audi") == 1);
    assert(Controller.nr_of_cars("WHatever") == 0);
}
