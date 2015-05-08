#include"Barrier.h"
#include<vector>

using namespace std;

//payoff Barrier Call Up&Out option
double BarrierCallUO::payoff(vector<double>& Path)const
{
    int length = Getm();
    for(int i=0;i<length;i++)
     {
         if(Path[i]>=m_L)
            return 0.0;

     }

    if(Path[length-1]>m_K)
        return Path[length-1]-m_K;

    return 0.0;
}

//payoff Barrier Call Down&Out option
double BarrierCallDO::payoff(vector<double>& Path)const
{
    int length = Getm();
    for(int i=0;i<length;i++)
     {
         if(Path[i]<=m_L)
            return 0.0;

     }

    if(Path[length-1]>m_K)
        return Path[length-1]-m_K;

    return 0.0;
}

//payoff Barrier Call Down&In option
double BarrierCallDI::payoff(vector<double>& Path)const
{
    int length = Getm();

    for(int i=0;i<length;i++)
     {
         if(Path[i]<=m_L)
            if(Path[length-1]>m_K)
                return Path[length-1]-m_K;

     }


    return 0.0;
}

//payoff Barrier Call Up&In option
double BarrierCallUI::payoff(vector<double>& Path)const
{
    int length = Getm();
    for(int i=0;i<length;i++)
     {
         if(Path[i]>=m_L)
            if(Path[length-1]>m_K)
                return Path[length-1]-m_K;
     }



    return 0.0;
}

//payoff Barrier Put Up&Out option
double BarrierPutUO::payoff(vector<double>& Path)const
{
    int length = Getm();
    for(int i=0;i<length;i++)
     {
         if(Path[i]>=m_L)
            return 0.0;

     }

    if(Path[length-1]<m_K)
        return m_K - Path[length-1];

    return 0.0;
}

//payoff Barrier Put Down&Out option
double BarrierPutDO::payoff(vector<double>& Path)const
{
    int length = Getm();
    for(int i=0;i<length;i++)
     {
         if(Path[i]<=m_L)
            return 0.0;

     }

    if(Path[length-1]<m_K)
        return m_K - Path[length-1];

    return 0.0;
}

//payoff Barrier Put Down&In option
double BarrierPutDI::payoff(vector<double>& Path)const
{
    int length = Getm();

    for(int i=0;i<length;i++)
     {
         if(Path[i]<=m_L)
            if(Path[length-1]<m_K)
                return m_K - Path[length-1];

     }


    return 0.0;
}

//payoff Barrier Put Up&In option
double BarrierPutUI::payoff(vector<double>& Path)const
{
    int length = Getm();
    for(int i=0;i<length;i++)
     {
         if(Path[i]>=m_L)
            if(Path[length-1]<m_K)
                return m_K - Path[length-1];
     }



    return 0.0;
}
