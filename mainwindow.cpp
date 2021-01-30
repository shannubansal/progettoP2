#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent){

    setWindowTitle("Vacations");

    wrapLayout=new QVBoxLayout(this);


//box window actions-----------------------------------------------------

    windowActions=new QGroupBox("Actions");
    windowActionsLayout=new QHBoxLayout();

    loadB=new QPushButton("Load", this);
    saveB=new QPushButton("Save", this);
    quitB=new QPushButton("Quit", this);

    windowActionsLayout->addWidget(loadB);
    windowActionsLayout->addWidget(saveB);
    windowActionsLayout->addWidget(quitB);
    windowActions->setLayout(windowActionsLayout);
    windowActions->setMaximumHeight(100);
    wrapLayout->addWidget(windowActions);


//box filters-----------------------------------------------------
    filters=new QGroupBox("Filter offers");
    filtersLayout=new QVBoxLayout();

    hotelFilterB=new QPushButton("Hotels", this);
    flatFilterB=new QPushButton("Flats", this);
    campingFilterB=new QPushButton("Camping", this);
    bungalowFilterB=new QPushButton("Bungalows", this);
    pitchFilterB=new QPushButton("Pitches", this);
    removeFilterB=new QPushButton("Remove Filter", this);
    advancedSearchB=new QPushButton("Advanced search", this);

    filtersLayout->addWidget(hotelFilterB);
    filtersLayout->addWidget(flatFilterB);
    filtersLayout->addWidget(campingFilterB);
    filtersLayout->addWidget(bungalowFilterB);
    filtersLayout->addWidget(pitchFilterB);
    filtersLayout->addWidget(removeFilterB);
    filtersLayout->addWidget(advancedSearchB);

    filters->setLayout(filtersLayout);

//central layout/group con filters group e layout------------------
    centralLayout=new QHBoxLayout();
    centralLayout->addWidget(filters);
    centralGroup=new QGroupBox("");
    centralGroup->setLayout(centralLayout);
    wrapLayout->addWidget(centralGroup);


//boxes per list(da implementare esterna)---------------------------
    listGroup=new QGroupBox("Vacations");
    listLayout=new QVBoxLayout();


/*
  da fare e aggiungere qua in ordine


*/




//listActions group-------------------------------------------------

    listActions=new QGroupBox("");
    listActionsLayout=new QHBoxLayout();

    displayB=new QPushButton("Display", this);//display selected?
    modifyB=new QPushButton("Modify", this);//modify selected?
    deleteB=new QPushButton("Delete", this);//delete selected?

    listActionsLayout->addWidget(displayB);
    listActionsLayout->addWidget(modifyB);
    listActionsLayout->addWidget(deleteB);

    listActions->setLayout(listActionsLayout);

    listLayout->addWidget(listActions);
    listGroup->setLayout(listLayout);//da rimettere sopra asap dopo implementazione di list
    centralLayout->addWidget(listGroup);//da rimettere sopra dopo list






}
