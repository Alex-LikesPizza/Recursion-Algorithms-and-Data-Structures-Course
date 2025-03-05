#include <iostream>
#include <map>
using namespace std;
struct Person{
  string name;
  int age;
  Person() = default;
  Person(string name, int age) : name(name), age(age) {};

  bool operator< (const Person& other) const{
    return age < other.age;
  }
};
int main(){
  map<string, Person> population;

  // Inserting/Creating new key-value pair
  auto m = make_pair("Mapple", Person{"Maple", 14});
  population.insert(m);
  population.insert({"Jack", Person{"Jack", 24}});
  population["Jimmy"] = {"Jimmy", 29};

  for(const auto& [key, person] : population){
    cout << person.name << " " << person.age << endl; // returns in order of name
  }

  // Accessing
  const Person& person = population.at("Jimmy"); // creates a reference to "Jimmy" | with bounds check
  const auto& [name, age] = population["Alex"]; // binds population values by order of declaration | if "Alex" does not exist, creates it and returns a reference" 
  
  // Checking if map has element
  if(population.find("Jack") != population.end()) population.at("Jack"); // safe access with at

  // Delete element from map
  population.erase("Jack");


  // Custom ordering map
    // Valid key - must have operator< overloaded
    map<Person, bool> isOld; isOld.insert({{"Marry", 68}, true}); // sorted by age

    // Use predicates
    map<string, int, greater<string>> reverse;
    reverse["Bob"] = 90;
    reverse["Anne"] = 45;
    reverse["Zed"] = 60;

    cout << endl << "Reverse order: " << endl;

    for(const auto& [name, age] : reverse){
      cout << name  << " " << age << endl; // ordered from greatest by name
    }
    // Use lambda functions
    auto compare = [](const int& left, const int& right){
      return left > right;
    };
    map<int, string, decltype(compare)> customAge(compare);
    customAge.insert({10, "George"});
    customAge.insert({25, "Amy"});
    customAge.insert({34, "Cooper"});
    customAge.insert({9, "Steve"});
    customAge.insert({18, "Chis"});
    
    cout << endl << "Custom order: " << endl;
    for(const auto& [age, name] : customAge){
      cout << name  << " " << age << endl; // ordered from greatest by name
    }
  return 0; 

  // Functions:

  // m.insert({key, value});       // Inserts a key-value pair if the key is not already present O(log n)
  // m.erase(key);                 // Removes the key-value pair associated with 'key' O(log n)
  // m.erase(iter);                // Removes the element at the iterator's position O(1)
  // m.clear();                    // Clears all elements from the map O(n)
  // m.find(key);                  // Returns iterator to the key-value pair or m.end() if not found O(log n)
  // m.count(key);                 // Returns 1 if the key exists, otherwise 0 O(log n)
  // m.contains(key);              // (C++20) Returns true if the key exists O(log n)
  // m.begin();                    // Returns an iterator to the first element O(1)
  // m.end();                      // Returns an iterator to the last element O(1)
  // m.lower_bound(key);           // Returns iterator to the first element >= key O(log n)
  // m.upper_bound(key);           // Returns iterator to the first element > key O(log n)
  // m.equal_range(key);           // Returns {lower_bound, upper_bound} O(log n)

}