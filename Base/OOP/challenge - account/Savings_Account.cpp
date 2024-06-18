#include "Savings_Account.h"

bool Savings_Account::deposit(double amount){
  amount += amount * (int_rate/100);
  return Account::deposit(amount);
};

Savings_Account::Savings_Account() : Account("undefined", 0.0), int_rate{5}{};
Savings_Account::Savings_Account(double bal) : Account("undefined", bal), int_rate{5}{};
Savings_Account::Savings_Account(std::string name) : Account(name, 0.0), int_rate{5}{};
Savings_Account::Savings_Account(std::string name, double bal) : Account(name, bal), int_rate{5}{};  
Savings_Account::Savings_Account(std::string name, double bal, double interest) : Account(name, bal), int_rate{interest}{};  

