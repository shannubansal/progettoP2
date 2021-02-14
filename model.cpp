#include "model.h"

model::model():vList(new Container<DeepPtr<Vacation>>), filteredVList(new Container<DeepPtr<Vacation>>) {
    //serie di test
//    Bungalow *p= new Bungalow();
//       Hotel* h= new Hotel();
//       Pitch *pi = new Pitch();
//       Flat *f = new Flat();
//       h->setStars(3);


//       addToContainer(h);
//       addToContainer(p);
//       addToContainer(f);
//       addToContainer(pi);
//       delete h; delete pi; delete p; delete f;
//       //vList->remove(p);
//       cout<<vList->getSize()<<endl;
//   //    saveAsXML();
//   //    cout<<*h<<endl;

//   //    XMLWriter xml;
//   //    Bungalow b;
//   //    for (auto it = vList->begin(); it!=vList->end(); ++it) {
//   //        (*it)->writer(xml);
//   //    }
//   ////    b.writer(xml);
//   //    cout<<"model"<<endl;
}


model::~model(){
    vList->emptyContainer();
    delete vList;
    filteredVList->emptyContainer();
    delete filteredVList;

}


void model::addToContainer(Vacation* v){//niente template qui
    vList->pushback(DeepPtr<Vacation>(v));
}



void model::removeFromContainer(Vacation *v){
    if(!vList->isEmpty()){
        vList->remove(DeepPtr<Vacation>(v));
     }
    if(!filteredVList->isEmpty()){
        filteredVList->remove(DeepPtr<Vacation>(v));
    }
}


void model::switchVacation(Vacation* v, Vacation* oldV){
     vList->sostituisciNodo(DeepPtr<Vacation>(oldV), DeepPtr<Vacation>(v));
}

//filters


void model::filterHotels(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Hotel* h=dynamic_cast<Hotel*>(v);
        if(h!=nullptr){
            filteredVList->pushback(DeepPtr<Vacation>(v));
        }

    }
}

void model::filterFlats(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Flat* f= dynamic_cast<Flat*>(v);
        if(f){
            filteredVList->pushback(DeepPtr<Vacation>(v));
        }
    }
}

void model::filterCamping(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Camping* c= dynamic_cast<Camping*>(v);
        if(c){
            filteredVList->pushback(DeepPtr<Vacation>(v));
        }
    }
}

void model::filterBungalows(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Bungalow* b= dynamic_cast<Bungalow*>(v);
        if(b){
            filteredVList->pushback(DeepPtr<Vacation>(v));
        }
    }
}

void model::filterPitches(){
    filteredVList->emptyContainer();
    for(auto it=vList->begin(); it!=vList->end(); ++it){
        Vacation* v= (*it).get();
        Pitch* p= dynamic_cast<Pitch*>(v);
        if(p){
            filteredVList->pushback(DeepPtr<Vacation>(v));
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

void model::saveAsXML() {
    FileManager xml;
    xml.saveAsXML(vList);
}

void model::loadXML() {
    cout<<"modelLoadXML"<<endl;
    FileManager xml;
//    vList->emptyContainer();
    vList = xml.loadXML();
}
