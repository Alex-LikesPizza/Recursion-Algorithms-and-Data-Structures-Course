#include <iostream>
#include <fstream>
#include <limits>

#define inf INT_MAX
#define nmax 100
using namespace std;

int adjMat[nmax][nmax];
int cost[nmax], source[nmax], explored[nmax];

int findMin(int n){
  int min = inf;
  int minIndex;
  for(int i = 1; i <= n; i++){
    if(!explored[i] && cost[i] < min){
      minIndex = i;
      min = cost[i];
    }
  }
  return minIndex;
}

void findPath(int nodeId, int n, int goal){
  explored[nodeId] = true;
  if(nodeId == goal)
    return;
  for(int i = 1; i <= n; i++){
    if(adjMat[nodeId][i] == 0)continue;
    int pathCost = cost[nodeId] + adjMat[nodeId][i];
    if(!explored[i] && pathCost < cost[i]){
      cost[i] = pathCost;
      source[i] = nodeId;
    }
  }

  findPath(findMin(n), n, goal);
}
int main(){
  ifstream fin ("Dijkstra's-Algorithm.in");
  ofstream fout ("Dijkstra's-Algorithm.out");
  int n, op, from, goal; fin >> n >> op >> from >> goal;
  

  for (int i = 1; i <= n; i++){
    cost[i] = inf;
    source[i] = -1;
    explored[i] = false;
    for (int j = 1; j <= n; j++){
      adjMat[i][j] = 0;
    }
  }
  cost[1] = 0;
  source[1] = 1;

  for(int i = 0; i < op; i++){
    int node, nodeTo, weight;
    fin >> node >> nodeTo >> weight;

    adjMat[node][nodeTo] = weight;
  }
  // for(int i = 1; i <= n; i++){
  //   for (int j = 1; j <= n; j++){
  //     cout << adjMat[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  findPath(from, n, goal);

  fout << "cost: " << cost[goal] << endl;
  
  int currentNode = goal;
  while(currentNode != from){
    fout << currentNode << " ";
    currentNode = source[currentNode];
  }
  fout << from;




  fin.close();
  fout.close();
  return 0;
}