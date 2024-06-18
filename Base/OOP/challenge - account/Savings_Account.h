#include "account.h"
#include <string>
#include <iostream>

#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

class Savings_Account : public Account{
  private:
    double int_rate;
  public:
    
    bool deposit(double amount);

    Savings_Account();
    Savings_Account(double bal);
    Savings_Account(std::string name);  
    Savings_Account(std::string name, double bal);  
    Savings_Account(std::string name, double bal, double interest);  

};


#endif