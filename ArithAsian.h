#ifndef ArithAsian_H_INCLUDED
#define ArithAsian_H_INCLUDED

#include"PathDepOption.h"
#include<vector>

using namespace std;

class ArithAsianCall:public PathDepOption{
private:
    double m_K; //m_K is the strike of the options (call and put)
public:
    ArithAsianCall():PathDepOption(),m_K(0.0){}//constructor
    ArithAsianCall(double T,int m,double K):PathDepOption(T,m),m_K(K){}  //overloaded constructor
    ArithAsianCall(const ArithAsianCall& a):PathDepOption(a),m_K(a.m_K){} //copy constructor
    ArithAsianCall& operator=(const ArithAsianCall& a)    //assignment operator
    {
        if(this!=&a)    //self assignment operator
        {
            this->PathDepOption::operator=(a);
            m_K = a.m_K;
        }

        return *this;
    }
    ~ArithAsianCall(){}

    double payoff(vector<double>& Path)const;  //the payoff of the option (put and call)
};

//class Arithmetic asina put
class ArithAsianPut:public PathDepOption{
private:
    double m_K;
public:
    ArithAsianPut():PathDepOption(),m_K(0.0){}
    ArithAsianPut(double T,int m,double K):PathDepOption(T,m),m_K(K){}
    ArithAsianPut(const ArithAsianPut& a):PathDepOption(a),m_K(a.m_K){}
    ArithAsianPut& operator=(const ArithAsianPut& a)
    {
        if(this!=&a)
        {
            this->PathDepOption::operator=(a);
            m_K = a.m_K;
        }

        return *this;
    }
    ~ArithAsianPut(){}

    double payoff(vector<double>& Path)const;
};

#endif // ArithAsian_H_INCLUDED
