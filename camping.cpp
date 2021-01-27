#include "camping.h"

Camping::Camping(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, unsigned int mC,
                 double dF, double vF ): Vacation(n, p, c, y, m, d, bP, w), maxCapacity(mC),
                dailyFee(dF), visitorsFee(vF){}




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

