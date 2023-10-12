#include <iostream>
using namespace std;

void tail(int i){

    if(i == 0) return;

    cout << i;

    tail(i - 1);
}

void head(int i){

    if(i == 0) return;

    head(i - 1);

    cout << i;
}

int main(){

  cout << "Tail Recursion:" << endl;

  tail(5);

  cout << endl << "Head Recursion:" << endl;

  head(5);
  return 0;
}