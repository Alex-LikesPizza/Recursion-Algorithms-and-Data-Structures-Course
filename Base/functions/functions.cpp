#include <iostream>
#include <string>


using namespace std;

// Function Prototypes
void print(); // Can be initialized, called and then defined later.
int getN(int n); // or [ int getN(int); ] (name is optional)

// Function with default value
int getDefaultN(int n = 0){
  return n;
}

// Overloading Functions
void print(int n);
void print(int n, int r);
void print(string s);
int print(int n, double d); 
// int print(int n); -error
// int print(int n, float f = 2); - runtime error 

// Read-only Values
void printArray(int arr[], size_t size);

int main(){
  
  
  return 0;
}

int getN(int n){
  return n;
}

void print(){
  cout << "Hello World" << endl;
}
void print(int n){
  cout << n << endl;
}
void print(int n, int r){
  cout << n << ' ' << r << endl;
}
void print(string s){
  cout << s << endl;
}
int print(int n, double d){
  cout << "Returning " << n << " + " << d << endl;
  return n + d;
}

// void printArray(int arr[], size_t size){
//   for(int i = 0; i < size; i++){
//     cout << arr[i];
//   }
//   arr[0] = 2; // bug... will change arr[0] to 2 if called
// };
void printArray(const int arr[], size_t size){
  for(int i = 0; i < size; i++){
    cout << arr[i];
  }
  // arr[0] = 2; -error
};