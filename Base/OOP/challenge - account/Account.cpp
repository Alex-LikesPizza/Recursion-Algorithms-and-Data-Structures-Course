#include "account.h"

#include <iostream>
#include <string>

bool Account::deposit(double amount){
  balance += amount;
  std::cout << "Deposited " << amount << " in " << name << "'s balance account. Total: " << balance << std::endl;
  return true;
}
bool Account::withdraw(double amount){
  if(balance - amount < 0) return false;
  balance -= amount;
  return true;
}

void Account::showBalance(){
  std::cout << name << " has " << balance << " in the account" << std::endl;
}

Account::Account(std::string name, double balance) : name{name}, balance{balance}{};
Account::Account() : Account("undefined", 0.0){};
Account::Account(double balance) : Account("undefined", balance){};
Account::Account(std::string name) : Account(name, 0.0){};

Account& Account::operator+=(const Account& rhs){
  balance += rhs.balance;
  return *this;
}
Account& Account::operator-=(const Account& rhs){
  balance -= rhs.balance;
  return *this;
}