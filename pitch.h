#ifndef PITCH_H
#define PITCH_H
#include<camping.h>
using std::string;


class Pitch: public Camping{

public:
    enum tentType { none, small, medium, large};

    Pitch(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1,
          unsigned int=1, double=0.0, double=0.0, bool=false, tentType= tentType::none );
    virtual ~Pitch() =default;
    virtual Pitch* clone() const override;
    virtual double calcFinalPrice() const override;
    virtual double calcCommission() const override;
    virtual double getPriceAndFees(unsigned int=1, unsigned int=0) const override;//per aggiunte  e calcoli sulla vista
    virtual string getTipo() const override;
    virtual string getInfo() const override;

    //virtual void print() const override();
    static string convertTentToString (const tentType& );

    bool getTentAvailable() const;
    tentType getTent() const;


    void setTentAvailable(bool tA);
    void setTent(tentType t);
private:
    bool tentAvailable;
    tentType tent;

};
std::ostream& operator<<(std::ostream&, const Pitch&);
#endif // PITCH_H
