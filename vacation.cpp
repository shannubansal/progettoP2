#include "vacation.h"

Vacation::Vacation(string n, string p, string c, int y, int m, int d, double bP,
                   unsigned int w ): name(n), place(p), country(c), date(y, m, d),
                basePrice(bP), weeks(w) {}



string Vacation::getInfo() const{

    string s=getTipo();
    return s.append("\nName: " +getName()).append("\nPlace: " +getPlace())
            .append("\nCountry : " +getCountry()).append( "\nDate: " + (this->getDate()).toString().toStdString())
            .append("\nStartingPrice :" + std::to_string(getBasePrice()))
            .append("€").append("\nWeeks : " + std::to_string(getWeeks()));


}

/*
Vacation::print() const{
 //funzione stampa I/O presumibimente
}
*/


bool Vacation::operator==(const Vacation & c) const{
    return name == c.getName() && place == c.getPlace()&&
country == c.getCountry() && date == QDate(c.getYearD(),c.getMonthD(),c.getDayD())
&& basePrice == c.getBasePrice() && weeks == c.getWeeks();
}

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

unsigned int Vacation::getWeeks() const{
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

std::ostream& operator<<(std::ostream& os, const Vacation& v){
    return os<< "Name: " << v.getName()
             << "\nPlace: " << v.getPlace()
             << "\nCountry: " << v.getCountry()
             << "\nDate: " << (v.getDate()).toString().toStdString()
             << "\nStartingPrice: " <<v.getBasePrice()
             << "\nWeeks: " << v.getWeeks();
}

