#include <iostream>
#include <fstream>
using namespace std;

int main(){

  ifstream fin("blugi.in");
  ofstream fout("blugi.out");

  unsigned n; fin >> n;

  unsigned colection[n];
  for(int i = 0; i < n; i++){
    fin >> colection[i];
  };

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(colection[j] > colection[j + 1]){
        int z = colection[j + 1];
        colection[j + 1] = colection[j];
        colection[j] = z;
      }
    }
  }
  
  for(int i = 0; i < n - 1; i++){
    if(colection[i] + 1 != colection[i + 1])
      fout << i + 2;
  }

  fin.close();
  fout.close();

  return 0;
}