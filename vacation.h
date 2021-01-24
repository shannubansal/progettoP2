#ifndef VACATION_H
#define VACATION_H
#include<QDate>
using std::string;

class Vacation
{
private:
    string name;
    string place;
    string country;
    QDate date;
    double basePrice;
    unsigned int weeks;

public:
    Vacation(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1 );
    virtual ~Vacation() =default;



    //metodi virtuali
    virtual Vacation* clone() const=0;
    virtual double calcFinalPrice() const=0;
    //virtual print() const;
    virtual double calcCommission() const=0;
    virtual bool operator==(const Vacation&) const;//utile? da implementare?
    //valutare inserimento di ritornante caparra/deposit



    string getName() const;
    string getPlace() const;
    string getCountry() const;
    QDate getDate() const;
    int getYearD() const;
    int getMonthD() const;
    int getDayD() const;
    double getBasePrice() const;
    unsigned int getWeeks() const;


    void setName(string n);
    void setPlace(string p);
    void setCountry(string c);
    bool setDateVacation(int y, int m, int d);
    void setBasePrice(double bP);
    void setWeeks(int w);
};

#endif // VACATION_H
