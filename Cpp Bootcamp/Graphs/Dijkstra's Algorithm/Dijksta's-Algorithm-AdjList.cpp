#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

#define nmax 100
using namespace std;
struct Neighbor{
  int id;
  int weight;
};

struct Node{
  int cost = INT_MAX;
  bool explored = false;
  int source;

  vector<Neighbor> neighbors;

} nodes[nmax];

int findMin(int n){
  int minVal = INT_MAX, minIndex;
  for(int i = 1; i <= n; i++){
    if(!nodes[i].explored && nodes[i].cost < minVal){
      minVal = nodes[i].cost;
      minIndex = i;
    }
  }

  return minIndex;
}

void findPath(int nodeId, int goalId, int n){
  nodes[nodeId].explored = true;
  if(nodeId == goalId) return;

  for(Neighbor neighbor : nodes[nodeId].neighbors){
    if(nodes[neighbor.id].explored)continue;
    int cost = nodes[nodeId].cost + neighbor.weight;
    if(cost < nodes[neighbor.id].cost){
    nodes[neighbor.id].source = nodeId;
    nodes[neighbor.id].cost = cost;
    }
  }

  findPath(findMin(n), goalId, n);
}

int main(){
  ifstream fin("Dijkstra's-Algorithm.in");
  ifstream fout("Dijkstra's-Algorithm.in");

  int n; fin >> n;
  int op; fin >> op;
  int from, goal; fin >> from >> goal;

  int nodeIdFrom, nodeIdTo, cost; 
  while(fin >> nodeIdFrom >> nodeIdTo >> cost){
    Neighbor neighbor;
    neighbor.id = nodeIdTo;
    neighbor.weight = cost;
    nodes[nodeIdFrom].neighbors.push_back(neighbor);
  }
  
  nodes[from].cost = 0;
  nodes[from].source = from;

  findPath(1, 13, n);

  cout << nodes[goal].cost;

  fin.close();
  fout.close();
  return 0;
}