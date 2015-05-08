#ifndef BlackSchollesmodel_H_INCLUDED
#define BlackSchollesmodel_H_INCLUDED

#include<vector>
#include<ctime>
#include<stdlib.h>

using namespace std;

class BlackSchollesmodel{
private:
    double m_S0;//m_S0 the initial price of the asset
    double m_r;//m_r : the risk free rate
    double m_sigma;//m_c : the dividend rate
    double m_c;//m_sigma the volatility
public:
    BlackSchollesmodel():m_S0(0.0),m_r(0.0),m_sigma(0.0),m_c(0.0){srand((unsigned int) time(NULL));}   //constructor
    
    BlackSchollesmodel(double S0,double r,double sigma,double c):m_S0(S0),m_r(r),m_sigma(sigma),m_c(c){srand((unsigned int) time(NULL));} //overloaded constructor
    
    BlackSchollesmodel(const BlackSchollesmodel& b):m_S0(b.m_S0),m_r(b.m_r),m_sigma(b.m_sigma),m_c(b.m_c){srand((unsigned int) time(NULL));}  //copy constructor
    
    BlackSchollesmodel& operator=(const BlackSchollesmodel& b)    //assignemnet operator
    {
        if(this!=&b)    //self assignment condition
        {
            m_S0=b.m_S0;
            m_r=b.m_r;
            m_sigma=b.m_sigma;
            m_c = b.m_c;
        }

        return *this;
    }

    ~BlackSchollesmodel(){}    //destructor
    double Gauss()const;    //generate normal variable (Box-Muller method)
    void GeneratePath(double T, int m,vector<double>& S); //generate a path
    double Getr()const{return m_r;} //return the risk free rate
};


#endif // BSMODEL_H_INCLUDED
