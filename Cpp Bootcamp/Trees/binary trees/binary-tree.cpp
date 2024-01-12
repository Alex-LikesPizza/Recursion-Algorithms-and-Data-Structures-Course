#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
  Node * root;
  Node * leftChild;
  Node * rightChild;
  int value;

  Node(int val = 0){
    root = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
    value = val;
  }

  ~Node(){
    delete leftChild;
    delete rightChild;
  }

};

void insert(Node* node, int value){
  if(value < node->value){
    if(node->leftChild == nullptr){ 
      node->leftChild = new Node(value);
      node->leftChild->root = node;
    }
    else insert(node->leftChild, value);
  }
  else if(value > node->value){
    if(node->rightChild == nullptr){
      node->rightChild = new Node(value);
      node->rightChild->root = node;
    }
    else insert(node->rightChild, value);
  }
  
}

int main(){

  ifstream fin ("binary-tree.in");
  ofstream fout ("binary-tree.out");

  int n; fin >> n;
  
  int value; fin >> value;

  Node* root = new Node(value);

  for(int i = 1; i < n; i++){
    int value; fin >> value;
    insert(root, value);
  }
  
  cout << root->leftChild->rightChild->value;

  
  delete root;
  fin.close();
  fout.close();

  return 0;
}