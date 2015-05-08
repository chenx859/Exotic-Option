#ifndef PATHDEPOPTION_H_INCLUDED
#define PATHDEPOPTION_H_INCLUDED

#include"BlackSchollesmodel.h"
#include<vector>

using namespace std;

class PathDepOption{
private:
    double m_T;//maturity
    int m_m;//number of elements in the paths, each elements of the path will be compute at time (i*T/m)
public:
    PathDepOption():m_T(0.0),m_m(0){}   //constructor
    PathDepOption(double T, int m):m_T(T),m_m(m){}  //overloaded constructor
    PathDepOption(const PathDepOption& p):m_T(p.m_T),m_m(p.m_m){}   //copy constructor
    PathDepOption& operator=(const PathDepOption& p)    //assignment operator
    {
        if(this!=&p)    //self assignmenet condition
        {
            m_T=p.m_T;
            m_m=p.m_m;
        }

        return *this;
    }
    virtual double payoff(vector<double>& Path) const =0;  //payoff of the option
    double PriceMC(BlackSchollesmodel& model, long N);    //Monte-Carlo method to price the option
    double GetT()const{return m_T;}     //return the maturity of the option
    int Getm()const{return m_m;}        //return the number of elements of the path

    double sdeviation;           //the unbias estimated standard deviation


};


#endif // PATHDEPOPTION_H_INCLUDED
