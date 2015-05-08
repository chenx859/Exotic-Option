#include"BlackSchollesmodel.h"
#include<cmath>
#include<iostream>
#include<time.h>

const double pi = 4.0*atan(1.0);

using namespace std;

//GeneratePath functions
void BlackSchollesmodel::GeneratePath(double T, int m, vector<double>& S )
{
    double St= m_S0;


    // dSt = r*St dt+sigma*St dWt (under the risk free probability),thus St = S0*exp((r-sigma^2)t+sigma*sqrt(t)Z), with Z~N(0,1)
    for(int i=0;i<m;i++)
    {
        S[i]=St*exp((m_r-m_c-(m_sigma*m_sigma*.5))*T/(double)m)*exp(m_sigma*sqrt(T/(double)m)*Gauss());
        St=S[i];
    }
}

//Gauss function
double BlackSchollesmodel::Gauss()const
{
    double U1=(rand()+1.0)/(RAND_MAX+1.0);  //uniform random variables
    double U2=(rand()+1.0)/(RAND_MAX+1.0);

    return sqrt(-2.0*log(U1))*cos(2.0*pi*U2);   //Box-Muller method
}
