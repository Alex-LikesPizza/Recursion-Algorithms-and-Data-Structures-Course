#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "account.h"

class Checking_Account : public Account{
  using Account::Account;
  private:
    const double fee = 1.5;
  public:
    bool withdraw(double amount);
};

#endif