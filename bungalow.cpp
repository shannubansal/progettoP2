#include "bungalow.h"

Bungalow::Bungalow(string n, string p, string c, int y, int m, int d, double bP,
                   unsigned int w, unsigned int mC, double dF, double vF, unsigned int mV, Bungalow::bungalowType bT,
                   bool cS) : Camping(n, p, c, y, m, d, bP, w, mC, dF, vF), maxVisitors(mV), bType(bT), cleaningService(cS) {}

Bungalow* Bungalow::clone() const{
    return new Bungalow(*this);
}



double Bungalow::calcFinalPrice() const{//da fareeeee
    double price= getBasePrice();
    if(getBungalowType()==Bungalow::bungalowType::suite){
        price += (price *0.25);
    }else if(getBungalowType()==Bungalow::bungalowType::deluxe){
        price += (price *0.50);
    }
    return price;
}

double Bungalow::calcCommission() const{
    return calcFinalPrice()*0.18;
}

double Bungalow::getPriceAndFees(unsigned int people, unsigned int visitors) const{
    double price= calcFinalPrice();
    if (people<= getMaxCapacity()){
        price+=(price*0.3*people);
    }
    if (visitors){
        if(visitors>getMaxVisitors()){
            price+=(price*0.15*visitors);
        }else{
            price+=(price*0.1*visitors);
        }
    }

    price+= calcCommission();
    if(getCleaningServ()){
        price+=30.0;
    }
    return price;
}


string Bungalow::convertBungToString (const bungalowType& l){
    if(l==Bungalow::bungalowType::standard){
        return "Standard";
    }else if(l==Bungalow::bungalowType::suite){
        return "Suite";
    }else if(l==Bungalow::bungalowType::deluxe){
        return "Deluxe";
    }else{
        return "Standard";
    }
}


Bungalow::bungalowType Bungalow::convertBungtoEnum (const string& str ){
    if(str=="Suite" ){
        return Bungalow::bungalowType::suite;
    }else if(str=="Deluxe"){
        return Bungalow::bungalowType::deluxe;
    }else{
        return Bungalow::bungalowType::standard;
    }

}

std::ostream& operator<<(std::ostream& os, const Bungalow& b) {

    return operator<< (os, static_cast<const Vacation&>(b))
                   <<"\nMaxVisitors: "<<b.getMaxVisitors()
                   << "\nBungalowType: " << Bungalow::convertBungToString(b.getBungalowType())
                   <<"\nCleaning: "<<(b.getCleaningServ()? "Yes" : "No");

}


string Bungalow::getTipo() const{
    return "Bungalow";
}

string Bungalow::getInfo() const{
    string s="";

    return s.append(Camping::getInfo())
            .append("\nBungalowType: ")
            .append(convertBungToString(getBungalowType()))
            .append("\nService: " )
            .append(getCleaningServ()? "Yes" : "No");
}



unsigned int Bungalow::getMaxVisitors() const{
    return maxVisitors;
}


Bungalow::bungalowType Bungalow::getBungalowType() const{
    return bType;
}

bool Bungalow::getCleaningServ() const{
    return cleaningService;
}


void Bungalow::setMaxVisitors(unsigned int mV){
    maxVisitors=mV;
}

void Bungalow::setBungalowType(Bungalow::bungalowType bT){
    bType=bT;
}

void Bungalow::setCleaningServ(bool cS){
    cleaningService=cS;
}
