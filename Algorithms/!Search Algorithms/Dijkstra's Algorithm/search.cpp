#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
  int id;
  vector<pair<int, int>> neighborId_weight_vec;
  bool visited = false;
  int distance = INT_MAX;

  Node(int i): id(i){};
};
struct CompareNodes{
  bool operator()(const Node* left, const Node* right){
    return left->distance > right->distance;
  }
};

int dijkstra(int fromId, int toId, vector<Node>& nodes){
  priority_queue<Node*, vector<Node*>, CompareNodes> pq;
  nodes.at(fromId).distance = 0;
  pq.push(&nodes.at(fromId));

  while(!pq.empty()){
    Node& currentNode = *pq.top(); pq.pop();

    if(currentNode.id == toId) return currentNode.distance;
    if(currentNode.visited) continue;
    currentNode.visited = true;
    
    for(pair<int, int> neighbor_weight : currentNode.neighborId_weight_vec){
      if(nodes.at(neighbor_weight.first).visited) continue;
      int& prevDist = nodes.at(neighbor_weight.first).distance;
      const int pathDistance = currentNode.distance + neighbor_weight.second;
      if(prevDist > pathDistance) prevDist = pathDistance;
      pq.push(&nodes.at(neighbor_weight.first));
    }
  }
  return -1;
}

int main(){
  vector<Node> nodes;
  ifstream fin ("file.in");
  int n; fin >> n;
  for(int i = 0; i < n; i++){
    nodes.emplace_back(i);
  }
  int from, to, weight;
  while(fin >> from >> to >> weight){
    nodes.at(from).neighborId_weight_vec.emplace_back(to, weight);
  }
  fin.close();

  int minDistance = dijkstra(1, 6, nodes);
  cout << minDistance;
}