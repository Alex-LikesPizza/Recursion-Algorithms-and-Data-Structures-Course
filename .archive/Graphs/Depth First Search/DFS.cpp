#include <iostream>
#include <fstream>
#include <vector>

#define NMAX 100
using namespace std;

struct Node{
  bool explored = false;
  vector<int> neighborsId;

} nodes[NMAX];

bool existsPath = false;
void findPath(int nodeId, int goalId){
  nodes[nodeId].explored = true;
  if(nodeId == goalId) {
    existsPath = true;
    return;
  }
  if(existsPath) return;

  for(int neighborId : nodes[nodeId].neighborsId){
    if(!nodes[neighborId].explored){
      cout << "been to node: " << neighborId << endl;
      findPath(neighborId, goalId);
      if(existsPath)return;
    }
  }

}

int main(){
  ifstream fin ("DFS.in");
  ofstream fout ("DFS.out");

  int from, to; fin >> from >> to;
  int nodeLink1, nodeLink2;
  while(fin >> nodeLink1 >> nodeLink2){
    nodes[nodeLink1].neighborsId.push_back(nodeLink2);
  }

  findPath(from, to);
  cout << existsPath;

  fin.close();
  fout.close();

  return 0;
}