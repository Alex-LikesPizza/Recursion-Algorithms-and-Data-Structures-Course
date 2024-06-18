#include <iostream>

#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main(){
  Trust_Account trust_account{"trust", 5000, 12};
  trust_account.deposit(5000);
  trust_account.withdraw(5000); // no withdraw (too much)
  trust_account.withdraw(1000); // 1
  trust_account.withdraw(1000); // 2
  trust_account.withdraw(1000); // 3
  trust_account.withdraw(1000); // no withdraw (to many withdrawals)
  trust_account.showBalance(); "7050";

  Checking_Account checking_account{"checking"};
  checking_account.deposit(100);
  checking_account.withdraw(8.5);
  checking_account.showBalance(); "90"; // 100 - 8.5 - 1.5(fee)
}