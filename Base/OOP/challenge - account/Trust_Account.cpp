#include "Trust_Account.h"
#include "Account.h"

#include <iostream>
bool Trust_Account::deposit(double amount){
  if(amount >= 5000) amount += 50;
  return Account::deposit(amount);
};
bool Trust_Account::withdraw(double amount){
  if(amount > balance * 0.2) return false;
  if(withdrawals++ == 3) return false;
  return Account::withdraw(amount);
}