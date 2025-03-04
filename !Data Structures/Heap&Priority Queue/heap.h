#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>

using namespace std;

template <typename T>

class Heap{ // max heap
private:
  vector<T> heap;
  bool is_max_heap = true;

  int left_node(int index) const {return 2*index + 1;}
  int right_node(int index) const {return 2*index + 2;}
  int parent(int index) const {return ceil(index / 2.f) - 1;}
  bool is_valid_index(int index) const {return index >= 0 && index < heap.size();}
  bool compare(T left, T right){
    if(is_max_heap) return left > right;
    else return left < right;
  }

  void heap_up(int index){
    if(index == 0) return;
    if(compare(heap.at(parent(index)), heap.at(index))) return;
    swap(heap.at(index), heap.at(parent(index)));
    heap_up(parent(index));
  }
  void heap_down(int index){
    if(!is_valid_index(index)) return;
    int largest = index;
    int l = left_node(index);
    int r = right_node(index);
    if(is_valid_index(l) && compare(heap.at(l), heap.at(largest))) largest = l;
    if(is_valid_index(r) && compare(heap.at(r), heap.at(largest))) largest = r;
    if(largest != index) {
      swap(heap.at(index), heap.at(largest));
      heap_down(largest);
    }
  }
  void heapify(vector<T> vec){heap = vec; heapify();}
  void heapify(){
    for(int i = parent(heap.size() - 1); i >= 0; i--){
      heap_down(i); 
    }
  }
public:
  Heap() = default;
  Heap(bool is_max_heap) : is_max_heap(is_max_heap){};
  Heap(vector<T> vec, bool is_max_heap = true) : Heap(is_max_heap){
    this->is_max_heap = is_max_heap;
    heapify(vec);
  
  };

  bool empty() const {return heap.size() == 0;}
  int size() const {return heap.size();}
  T top() const {return heap.front();}
  T pop(){
    T topVal = top();
    
    swap(heap.at(0), heap.at(heap.size() - 1));
    heap.pop_back();
    heap_down(0);
    
    return topVal;
  }
  void push(const T value){
    heap.push_back(value);
    heap_up(heap.size() - 1);
  }
};

#endif // HEAP_H