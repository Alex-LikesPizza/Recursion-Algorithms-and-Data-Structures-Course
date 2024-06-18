#include "Checking_Account.h"

bool Checking_Account::withdraw(double amount){
  return Account::withdraw(amount + fee);
};