#include "model.h"

model::model():vList(new Container<DeepPtr<Vacation>>), filteredVList(new Container<DeepPtr<Vacation>>) {}


model::~model(){
    vList->emptyContainer();
    delete vList;
    filteredVList->emptyContainer();
    delete filteredVList;
}
