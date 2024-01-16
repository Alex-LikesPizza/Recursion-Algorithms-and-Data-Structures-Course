#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
  Node* leftChild;
  Node* rightChild;
  Node* parent;
  int value;

  Node(int val){
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
    value = val;
  }

  ~Node(){
    delete leftChild;
    delete rightChild;
  }

};

class BinaryTreeUtils{
  private:
    Node* findNode(Node* node, int data){
      if(data < node->value)
        return findNode(node->leftChild, data);
      else if(data > node->value)
        return findNode(node->rightChild, data);
      else return node;
    }

  public:
    void insert(Node* node, int value){
      if(value < node->value){
        if(node->leftChild == nullptr){ 
          node->leftChild = new Node(value);
          node->leftChild->parent = node;
        }
        else insert(node->leftChild, value);
      }
      else if(value > node->value){
        if(node->rightChild == nullptr){
          node->rightChild = new Node(value);
          node->rightChild->parent = node;
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
        cout << "Node not found" << endl;
        return;
      }

      Node* node = findNode(rootNode, data);
      
      if(node->leftChild == nullptr && node->rightChild == nullptr){
        delete node;
        return;
      }

      if(node->leftChild == nullptr){
        if(node->parent->rightChild == node){
          node->parent->rightChild = node->rightChild;
          delete node;
        }
        else{
          node->parent->leftChild = node->rightChild;
          delete node;
        }
      }
      if(node->rightChild == nullptr){
        if(node->parent->rightChild == node){
          node->parent->rightChild = node->leftChild;
          delete node;
        }
        else{
          node->parent->leftChild = node->leftChild;
          delete node;
        }
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

  
  btu.remove(root, 1); // unfinished
  
  delete root;
  fin.close();
  fout.close();

  return 0;
}