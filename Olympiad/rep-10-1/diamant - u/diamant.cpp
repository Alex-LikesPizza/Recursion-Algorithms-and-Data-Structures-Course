#include <iostream>
#include <fstream>
#include <vector>
#define nmax 2000
using namespace std;

int dimX, dimY;
char mat[nmax][nmax];

int diamonds = 0;
void findTip(int x, int y, int dimX, int dimY){
  if(x >= dimX) {
    findTip(0, y + 1, dimX, dimY);
    return;
  }
  if(y >= dimY) return;

  if(mat[x][y] == '#') /**/;
  findTip(x + 1, y, dimX, dimY);
}

void findDiamond(int x, int y, int dimX, int dimY, int k){
  
}

int main(){

  ifstream fin("diamant.in");
  ofstream fout("diamant.out");

  fin >> dimX >> dimY;
  for(int i = 0; i < dimY; i++){
    for(int j = 0; j < dimX; j++){
      fin >> mat[dimY][dimX];
    }
  }



  fin.close();
  fout.close();

  return 0;
}