#include "hotel.h"

Hotel::Hotel(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, int s, Hotel::serviceType ty, int b): Vacation(n, p, c, y, m, d, bP, w), stars(s), type(ty), beds(b){}


Hotel* Hotel::clone() const{
    return new Hotel(*this);
}

double Hotel::calcFinalPrice() const{
    double price= getBasePrice();
    if(getType()==Hotel::serviceType::halfboard){
        price += (price *0.2);
    }else if(getType()==Hotel::serviceType::allinclusive){
        price += (price *0.5);
    };
    price+=(price*0.3*getBeds());
    return price;
}

/*
Flat::print() const{
 //funzione stampa I/O presumibimente
}
*/

double Hotel::calcCommission() const{
    return calcFinalPrice()*0.08;
}


string Hotel::getTipo() const{
    return "Hotel";
}



int Hotel::getStars() const{
    return stars;
}

Hotel::serviceType Hotel::getType() const{
    return type;
}

int Hotel::getBeds() const{
    return beds;
}



void Hotel::setStars(int s){
    stars=s;
}

void Hotel::setType(serviceType ty){//da controllare dove mettere
    type=ty;
}

void Hotel::setBeds(int b){
    beds=b;
}

string Hotel::convertServToString(const Hotel::serviceType & l){
    if(l==Hotel::serviceType::overnight){
        return "overnight";
    }else if(l==Hotel::serviceType::halfboard){
        return "halfboard";
    }else if(l==Hotel::serviceType::allinclusive){
        return "allinclusive";
    }else{
        return "overnight";//comportamento standard cmq nella vista da  implementare scelta
        //esclusivamente tra i tre enum
    }
    //throw std::exception();
}
std::ostream& operator<<(std::ostream& os, const Hotel& h) {

    return operator<< (os, static_cast<const Vacation&>(h))
                   << "\nStars: " << h.getStars()
                   << "\nService: " << Hotel::convertServToString(h.getType())
                   <<"\nBeds: "<<h.getBeds();
}

