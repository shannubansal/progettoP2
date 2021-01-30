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

class model{

private:
    Container<DeepPtr<Vacation>> *vList;
    Container<DeepPtr<Vacation>> *filteredVList;
public:
    model();
    ~model();

};

#endif // MODEL_H
