#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"

class Trust_Account : public Savings_Account{
  using Savings_Account::Savings_Account;
  private:
    int withdrawals = 0;
  public:
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif