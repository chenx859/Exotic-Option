#include"ArithAsian.h"
#include<iostream>
#include<vector>

using namespace std;

//payoff of the arithmetic asian call
double ArithAsianCall::payoff(vector<double>& Path)const
{
    double sum=0.0;
    int m = Getm();
    for(int i=0;i<m;i++)
        sum+=Path[i];

    sum=sum/(double)m;  //arithmetic average of the path

    if(sum-m_K>=0)
        return sum-m_K;

    return 0.0;
}

//payoff of the arithmetic asian put
double ArithAsianPut::payoff(vector<double>& Path)const
{
    double sum=0.0;
    int m = Getm();
    for(int i=0;i<m;i++)
        sum+=Path[i];

    sum=sum/(double)m;  //arithmetic average of the path

    if(m_K-sum>=0)
        return m_K-sum;

    return 0.0;
}

