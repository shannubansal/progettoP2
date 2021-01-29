#ifndef HOTEL_H
#define HOTEL_H
#include<vacation.h>
using std::string;


class Hotel: public Vacation
{

public:
    enum serviceType { overnight, halfboard, allinclusive};//forse valutare posizionamento diverso (qua serve per non
    //inquinare il namespace)

    Hotel(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1, int=0, Hotel::serviceType=overnight, int=1);

    virtual ~Hotel() =default;
    virtual Hotel* clone() const override;
    double calcFinalPrice() const override;
    double calcCommission() const override;
    //virtual void print() const override();
    virtual string getTipo()const override;

    static string convertServToString (const serviceType& );

    int getStars() const;
    serviceType getType() const;
    int getBeds() const;

    void setStars(int s);
    void setType(serviceType ty);
    void setBeds(int b);
private:
        int stars;
        serviceType type;
        int beds;


};
std::ostream& operator<<(std::ostream&, const Hotel&);
#endif // HOTEL_H
