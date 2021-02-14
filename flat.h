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
    virtual ~Flat() =default;

    virtual Flat* clone() const override;
    double calcFinalPrice() const override;
    double calcCommission() const override;

    virtual string getTipo()const override;
    virtual string getInfo() const override;



    bool hasAC() const;
    unsigned int getRooms() const;
    virtual bool  operator==(const Vacation&) const override;

    void setRooms(int ro);
    void setAC(bool ac);

    void saveOnFile(Writer&);


};
std::ostream& operator<<(std::ostream&, const Flat&);
#endif // FLAT_H
