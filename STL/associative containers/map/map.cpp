#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
  map<string, int> intMap {
    {"Alex", 17},
    {"Luca", 9},
    {"Aiu", 12}
  };
  map<string, string> stringMap{
    {"Alex", "Programming"},
    {"Luca", "Youtube"},
    {"Aiu", "Gamming"}
  };

  intMap.size(); // 3
  intMap.insert(make_pair("Ivan", 18));

  stringMap["Ana"] = "Working";
  stringMap.at("Luca") = "Tiktok";

  auto it = stringMap.find("Ana");
  if(it != stringMap.end())
    stringMap.erase(it);
  int n = intMap.count("Alex");
  
  // multimap (allows duplicates)
  // unordered_map 
  // unordered_multimap

  return 0;
}