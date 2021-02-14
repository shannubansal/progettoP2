#include <QApplication>

#include<controller.h>
#include<model.h>



int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     controller c(nullptr);
     return a.exec();

}
