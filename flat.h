#ifndef FLAT_H
#define FLAT_H
#include<vacation.h>
using std::string;

class Flat: public Vacation {
private:
    unsigned int rooms;
    bool AC;
public:
    Flat(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1 , unsigned int=1, bool=false);
    virtual Flat* clone() const override;

    double calcFinalPrice() const override;
    double calcCommission() const override;
    //void print() const override();


    bool hasAC() const;
    unsigned int getRooms() const;

    void setRooms(int ro);
    void setAC(bool ac);

};

#endif // FLAT_H
