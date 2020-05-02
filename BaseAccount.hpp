#include <iostream>
#include <istream>
#include <string>
#include <map>
#include <ctime>

using namespace std;

class BaseAccount {
  public:
   string firstName;
   string lastName;
   string address;
   long int accNo;
   long int balance;
   multimap<string,long int> transactions;
   static long int accNoGen; 
  BaseAccount(){
  };
  void baseAccountInitialise(string _firstname,string _lastname,string _address,long int _balance ){
    firstName = _firstname;
    lastName = _lastname;
    address = _address;
    balance = _balance;
    accNoGen = accNoGen + 1;
    accNo = accNoGen;
    time_t now = time(0);
    char* dt = ctime(&now);
     transactions.insert(std::pair<string,long int>(dt,balance));
     }
    long int getBalance (void){return balance;}
    bool addFunds(long int amount){
      time_t now = time(0);
      char* dt = ctime(&now);
      balance += amount;
      transactions.insert(std::pair<string,long int>(dt,amount));
      return true;
    }
    bool removeFunds(long int amount){
      time_t now = time(0);
      char* dt = ctime(&now);
       balance -= amount;
       amount -= (2*amount);
       transactions.insert(std::pair<string,long int>(dt,amount));
        return true;
    }
    void displayAccount(){
      cout<<"-----------------------Bank of München--------------------------"<<endl;
      cout<<"Account Holder:"<<lastName<<" "<<firstName<<endl;
      cout<<"Address:"<<address<<endl;
      cout<<"Current Balance:"<<balance<<"$"<<endl;
      cout<<"----------------------------------------------------------------"<<endl;
    }
    void viewAllTransactions(){
      cout<<"----------------------Recent Transactions-----------------------"<<endl;
      cout<<"Account Holder:"<<lastName<<" "<<firstName<<endl;
      for(multimap<string,long int> ::iterator it = transactions.begin(); it != transactions.end(); it++ )
      {
        cout<<it->first<<"---->"<<it->second<<"$"<<endl;
      }
      cout<<"---------------------------------------------------------------"<<endl;
    }
};