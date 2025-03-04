#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <utility>

using namespace std;

struct Node {
  int id = -1;
  unordered_set<int> neighborsId;
  int visited = false;
  int length = INT_MAX;
  Node(int id): id(id) {};
};

int dfs_min_length_from_a_to_b(int startId, int targetId, vector<Node> nodes){
  deque<int> queue;

  queue.push_back(startId);
  nodes.at(startId).length = 0;

  while(!queue.empty()){
    int nodeId = queue.front(); queue.pop_front();
    
    if(nodes.at(nodeId).visited) continue;
    nodes.at(nodeId).visited = true;
    if(nodeId == targetId) return nodes.at(nodeId).length;  

    for(int neighbourId : nodes.at(nodeId).neighborsId){
      if(nodes.at(neighbourId).visited == false){
        queue.push_back(neighbourId);
        nodes.at(neighbourId).length = nodes.at(nodeId).length + 1;
      }
    }
  }

  return -1;
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
    nodes.at(to).neighborsId.insert(from); 
  }
  fin.close();  
  int pathLength = dfs_min_length_from_a_to_b(7, 8, nodes);
  cout << pathLength;
  return 0;
}