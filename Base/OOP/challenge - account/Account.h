#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account {
  protected:
    std::string name;
    double balance;

  public:
    void showBalance();
    bool deposit(double amount);
    bool withdraw(double amount);

    Account(std::string name, double balance);
    Account();
    Account(double balance);
    Account(std::string name);
    
    Account& operator+=(const Account& rhs);
    Account& operator-=(const Account& rhs);
};

#endif