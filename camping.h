#ifndef CAMPING_H
#define CAMPING_H
#include<vacation.h>
using std::string;


class Camping: public Vacation{
private:
    unsigned int maxCapacity;//o da mettere solo su bungalow
    double dailyFee;
    double visitorsFee;
public:
    Camping(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1, unsigned int=1, double=0.0, double=0.0);
    virtual getPriceAndFees() const=0;





};

#endif // CAMPING_H
