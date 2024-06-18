#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Player{
  private: // cannot be accessed outside this object
  int xp {0};

  public: // can be accessed outside this object

  string name;
  int health {100};

  void addXp(int amount){xp += amount;}
  void showXp(){cout << "Current XP: " << xp << endl;}
  void displayStatus(){
  cout << "Player Name: " << name << endl;
  cout << "Player Health: " << health << endl;
  this->showXp();
  cout << endl;
  }
  
  // Player(); // empty constructor
  // Player(string playerName){name = playerName;}; // overload
  // Player(string playerName, int playerHealth, int playerXp){ // overload 
  //   name = playerName;
  //   health = playerHealth;
  //   xp = playerXp;
  // };

  Player(string name, int health, int xp) // overload, same as before but with constructor initialization list
   : name{name}, health{health}, xp{xp}{ 
    cout << "Constructor called for " << name << endl;
   }; 

  Player(string name) : Player{name, 100, 0}{}; // delegating constructor
  Player() : Player{"none", 100, 0}{}; // delegating constructor

  Player(const Player& source) : name{source.name}, health{source.health}, xp{source.xp}{ // copy constructor
    cout << "Copy constructor called for " << source.name << endl;
  }

  ~Player(){}; // destructor: called when object is deleted
};

class Move{  
  private:
    int* data;

  public:
    void logData(){cout << *data << endl;}

    Move(int value){
      data = new int(value);
      cout << "Creating data" << endl;
    }
    Move(Move&& source) noexcept { // move constructor
      data = new int(*source.data);
      source.data = nullptr;
      cout << "Moving data" << endl;
    }
    ~Move() {
      delete data;
      cout << "Deleting data" << endl;
    }
};

class ConstObject{
  private:
    int *data;

  public:
    int getData() { return *data;} // wont work if object is constant. Needs "const" type qualifier
    void printData() const {cout << *data << endl;} // enables const accessibility
    // void setData(int data) const { this->data = &data;} // Error: trying to modify data in a const member function 

    ConstObject(int data) : data{new int(data)}{}
};
class StaticObject{
  friend void display_object_num();
  
  private:
    static int objectNum;
    static vector<int> objectIDs;
    int id;
  public:
    static void display_object_num(){
      cout << "Current object num: ";
      cout << objectNum << endl;
    }
    static void display_object_ids() {
      cout << "Current object IDs: ";
      for (int id : objectIDs) {
        cout << id << " ";
      }
      cout << endl;
    }
    static void add_object(int id){
      objectNum++;
      objectIDs.push_back(id);
    }

    StaticObject(int id) : id{id}{
      add_object(id);
    };
    
    ~StaticObject(){
      objectNum--;
      auto index = find(objectIDs.begin(), objectIDs.end(), id);
      objectIDs.erase(index);
    }

};

void display_object_num(){
  cout << "Current object num: ";
  cout << StaticObject::objectNum << endl;
}

int StaticObject::objectNum {0};
vector<int> StaticObject::objectIDs;


int main(){
  // // Creating and accessing object
  // Player player {"Kevin", 100, 980};
  // player.name = "Josh";
  // // player.xp += 20; // Error
  // player.addXp(20);
  // player.displayStatus();

  // // Copy constructor
  // Player hero {"Hero"};
  // cout << "Creating impostor" << endl;
  // Player impostor {hero};
  // impostor.displayStatus();

  // // Move constructor
  // vector<Move> moveVec;
  // moveVec.push_back(Move{10});
  // moveVec.push_back(Move{20});

  // // "const" with objects
  // const ConstObject object = ConstObject(2);
  // object.printData(); // ok
  // // object.getData(); // Error: needs "const" type qualifier

  // // Static variables
  // StaticObject::display_object_num(); // 0
  // StaticObject obj1 {StaticObject(1)};
  // StaticObject obj2 {StaticObject(2)};
  // StaticObject obj3 {StaticObject(3)};
  // StaticObject::display_object_num(); // 3
  // {
  //   StaticObject obj4 {StaticObject(4)};
  //   StaticObject::display_object_num(); // 4
  // }
  // StaticObject obj5 {StaticObject(5)};
  // StaticObject obj6 {StaticObject(6)};
  // StaticObject::display_object_num(); // 5
  // StaticObject::display_object_ids(); // 1 2 3 5 6

  // friend of a class
  // cout << StaticObject::objectNum << endl; // Error: Inaccessible (private)
  display_object_num(); // function is friend of class. Can access private members 


}