#include <iostream>
#include<string.h>
#include "atm.hpp"
using namespace std;
 typedef struct {
    long int fdnum;
    long int amount;
    long int duration;
    long int roi;
    char date[40];

}Fd;
class Deposits: virtual public BaseAccount{
    public:
    static long long int fdNumGen;
     multimap<long long int,Fd> Fds;
      Fd fd;
      Deposits(){};
     /*  Deposits(string _firstname,string _lastname,string _address,long int _balance )
       :BaseAccount{_firstname,_lastname,_address,_balance }{};*/
    long long int openFixedDeposit(long int amt, int dur){
        cout<<"opening fixed deposit"<<endl;
        fdNumGen=fdNumGen+1;
        long long int fdnum = fdNumGen+1;
        int roi;
        time_t now = time(0);
        char* dt = ctime(&now);
        if(dur>12)roi=6.5;
        else
        {
            roi=6;
        }
        if((balance - amt)>0)
        {
        fd.fdnum=fdnum,fd.amount = amt,fd.duration=dur,fd.roi=roi,
        strcpy(fd.date,dt);
         
         Fds.insert(std::pair<long long int,Fd>(fdnum,fd));
         removeFunds(amt);
         cout<<"Fd:"<<fdnum<<"is created"<<endl;
        }
        else
        {
            cout<<"Insufficient Balance to create an FD"<<endl;
        }
        return fdnum;

    }
    void closeFixedDeposit(long long int key)
    {
         multimap<long long int,Fd>::iterator it = Fds.find(key);
         cout <<"Fd:"<<key<<"is closed."<<it->second.amount<<"is credited to your Bank account"<<endl;
         addFunds(it->second.amount);
    }


};