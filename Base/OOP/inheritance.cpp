#include <iostream>
#include <string>

using namespace std;

class Account{ 
public:
  double balance = 0;
  string name = "none";

  void deposit(double amount){
    cout << "Account deposit called with " << amount << endl;
  }
  Account(){}; // Must be declared for child class default constructor
  Account(string name): name{name}{};
};
class Savings_Account: public Account{
public:
  int interest_rate;
  void deposit(double amount){
    cout << "Savings account deposit called with " << amount << endl;
  }

};

class Base{
  public: int a = 0;
  protected: int b = 1;
  private: int c = 2;

public: 
  void displayAvailableValues(){
    cout << "Accessing base class inner members" << endl;
    
    cout << "a(public): " << a << endl; 
    cout << "b(protected): " << b << endl;
    cout << "c(private): " << c << endl;
  }
};
class Public: public Base{
  friend void publicClass(Base& base);
  // public -> public: a
  // protected -> protected: b
  // private -> no-access: c
public: 
  void displayAvailableValues(){
    cout << "Accessing public class inner members" << endl;
    
    cout << "a(public): " << a << endl; 
    cout << "b(protected): " << b << endl;
    cout << "c: " << "no-access" << endl;
  }
};
class Protected: protected Base{
  friend void protectedClass(Base& base);
  // public -> protected: a
  // protected -> protected: b
  // private -> no-access: c

public: 
  void displayAvailableValues(){
    cout << "Accessing protected class inner members" << endl;
    
    cout << "a(protected): " << a << endl; 
    cout << "b(protected): " << b << endl;
    cout << "c: " << "no-access" << endl;
  }
};
class Private: private Base{
  friend void privateClass(Base& base);
  // public -> private: a
  // protected -> private: b
  // private -> no-access: c
public: 
  void displayAvailableValues(){
    cout << "Accessing protected class inner members" << endl;
    
    cout << "a(private): " << a << endl; 
    cout << "b(private): " << b << endl;
    cout << "c: " << "no-access" << endl;
  }
};

class Multiplier{
private:
  int base_value;
public:
  void print_base_value(){
    cout << base_value << endl;
  }

  Multiplier() : base_value{0}{
    cout << "Called base no-args constructor base_value = " << base_value << endl;
  };
  Multiplier(int x) : base_value{x}{
    cout << "Called base one-arg constructor: base_value = " << base_value << endl;
  };
  ~Multiplier(){
    cout << "Called deconstructor for base" << endl;
  }
};
class DoubleMultiplier : public Multiplier{
  // using Multiplier::Multiplier; // Inherits all Multiplier constructors
private:
  int double_value;
public:
  void print_double_value(){
    cout << double_value << endl;
  }

  DoubleMultiplier() : /*Multiplier(),*/ double_value{0}{
    cout << "Called double no-args constructor double_value = " << double_value << endl;
  };
  DoubleMultiplier(int x) : Multiplier(x), double_value{x * 2}{
    cout << "Called double one-arg constructor: double_value = " << double_value << endl;
  };
  ~DoubleMultiplier(){
    cout << "Called deconstructor for double" << endl;
  }
};

class Number{
protected:
  double value;
public:

  Number() : value{0}{};
  Number(double x) : value{x}{};
  Number(const Number& source){
    value = source.value;
  }
  Number& operator=(const Number &rhs){
    if(this == &rhs)
      return *this;
    value = rhs.value;
    return *this;
  }
};
class ComplexNumber : public Number{
private:
  double im_value;
public:

  ComplexNumber() : Number(), im_value{0}{
    cout << "Running complex no-args constructor" << endl;
  };
  ComplexNumber(double re, double im) : Number(re), im_value{im}{
    cout << "Running complex args constructor" << endl;
  };
  ComplexNumber(const ComplexNumber& n) : Number(n){
    cout << "Running complex copy constructor" << endl;
    im_value = n.im_value;
  }
  ComplexNumber& operator=(const ComplexNumber& rhs){
    cout << "Running complex operator=" << endl;
    if(this == &rhs)
      return *this;
    Number::operator=(rhs);
    im_value = rhs.im_value;
    return *this;
  }
};
class Shape{}; class Area{}  ;
class Rectangle : public Shape, public Area{}; // Multiple inheritance

int main(){
  // // --------- Inheriting ----------- //
  // Account account("any account");
  // account.name = "account";
  // account.balance = 1000;
  // account.deposit(1999);

  // // Savings_Account savings_account("deposit account"); // Error: Cannot access base class constructor
  // Savings_Account savings_account;
  // savings_account.name = "savings";
  // savings_account.balance = 1000;
  // savings_account.interest_rate = 10; // access new members
  // savings_account.deposit(999); // previous deposit method overwritten

  // ------------- Inheritance Type -----------//
  // Base base;
  // Public basedPublic;
  // Protected basedProtected;
  // Private basedPrivate;

  // base.displayAvailableValues();
  // basedPublic.displayAvailableValues();
  // basedProtected.displayAvailableValues();
  // basedPrivate.displayAvailableValues();

  // // basedPrivate.a; // Error: no access (private)
  // // basedPrivate.b; // Error: no access (private)
  // // basedPrivate.c; // Error: no access (private)

  // // basedProtected.a; // Error: no access (protected)
  // // basedProtected.b; // Error: no access (protected)
  // // basedProtected.c; // Error: no access (private)

  // // basedPublic.b; // Error: no access (protected)
  // // basedPublic.b; // Error: no access (private)
  // basedPublic.a; // ok (public)
  
  // ------------- Inheritance constructors --------------------- //
  
  // cout << "Base Multiplier: " << endl;
  // {Multiplier once {2};}
  // cout << endl << "Double Multiplier: " << endl;
  // {DoubleMultiplier dbl {2};}
  // cout << endl << "Double Multiplier Empty: " << endl;
  // {DoubleMultiplier dbl_empty{};}

  // -------- Copy constructor; Move constructor(same idea); operator= Inheritance -----------//

  ComplexNumber cp1 {10.5, 15.5};
  ComplexNumber cp2 {};
  ComplexNumber cp3 {cp1};
  cp1 = cp2;


}