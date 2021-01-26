#include "camping.h"

Camping::Camping(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, unsigned int mC, double dF, double vF ): Vacation(n, p, c, y, m, d, bP, w), maxCapacity(mC), dailyFee(dF), visitorsFee(vF){}

