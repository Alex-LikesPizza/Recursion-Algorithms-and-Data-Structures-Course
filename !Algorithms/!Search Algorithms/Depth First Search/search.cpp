#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <iomanip>

using namespace std;

struct Node {
  int id = -1;
  unordered_set<int> neighborsId;
  int visited = false;

  Node(int id): id(id) {};
};
bool bfs_is_graph_cyclic2(vector<Node> nodes, int startId){
  vector<int> stack;

  stack.push_back(startId);

  while(!stack.empty()){
    int nodeId = stack.back(); stack.pop_back();
    
    if(nodes.at(nodeId).visited) return true;
    nodes.at(nodeId).visited = true;
    for(int neighbourId : nodes.at(nodeId).neighborsId){
      stack.push_back(neighbourId);
    }
  }

  return false;
}

int main(){
  vector<Node> nodes;
  int v, e;

  ifstream fin ("file.in");
  fin >> v >> e;
  int from, to;
  for(int i = 0; i < v; i++){
    nodes.emplace_back(i);
  }
  while (fin >> from >> to){
    nodes.at(from).neighborsId.insert(to);
  }
  fin.close();  
  int cyclic = bfs_is_graph_cyclic2(nodes, 1);
  cout << boolalpha << cyclic;
  return 0;
}