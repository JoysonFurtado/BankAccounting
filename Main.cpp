/* Example code for 
classes, Multipath Inheritance, static variables,Dreaded Daimond
*/
#include <iostream>
#include <istream>
#include <string>
#include <map>
#include <ctime>
#include "deposits.hpp"
//#include "atm.hpp"
using namespace std;

  long int BaseAccount:: accNoGen = 100120200;
  long long int Deposits::fdNumGen = 1001202007000;

  class BankAccount:public Deposits,public ATM{
    public:
    BankAccount(string _firstname,string _lastname,string _address,long int _balance ){
       //:Deposits{_firstname,_lastname,_address,_balance }{
         baseAccountInitialise(_firstname,_lastname,_address,_balance );
       };

  };

int main () {
  string _first,_last, _address;
  long long int fd;
  long int _balance;
  cout<< "Enter your First Name"<<endl;
   getline(cin,_first);
  cout<< "Enter your Last Name"<<endl;
   getline(cin,_last);
  cout<< "Enter your Address"<<endl;
  getline(cin,_address);
  cout<<"Deposit base amount with which you want to open your Account with "<<endl;
  cin>> _balance;

  //BaseAccount Account(_first,_last, _address,_balance);
  BankAccount Account(_first,_last, _address,_balance);
  Account.displayAccount();
  Account.addFunds(400);
  Account.removeFunds(200);
  Account.viewAllTransactions();
  fd= Account.openFixedDeposit(100,7);
  cout<<"closing Deposit";
  Account.closeFixedDeposit(fd);
  Account.displayAccount();
   Account.viewAllTransactions();
  return 0;
}