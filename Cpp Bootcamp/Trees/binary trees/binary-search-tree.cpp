#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
  Node* leftChild;
  Node* rightChild;
  int value;

  Node(int val){
    leftChild = nullptr;
    rightChild = nullptr;
    value = val;
  }

  ~Node(){
    if(leftChild)
      delete leftChild;
    if(rightChild)
      delete rightChild;
  }

};

class BinaryTreeUtils{
  public:
    Node* findNode(Node* node, int data, bool parent = false){
      if(!node->leftChild && !node->rightChild){
        cout << "Node not found" << endl;
        return nullptr;
      }
      if(data < node->value){
        if(node->leftChild->value == data)
          return (parent? node : node->leftChild);
        return findNode(node->leftChild, data);
      }
      else if(data > node->value){
        if(node->rightChild->value == data)
          return (parent? node : node->rightChild);
        return findNode(node->rightChild, data);
      }
      return node;
    }

  public:
    void insert(Node* node, int value){
      if(value < node->value){
        if(node->leftChild == nullptr){ 
          node->leftChild = new Node(value);
        }
        else insert(node->leftChild, value);
      }
      else if(value > node->value){
        if(node->rightChild == nullptr){
          node->rightChild = new Node(value);
        }
        else insert(node->rightChild, value);
      }
    }
    int findMax(Node* node){
      if(node->rightChild == nullptr){
        return node->value;
      }
      return findMax(node->rightChild);
    }
    int findMin(Node* node){
      if(node->leftChild == nullptr){
        return node->value;
      }
      return findMax(node->rightChild);
    }
    void traverse(Node* node){ // and sort

      if(node->leftChild != nullptr)
        traverse(node->leftChild);
      
      //... Do stuff here
      cout << node->value << " ";
      //...

      if(node->rightChild != nullptr)
        traverse(node->rightChild);
    }

    void remove(Node* rootNode, int data){
      if(rootNode == nullptr){
        cout << "Tree is Empty" << endl;
        return;
      }
      Node* nodeParent = findNode(rootNode, data, true);
      bool nodeIsLeftOfParent; Node* node;
      if(nodeParent->leftChild->value == data){
        nodeIsLeftOfParent = true;
        node = nodeParent->leftChild;
      }
      else{
        nodeIsLeftOfParent = false;
        node = nodeParent->rightChild;
      }

      if(!node->leftChild && !node->rightChild){
        if(nodeIsLeftOfParent)
          nodeParent->leftChild = nullptr;
        else 
          nodeParent->rightChild = nullptr;
        delete node;
      }
      


      
    }


}btu;


int main(){

  ifstream fin ("binary-tree.in");
  ofstream fout ("binary-tree.out");

  int n; fin >> n;
  
  int value; fin >> value;

  Node* root = new Node(value);

  for(int i = 1; i < n; i++){
    int value; fin >> value;
    btu.insert(root, value);
  }
  // i give up for now...
  cout << root->leftChild->rightChild->rightChild->value << endl;
  // btu.remove(root, 3);

  delete root;
  fin.close();
  fout.close();

  return 0;
}