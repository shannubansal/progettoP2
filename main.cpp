#include <QApplication>

#include<controller.h>
#include<model.h>



int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     controller c(nullptr);
     return a.exec();
   /*
    DeepPtr<Pitch> p = new Pitch();
    p->setBasePrice(30036.6);
    cout<<"mlem " <<*p<<endl;
    */




}
