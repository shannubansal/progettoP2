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
    Camping(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1, unsigned int=10, double=0.0, double=0.0);
    virtual ~Camping()=default;
    virtual Camping* clone() const=0;
    virtual double calcFinalPrice() const=0;
    //virtual void print() const;
    virtual double calcCommission() const=0;
    virtual double getPriceAndFees(unsigned int=1, unsigned int=0) const=0;
    virtual string getTipo()const=0;
    virtual string getInfo() const override;
    virtual bool operator==(const Camping&) const;


    unsigned int getMaxCapacity() const;
    double getDailyFee() const;
    double getVisitorsFee() const;

    void setMaxCapacity(unsigned int mC);
    void setDailyFee(double dF);
    void setVisitorsFee(double vF);




};
std::ostream& operator<<(std::ostream&, const Camping&);

#endif // CAMPING_H
