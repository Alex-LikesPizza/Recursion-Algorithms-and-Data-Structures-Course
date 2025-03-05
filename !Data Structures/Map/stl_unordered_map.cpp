#include <iostream>
#include <unordered_map>
using namespace std;
struct Person{
  string name;
  int age;
  Person() = default;
  Person(string name, int age) : name(name), age(age) {};
};
int main(){
  unordered_map<string, Person> population; // the same operations as ordered map

  // Inserting/Creating new key-value pair
  auto m = make_pair("Mapple", Person{"Maple", 14});
  population.insert(m);
  population.insert({"Jack", Person{"Jack", 24}});
  population["Jimmy"] = {"Jimmy", 29};

  for(const auto& [key, person] : population){
    cout << person.name << " " << person.age << endl; // returns "random" order
  }

  // Accessing
  const Person& person = population.at("Jimmy"); // creates a reference to "Jimmy" if exists|const
  const auto& [name, age] = population["Alex"]; // binds population values by order of declaration | if "Alex" does not exist, creates it and returns a reference" 
  
  // Checking if map has element
  if(population.find("Jack") != population.end()) population.at("Jack"); // safe access with at

  // Delete element from map
  population.erase("Jack");

  // Valid keys - key must be hashable
  // unordered_map<Person, int> PersonId; // error. Not hashable
  unordered_map<Person*, int> PersonId;  // valid hashable data
  
  // Functions:

  // um.insert({key, value}); // Inserts a key-value pair if the key is not already present O(1) on average
  // um.erase(key);           // Removes the key-value pair associated with 'key' O(1) on average
  // um.erase(iter);          // Removes the element at the iterator's position O(1)
  // um.clear();              // Clears all elements from the unordered map O(n)
  // um.find(key);            // Returns iterator to key-value pair or um.end() if not found O(1) on average
  // um.count(key);           // Returns 1 if the key exists, otherwise 0 O(1) on average
  // um.contains(key);        // (C++20) Returns true if the key exists O(1) on average
  // um.begin();              // Returns an iterator to the first element O(1)
  // um.end();                // Returns an iterator to the past-the-last element O(1)
  
  return 0; 
}