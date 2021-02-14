#include "pitch.h"

Pitch::Pitch(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, unsigned int mC,
             double dF, double vF, bool tA, Pitch::tentType t): Camping(n, p, c, y, m, d, bP, w, mC, dF, vF),
             tentAvailable(tA), tent(t){}


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
        price+=(price*0.15*people);
    }
    if (visitors){
        price+=(price*0.05*visitors);
    }

    price+= calcCommission();
    return price;
}


string Pitch::convertTentToString (const tentType& l){
    if(l==Pitch::tentType::small){
        return "Small";
    }else if(l==Pitch::tentType::medium){
        return "Medium";
    }else if(l==Pitch::tentType::large){
        return "Large";
    }else{
        return "None";
    }
}


int Pitch::convertTentToI(const tentType& l){
    if(l==Pitch::tentType::small){
        return 1;
    }else if(l==Pitch::tentType::medium){
        return 2;
    }else if(l==Pitch::tentType::large){
        return 3;
    }else{
        return 0;
    }
}

Pitch::tentType Pitch::convertTentToEnum (const string& str ){
    if(str=="Small" ){
        return Pitch::tentType::small;
    }else if (str=="Medium"){
        return Pitch::tentType::medium;
    }else if(str=="Large"){
        return Pitch::tentType::large;
    }else{
        return Pitch::tentType::none;
    }

}

bool  Pitch::operator==(const Vacation& h) const {
    if(!(dynamic_cast<const Pitch*>(&h))){
            return false;
    }
    return Camping::operator==(h)
            &&  getTentAvailable() == dynamic_cast<const Pitch*>(&h)->getTentAvailable()
            && getTent() == dynamic_cast<const Pitch*>(&h)->getTent();
}

std::ostream& operator<<(std::ostream& os, const Pitch& p) {

    return operator<< (os, static_cast<const Vacation&>(p))
                   <<"\nTentAvailable: "<<(p.getTentAvailable()? "Yes" : "No")
                   << "\nTentType: " << Pitch::convertTentToString(p.getTent());

}



string Pitch::getTipo() const{
    return "Pitch";
}


string Pitch::getInfo() const{
    string s=Camping::getInfo();
    return s.append("\nTent: "+convertTentToString(getTent()));

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

void Pitch::saveOnFile(Writer& w) {

    w.write(*this);

}

