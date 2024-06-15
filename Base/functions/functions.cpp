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
inline void print(int n); // inline - "places" the code from within the function wherever it is called
inline void print(int n, int r);
inline void print(string s);
inline int print(int n, double d); 
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

inline void print(){
  cout << "Hello World" << endl;
}
inline void print(int n){
  cout << n << endl;
}
inline void print(int n, int r){
  cout << n << ' ' << r << endl;
}
inline void print(string s){
  cout << s << endl;
}
inline int print(int n, double d){
  cout << "Returning " << n << " + " << d << endl;
  return n + d;
}

// void printArray(int arr[], size_t size){
//   for(int i = 0; i < size; i++){
//     cout << arr[i];
//   }
//   arr[0] = 2; // bug... will change arr[0] to 2 if called (even if not intended)
// };
void printArray(const int arr[], size_t size){
  for(int i = 0; i < size; i++){
    cout << arr[i];
  }
  // arr[0] = 2; -error
};