#include <QCoreApplication>
#include "deepPtr.h"


class A {
private:
    int x;
public:
    A(int s =0) : x(s) {}
    int getValue() {return x;}
};

int main(int argc, char *argv[])
{
    DeepPtr<A> p = new A ();

    DeepPtr<A> p1 = new A(1);



}
