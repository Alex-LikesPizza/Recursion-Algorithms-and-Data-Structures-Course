#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
  int age;
  string name;

  Person() : age(0), name("") {}
  Person(int age, string name) : age(age), name(name){};
};

vector<Person> counting_sort(vector<Person> arr){
  vector<int> count_arr;
  for(Person p : arr){
    if(p.age >= count_arr.size()) count_arr.resize(p.age * 2);
    count_arr.at(p.age)++;
  }
  vector<int> end_arr(count_arr.size()); int acc {};
  for(int i = 0; i < count_arr.size(); i++){
    acc+= count_arr.at(i);
    end_arr.at(i) = acc;
  }
  vector<int> start_arr = {0}; start_arr.insert(start_arr.end(), end_arr.begin(), end_arr.end() - 1);

  
  vector<Person> sorted_arr(arr.size());
  for(Person p : arr){
    int& index = start_arr.at(p.age);
    sorted_arr.at(index) = p;
    index++;
  }

  return sorted_arr;
}

int main(){

  ifstream fin("file.in");
  
  vector<Person> arr;

  int t; string name;
  while (fin >> name >> t) {
    arr.emplace_back(t, name);
  }

  arr = counting_sort(arr);

  for(Person p : arr) cout << p.name << " " << p.age << endl;

  fin.close();

  return 0;
}