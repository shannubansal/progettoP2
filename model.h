#ifndef MODEL_H
#define MODEL_H
#include <QObject>
#include<container.h>
#include<vacation.h>
#include<camping.h>
#include<bungalow.h>
#include<pitch.h>
#include<hotel.h>
#include<flat.h>
#include "filemanager.h"
class model{

private:
    Container<DeepPtr<Vacation>> *vList;
    Container<DeepPtr<Vacation>> *filteredVList;
public:
    model();
    ~model();
    void addToContainer(Vacation*);
    void removeFromContainer(Vacation*);
    void switchVacation(Vacation* v, Vacation* oldV);

    void filterHotels();
    void filterFlats();
    void filterCamping();
    void filterBungalows();
    void filterPitches();
    void removeFilter();
    void saveAsXML();
    void loadXML();
    Container<DeepPtr<Vacation>>* mGetListVacations();
    Container<DeepPtr<Vacation>>* mGetListVacationsFiltered();
};

#endif // MODEL_H
