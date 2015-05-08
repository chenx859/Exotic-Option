#include <iostream>
#include"BlackSchollesmodel.h"
#include"PathDepOption.h"
#include"ArithAsian.h"
#include"Barrier.h"
#include"ImpliVol.h"
#include<vector>

using namespace std;

int main()
{
    int choice;
    double S0, r, sigma, T, K, L,MktPrice,IV;
    char PutCall;
    long N = 100000;//N is the number of iteration in the monte-carlo algorithm
    int m = 100;//m is number of step of the stock path
    double c=0.0;
    double a = 0.0000001;// Bisection algorithm starting value
    double b = 10.0;// Bisection algorithm starting value
    
    while(choice!=9) //Run a loop till the user asks to exit using choice = 9
    {
        cout<<"Welcome to use Exotic Options Calculator"<<endl;
        cout<<"Enter 1 to price Asian call option"<<endl;
        cout<<"Enter 2 to price Asian put option"<<endl;
        cout<<"Enter 3 to price Barrier call option"<<endl;
        cout<<"Enter 4 to price Barrier put option"<<endl;
        cout<<"Enter 5 to calculate implied volatility"<<endl;
        cout<<"Enter 9 to Exit"<<endl;
        cin>>choice; //inputting choice from user
        switch(choice)
        {
            case 1://Enter an option information
            {
                cout<<"Enter Current Stock Price($): ";
                cin>>S0;
                cout<<"Enter the risk free rate: ";
                cin>>r;
                cout<<"Enter the stock volatility: ";
                cin>>sigma;
                cout<<"Enter the Strike Price($): ";
                cin>>K;
                cout<<"Enter the Time to Maturity(year): ";
                cin>>T;
                cout<<endl;
                BlackSchollesmodel model(S0,r,sigma,c); //used to define the stock path
                ArithAsianCall callasian(T,m,K);
                cout<<"Asian option call = "<<callasian.PriceMC(model,N)<<endl;
                cout<<"standard deviation = "<<callasian.sdeviation<<endl;
                cout<<endl;
                break;
            }
            case 2:
            {
                cout<<"Enter Current Stock Price($): ";
                cin>>S0;
                cout<<"Enter the risk free rate: ";
                cin>>r;
                cout<<"Enter the stock volatility: ";
                cin>>sigma;
                cout<<"Enter the Strike Price($): ";
                cin>>K;
                cout<<"Enter the Time to Maturity(year): ";
                cin>>T;
                BlackSchollesmodel model(S0,r,sigma,c); //used to define the stock path
                ArithAsianPut putasian(T,m,K);
                cout<<"Asian option put = "<<putasian.PriceMC(model,N)<<endl;
                cout<<"standard deviation = "<<putasian.sdeviation<<endl;
                cout<<endl;
                break;
            }
            case 3:
            {
                cout<<"Enter Current Stock Price($): ";
                cin>>S0;
                cout<<"Enter the risk free rate: ";
                cin>>r;
                cout<<"Enter the stock volatility: ";
                cin>>sigma;
                cout<<"Enter the Strike Price($): ";
                cin>>K;
                cout<<"Enter the Barrier Price($): ";
                cin>>L;
                cout<<"Enter the Time to Maturity(year): ";
                cin>>T;
                BlackSchollesmodel model(S0,r,sigma,c); //used to define the stock path
                BarrierCallUO call(T,m,K,L);
                BarrierCallDO call1(T,m,K,L);
                BarrierCallUI call2(T,m,K,L);
                BarrierCallDI call3(T,m,K,L);
                cout<<"Barrier option Call Up and Out = "<<call.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<call.sdeviation<<endl;
                cout<<endl;
                
                cout<<"Barrier option Call Down and Out = "<<call1.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<call1.sdeviation<<endl;
                cout<<endl;
                
                cout<<"Barrier option Call Up and In = "<<call2.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<call2.sdeviation<<endl;
                cout<<endl;
                
                cout<<"Barrier option Call Down and In = "<<call3.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<call3.sdeviation<<endl;
                cout<<endl;
                break;
            }
            case 4:
            {
                cout<<"Enter Current Stock Price($): ";
                cin>>S0;
                cout<<"Enter the risk free rate: ";
                cin>>r;
                cout<<"Enter the stock volatility: ";
                cin>>sigma;
                cout<<"Enter the Strike Price($): ";
                cin>>K;
                cout<<"Enter the Barrier Price($): ";
                cin>>L;
                cout<<"Enter the Time to Maturity(year): ";
                cin>>T;
                BlackSchollesmodel model(S0,r,sigma,c); //used to define the stock path
                BarrierPutUO put(T,m,K,L);
                BarrierPutDO put1(T,m,K,L);
                BarrierPutUI put2(T,m,K,L);
                BarrierPutDI put3(T,m,K,L);
                cout<<"Barrier option Put Up and Out = "<<put.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<put.sdeviation<<endl;
                cout<<endl;
                
                cout<<"Barrier option Put Down and Out = "<<put1.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<put1.sdeviation<<endl;
                cout<<endl;
                
                cout<<"Barrier option Put Up and In = "<<put2.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<put2.sdeviation<<endl;
                cout<<endl;
                
                cout<<"Barrier option Put Down and In = "<<put3.PriceMC(model, N)<<endl;
                cout<<"standard deviation = "<<put3.sdeviation<<endl;
                cout<<endl;
                break;
            }
            case 5:
            {
                cout<<"Enter Current Stock Price($): ";
                cin>>S0;
                cout<<"Enter the risk free rate: ";
                cin>>r;
                cout<<"Enter the type of option(C or P): ";
                cin>>PutCall;
                cout<<"Enter the Strike Price($): ";
                cin>>K;
                cout<<"Enter the Market Price of the option($): ";
                cin>>MktPrice;
                cout<<"Enter the Time to Maturity(year): ";
                cin>>T;
                
                ImpliedV ImpV(S0,K,r,T,MktPrice,PutCall);
                IV = ImpV.BisecBSV(a, b);
                cout<<"The implied volatility is: "<<IV<<endl;
                cout<<endl;
                break;
            }
            case 9:
            {
                cout<<"Thank you for using Exotic Option Calculator"<<endl;//Exit
                break;
            }
            default:
                cout<<"That is not a valid entry, please try again."<<endl;
        }
    }
}

