#ifndef __Final_project__ImpliVol__
#define __Final_project__ImpliVol__

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Cumulative Standard Normal
class ImpliedV{
private:
    double S, K, r, T, MktPrice;
    char PutCall;
    
public:
    ImpliedV():S(0.0),K(0.0),r(0.0),T(0.0),PutCall(0), MktPrice(0){}   //constructor
    
    ImpliedV(double S,double K,double r,double T,double MktPrice, char PutCall):S(S),K(K),r(r),T(T),MktPrice(MktPrice),PutCall(PutCall){} //overloaded constructor
    
    ImpliedV(const ImpliedV& b):S(b.S),K(b.K),r(b.r),T(b.T),MktPrice(b.MktPrice),PutCall(b.PutCall){} //copy constructor
    
    ImpliedV& operator=(const ImpliedV& b)    //assignemnet operator
    {
        if(this!=&b)    //self assignment condition
        {
            S=b.S;
            K=b.K;
            r=b.r;
            T=b.T;
            MktPrice=b.MktPrice;
            PutCall=b.PutCall;
        }
        
        return *this;
    }
    double N(double x);
    // Black-Scholes Price
    double BSPrice(double v);
    // Bisection Algorithm
    double BisecBSV(double a, double b);
};


#endif /* defined(__Final_project__ImpliVol__) */
