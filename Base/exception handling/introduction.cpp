#include <iostream>

using namespace std;

class DivideByZeroExcept{};

double getMedExceptInteger(const int grades[], const int length){
  double sum {0};
  double med {0};
  for(int i {0}; i < length; i++){
    sum+= grades[i];
  }
  try{
    if(length == 0)
      throw 0;
    med = sum / length;
  }
  catch(int& ex){
    cerr << "Can't divide by 0" << endl;
    return -1;
  }
  return med;
}
double getMedExceptAny(const int grades[], const int length){
    double sum {0};
  double med {0};
  for(int i {0}; i < length; i++){
    sum+= grades[i];
  }
  if(length < 0 || sum < 0)
    throw "Any type";
  if(length == 0)
    throw DivideByZeroExcept();
  med = sum / length;
  return med;
}
int main(){
  int grades[] {9, 10, 8, 9};
  int length {0}; // if 0 or if negative: throws an exception
  double sum {0};
  // double med = getMedExceptInteger(grades, length);
  double med2;

  try{ // outside the function
    med2 = getMedExceptAny(grades, length);
  }
  catch(DivideByZeroExcept& ex){
    med2 = -1;
    cerr << "Can't divide by 0" << endl;
  }
  catch(...){
    med2 = -1;
    cerr << "Can't divide by negative number" << endl;
  }

  cout << med2 << endl;
}