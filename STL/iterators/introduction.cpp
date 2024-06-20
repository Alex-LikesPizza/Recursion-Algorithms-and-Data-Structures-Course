#include <iostream>
#include <vector>


int main(){
  std::vector<int> vec {1, 2, 3, 4, 5}; 
  // --------------- Iterator intro ----------------//
  // std::cout << "First(1): " << *(vec.begin()) << std::endl;
  // std::cout << "Last(5): " << *(vec.end() - 1) << std::endl;
  // std::cout << "Last+1(garbage): " << *(vec.end()) << std::endl;
  // Iterators act a lot like pointers, although they are not pointers themselves
  

  // --------------- Iterator types ------------------- //
  // vec.begin(); vec.end(); // iterator
  // vec.cbegin(); vec.cend(); // const_iterator
  // vec.rbegin(); vec.rend(); // reverse_iterator
  // vec.crbegin(); vec.crend(); // const_reverse_iterator

  // ------------------ Iterator initialisation ---------------- //
  // std::vector<int>::iterator it = vec.begin();
  // std::vector<int>::reverse_iterator r_it = vec.rbegin();
  // std::vector<int>::const_iterator c_it = vec.cbegin();
  // std::vector<int>::const_reverse_iterator c_r_it = vec.crbegin();
  // auto it_end = vec.end(); // using auto for better readability
  // auto it_end2 = std::end(vec); // alternative to vec.end()
  // auto it_end2 = std::crend(vec); // alternative to vec.crend()
  // ------------------- Iterator operations --------------------- //
  // auto it1 = vec.begin();
  // auto it2 = vec.end();

  // *it1; // dereferencing; Returns the "pointed-to" value
  // it1 + 1; // add; Returns a pointer to one element after itself
  // it1 - 1; // sub; Returns a pointer to one element before itself
  // it1++; // pre/post increment; 
  // it1--; // pre/post decrement; 
  // it1 += 2;
  // it1 -= 2;
  // it1 > it2; it1 < it2; it1 >= it2; it1 <= it2; it1 == it2; // compare; Returns a bool, compares the positional index
  // it->a // arrow operator for objects

  // ---------------- Using Iterators ------------------------- //

  for(auto it = vec.begin(); it < vec.end(); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  for(auto it = vec.rbegin(); it < vec.rend(); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}