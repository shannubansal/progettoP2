#include "pitch.h"

Pitch::Pitch(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, unsigned int mC,
             double dF, double vF, bool tA, Pitch::tentType t): Camping(n, p, c, y, m, d, bP, w, mC, dF, vF),
             tentAvailable(tA), Pitch::tentType::tent(t){}


Pitch* Pitch::clone() const{
    return new Pitch(*this);
}


double Pitch::calcFinalPrice() const{
     double price= getBasePrice();
     if(getTentAvailable()){
         if(getTent()== Pitch::tentType::small){
             price += (price *0.14);
         }else if(getTent()== Pitch::tentType::medium){
             price += (price *0.24);
         }else if(getTent()== Pitch::tentType::large){
             price += (price *0.36);
         }
     }
    return price;
}

/*
void Pitch::print() const{
 //funzione stampa I/O presumibimente
}
*/

double Pitch::calcCommission() const{
    return calcFinalPrice()*0.05;
}

double Pitch::getPriceAndFees(unsigned int people, unsigned int visitors) const{
    double price= calcFinalPrice();

    if (people<= Camping::getMaxCapacity()){
        price+=(price*0,15*people);
    }
    if (visitors){
        price+=(price*0,05*visitors);
    }

    price+= calcCommission();
    return price;
}



bool Pitch::getTentAvailable() const{
    return tentAvailable;
}

Pitch::tentType Pitch::getTent() const{
    return tent;
}


void Pitch::setTentAvailable(bool tA){
    tentAvailable=tA;
}

void Pitch::setTent(Pitch::tentType t){
    tent=t;
}
