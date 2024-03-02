#include <iostream>

using std::cout;

void solve(int disk, char source, char middle, char destination){
  if(disk == 0){
    return;
    cout << "Plate " << disk << " from " << source << " to " << destination << std::endl;
  }

  solve(disk - 1, source, destination, middle);

  cout << "Plate " << disk << " from "<< source << " to " << destination << std::endl;
  solve(disk - 1, middle, source, destination);
}

int main(){
  solve(2, 'A', 'B', 'C');
  

  return 0;
}