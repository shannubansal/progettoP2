#include "model.h"

model::model():vList(new Container<DeepPtr<Vacation>>), filteredVList(new Container<DeepPtr<Vacation>>) {
    //serie di test prolematici con push back e addToContainer e DeepPtr
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

Container<DeepPtr<Vacation>>* model::mGetListVacations(){
    return this->vList;
}
