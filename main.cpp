#include <QCoreApplication>
#include "deepPtr.h"


class A {
private:
    int x;
public:
    A() : x(22) {}
    int getValue() {return x;}
};

int main(int argc, char *argv[])
{
    DeepPtr<A> p = new A ();
    cout << (*p).getValue() << "  " << p->getValue();
}
