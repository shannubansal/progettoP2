#include "vacation.h"

Vacation::Vacation(string n, string p, string c, int y, int m, int d, double bP, unsigned int w ): name(n), place(p), country(c), date(y, m, d), basePrice(bP), weeks(w) {}


/*
Vacation::print() const{
 //funzione stampa I/O presumibimente
}
*/
string Vacation::getName() const{
    return name;
}
string Vacation::getPlace() const{
    return place;
}
string Vacation::getCountry() const{
    return country;
}
QDate Vacation::getDate() const{
    return date;
}

double Vacation::getBasePrice() const{
    return basePrice;
}

unsigned int getWeeks() const{
    return weeks;
}

int Vacation::getYearD() const{
    return date.QDate::year();
}

int Vacation::getMonthD() const{
    return date.QDate::month();
}

int Vacation::getDayD() const{
    return date.QDate::day();
}




void Vacation::setName(string n){
    name=n;
}

void Vacation::setPlace(string p){
    place=p;
}

void Vacation::setCountry(string c){
    country=c;
}

bool Vacation::setDateVacation(int y, int m, int d){
    return date.setDate(y,m,d);
}


void Vacation::setBasePrice(double bP){
    basePrice=bP;
}

void Vacation::setWeeks(int w){
    weeks=w;
}


