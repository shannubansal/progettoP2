#include "camping.h"

Camping::Camping(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, unsigned int mC,
                 double dF, double vF ): Vacation(n, p, c, y, m, d, bP, w), maxCapacity(mC),
                dailyFee(dF), visitorsFee(vF){}


string Camping::getInfo() const{
    string s=Vacation::getInfo();
    return s.append("\nDailyFee: "+ std::to_string(getDailyFee()))
            .append("€");
}

unsigned int Camping::getMaxCapacity() const{
    return maxCapacity;
}

double Camping::getDailyFee() const{
    return dailyFee;
}

double Camping::getVisitorsFee() const{
    return visitorsFee;
}


void Camping::setMaxCapacity(unsigned int mC){
    maxCapacity=mC;
}

void Camping::setDailyFee(double dF){
    dailyFee=dF;
}

void Camping::setVisitorsFee(double vF){
    visitorsFee=vF;
}


bool  Camping::operator==(const Vacation& h) const {
    if(!(dynamic_cast<const Camping*>(&h))){
            return false;
    }
    return Vacation::operator==(h)
            && getMaxCapacity() == dynamic_cast<const Camping*>(&h)->getMaxCapacity()
            && getDailyFee() == dynamic_cast<const Camping*>(&h)->getDailyFee()
            && getVisitorsFee() == dynamic_cast<const Camping*>(&h)->getVisitorsFee();
}

std::ostream& operator<<(std::ostream& os, const Camping& c) {

    return operator<< (os, static_cast<const Vacation&>(c))
                   << "\nMaxCapacity: " << c.getMaxCapacity()
                   << "\nDailyFee: " << c.getMaxCapacity()
                   <<"\nVisitorsFee: "<< c.getVisitorsFee();
}
