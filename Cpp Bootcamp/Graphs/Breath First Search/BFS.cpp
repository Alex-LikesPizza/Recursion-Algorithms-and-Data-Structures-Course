#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <list>

#define NMAX 100

using namespace std;

struct Node{
  int sourceId = -1;
  int explored = false;
  vector<int> neighbors;

};

void logQueue(deque<int>& queue){
  for(int nodeId : queue){
    cout << nodeId << " ";
  }
  cout << endl;
}

bool isInQueue(deque<int>& queue, int target){
  int res = false;
  for(int id : queue){
    if(id == target){
      res = true;
    }
  }
  return res;
}

int main(){
  ifstream fin("BFS.in");
  ofstream fout("BFS.out");

  //undirected graph
  deque<int> queue;
  Node nodes[NMAX];

  int from, to;
  fin >> from >> to;

  int inNode1, inNode2;
  while(fin >> inNode1 >> inNode2){
    nodes[inNode1].neighbors.push_back(inNode2);
    nodes[inNode2].neighbors.push_back(inNode1);
  }

  queue.push_front(from);
  nodes[from].explored = true;

  while(!queue.empty()){
    int nodeId = queue.back();
    queue.pop_back();

    for(int neighborId : nodes[nodeId].neighbors){
      if(!nodes[neighborId].explored){
        queue.push_front(neighborId);
        nodes[neighborId].sourceId = nodeId;
        nodes[neighborId].explored = true;
      }
    }
  }

  int sourceId = to;
  list<int> path;
  while(sourceId != from){
    path.push_front(sourceId);
    sourceId = nodes[sourceId].sourceId;
  }
  path.push_front(from);

  for(int id : path){
    fout << id <<" ";
  }



  fin.close();
  fout.close();
}