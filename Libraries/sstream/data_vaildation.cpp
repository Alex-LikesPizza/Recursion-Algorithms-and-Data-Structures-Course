#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

void resetConsoleBuffer(){
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main(){
  string entry;
  string name;
  int age; 
  double monthly_salary;

  cout << "Name: ";
  cin >> name;
  resetConsoleBuffer();

  cout << "Age: ";
  cin >> entry;

  while(true){
    istringstream validator(entry);
    if(validator >> age) break;
    resetConsoleBuffer();
    cout << "Please enter a valid integer: ";
    cin >> entry;
  }

  cout << "Monthly Salary: ";
  cin >> entry;
  while(true){
    istringstream validator(entry);
    if(validator >> monthly_salary) break;
    resetConsoleBuffer();
    cout << "Please enter a valid number: ";
    cin >> entry;
  }

  ostringstream nameAndAge;
  nameAndAge << name << ", " << age;
  cout << left;
  cout << setw(10) << nameAndAge.str() << ": $" << monthly_salary << endl;


  return 0;
}