#include"ImpliVol.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

//Cumulative Standard Normal
double ImpliedV:: N(double x) {
    const double pi =  4.0*atan(1.0);
    const double b1 =  0.319381530;
    const double b2 = -0.356563782;
    const double b3 =  1.781477937;
    const double b4 = -1.821255978;
    const double b5 =  1.330274429;
    double t = 1.0 / (1.0 + 0.2316419*x);
    double n = exp(-x*x/2.0)/sqrt(2*pi);
    return 1.0 - n*(b1*t + b2*pow(t,2) + b3*pow(t,3) + b4*pow(t,4) + b5*pow(t,5));
}

// Black-Scholes Price
double ImpliedV::BSPrice(double v) {
    double d = (log(S/K) + T*(r + 0.5*v*v)) / (v*sqrt(T));
    double Call = S*N(d) - exp(-r*T)*K*N(d - v*sqrt(T));
    if (PutCall=='C')
        return Call;
    else
        return Call - S + K*exp(-r * T);
}


// Bisection Algorithm
double ImpliedV:: BisecBSV(double a, double b) {
    const int MaxIter = 500;
    double Tol = 0.00001;
    double midP = 0.0, midCdif;
    double  lowCdif = MktPrice - BSPrice(a);
    double highCdif = MktPrice - BSPrice(b);
    if (lowCdif*highCdif > 0)
        return -1;
    else
        for (int i=0; i<=MaxIter; i++) {
            midP = (a + b) / 2.0;
            midCdif = MktPrice - BSPrice(midP);
            if (abs(midCdif)<Tol) goto LastLine;
            else {
                if (midCdif>0) a = midP;
                else b = midP;
            }
        }
LastLine:
    return midP;
}
