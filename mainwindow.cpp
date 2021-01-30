#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent)/*, menuBar(new mainWindowMenu())*/
{

    setWindowTitle("Vacations");
    wrapLayout=new QVBoxLayout(this);
    prova=new QPushButton("prova", this);
    wrapLayout->addWidget(prova);
    //menuBar=new mainWindowMenu(this);
    //this->setMenuBar(menuBar);



}
