#ifndef BARRIER_H_INCLUDED
#define BARRIER_H_INCLUDED

#include"PathDepOption.h"

using namespace std;

//class Barrier Call Up and Out
class BarrierCallUO : public PathDepOption{
private:
    double m_K;//the strike of the option
    double m_L;//m_L which is the barrier of the option
public:
    BarrierCallUO():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierCallUO(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierCallUO(const BarrierCallUO& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierCallUO& operator=(const BarrierCallUO& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierCallUO(){}

    double payoff(vector<double>& Path)const;

};

//class Barrier Call Up and In
class BarrierCallUI : public PathDepOption{
private:
    double m_K;
    double m_L;
public:
    BarrierCallUI():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierCallUI(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierCallUI(const BarrierCallUI& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierCallUI& operator=(const BarrierCallUI& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierCallUI(){}

    double payoff(vector<double>& Path)const;

};

//class Barrier Call Down and In
class BarrierCallDI : public PathDepOption{
private:
    double m_K;
    double m_L;
public:
    BarrierCallDI():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierCallDI(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierCallDI(const BarrierCallDI& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierCallDI& operator=(const BarrierCallDI& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierCallDI(){}

    double payoff(vector<double>& Path)const;

};

//class Barrier Call Down and Out
class BarrierCallDO : public PathDepOption{
private:
    double m_K;
    double m_L;
public:
    BarrierCallDO():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierCallDO(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierCallDO(const BarrierCallDO& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierCallDO& operator=(const BarrierCallDO& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierCallDO(){}

    double payoff(vector<double>& Path)const;

};

//class Barrier Put Up and Out
class BarrierPutUO : public PathDepOption{
private:
    double m_K;
    double m_L;
public:
    BarrierPutUO():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierPutUO(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierPutUO(const BarrierPutUO& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierPutUO& operator=(const BarrierPutUO& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierPutUO(){}

    double payoff(vector<double>& Path)const;

};

class BarrierPutUI : public PathDepOption{
private:
    double m_K;
    double m_L;
public:
    BarrierPutUI():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierPutUI(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierPutUI(const BarrierPutUI& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierPutUI& operator=(const BarrierPutUI& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierPutUI(){}

    double payoff(vector<double>& Path)const;

};

class BarrierPutDI : public PathDepOption{
private:
    double m_K;
    double m_L;
public:
    BarrierPutDI():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierPutDI(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierPutDI(const BarrierPutDI& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierPutDI& operator=(const BarrierPutDI& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierPutDI(){}

    double payoff(vector<double>& Path)const;

};

class BarrierPutDO : public PathDepOption{
private:
    double m_K;
    double m_L;
public:
    BarrierPutDO():PathDepOption(),m_K(0.0),m_L(0.0){}
    BarrierPutDO(double T, int m, double K, double L):PathDepOption(T,m),m_K(K),m_L(L){}
    BarrierPutDO(const BarrierPutDO& b):PathDepOption(b),m_K(b.m_K),m_L(b.m_L){}
    BarrierPutDO& operator=(const BarrierPutDO& b)
    {
        if(this!=&b)
        {
            this->PathDepOption::operator=(b);
            m_K=b.m_K;
            m_L=b.m_L;
        }

        return *this;
    }
    ~BarrierPutDO(){}

    double payoff(vector<double>& Path)const;

};


#endif // BARRIER_H_INCLUDED
