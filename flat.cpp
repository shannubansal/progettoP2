#include "flat.h"

Flat::Flat(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, unsigned int r, bool ac ): Vacation(n, p, c, y, m, d, bP, w), rooms(r), AC(ac){}


Flat* Flat::clone() const{
    return new Flat(*this);
}


double Flat::calcFinalPrice() const{
     double price= getBasePrice();
    if(AC) price += (price *0.02);
    price+=(price*0.2*getRooms());
    return price;
}

/*
Flat::print() const{
 //funzione stampa I/O presumibimente
}
*/

double Flat:: calcCommission() const{
    return calcFinalPrice()*0.12;
}



bool Flat::hasAC() const{
    return AC;
}

unsigned int Flat::getRooms() const{
    return rooms;
}




void Flat::setRooms(int ro){
    rooms=ro;
}

void Flat::setRooms(bool ac){
    AC=ac;
}
