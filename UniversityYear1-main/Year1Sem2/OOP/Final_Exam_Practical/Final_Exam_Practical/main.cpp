#include "Final_Exam_Practical.h"
#include "service.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    new Gui();
    return a.exec();
}
