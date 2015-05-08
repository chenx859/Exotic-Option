#include"PathDepOption.h"
#include<iostream>
#include<cmath>
#include<vector>


using namespace std;

double PathDepOption::PriceMC(BlackSchollesmodel& model, long N)
{
    double sum=0.0;
    double sumsq = 0.0;
    vector<double> Path(m_m);

    for(int i=0;i<N;i++)
    {
        model.GeneratePath(m_T,m_m,Path);
        sum+=payoff(Path);
        sumsq+=payoff(Path)*payoff(Path);
    }

    sdeviation = exp(-model.Getr()*m_T)*sqrt(sumsq-sum/((double) N))/sqrt((double)((N-1)*N));

    return exp(-model.Getr()*m_T)*sum/(double)N;
}

