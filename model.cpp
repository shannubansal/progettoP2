#include "model.h"

model::model():vList(new Container<DeepPtr<Vacation>>), filteredVList(new Container<DeepPtr<Vacation>>) {
    //serie di test
    Vacation *p;
    p=new Pitch();
    Hotel* h= new Hotel();
    h->setStars(3);

    addToContainer(p);
    addToContainer(h);


    cout<<vList->getSize()<<endl;
    cout<<*p<<endl;
}


model::~model(){
    vList->emptyContainer();
    delete vList;
    filteredVList->emptyContainer();
    delete filteredVList;

}


void model::addToContainer(Vacation* v){//niente template qui
    vList->pushback(v);
}






//filters


void model::filterHotels(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Hotel* h= dynamic_cast<Hotel*>(v);
        if(h){
            filteredVList->pushback(v);
        }
    }
}

void model::filterFlats(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Flat* f= dynamic_cast<Flat*>(v);
        if(f){
            filteredVList->pushback(v);
        }
    }
}

void model::filterCamping(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Camping* c= dynamic_cast<Camping*>(v);
        if(c){
            filteredVList->pushback(v);
        }
    }
}

void model::filterBungalows(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Bungalow* b= dynamic_cast<Bungalow*>(v);
        if(b){
            filteredVList->pushback(v);
        }
    }
}

void model::filterPitches(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Pitch* p= dynamic_cast<Pitch*>(v);
        if(p){
            filteredVList->pushback(v);
        }
    }
}


void model::removeFilter(){
    filteredVList->emptyContainer();
}

Container<DeepPtr<Vacation>>* model::mGetListVacations(){
    return this->vList;
}

Container<DeepPtr<Vacation>>* model::mGetListVacationsFiltered(){
    return this->filteredVList;
}
