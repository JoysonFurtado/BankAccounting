#include <iostream>
#include<string.h>
#include "BaseAccount.hpp"

class ATM:virtual public BaseAccount{
    public:
    void atmWithdrawl(long int amt){
        if(amt <= 10000){
        removeFunds(amt);
        }
        else{
            cout<<"Amount entered is more than Withdrawl limit"<<endl;
        }

    }
    void atmDeposit(long int amt){
        double depAmt;
        depAmt= amt - (0.01*(amt));
        addFunds(depAmt);
    }
};