#include <iostream>
#include <string>

using namespace std;

class Player{
  private:
  int xp {0};

  public:
  string name;
  int health {100};

  void addXp(int amount){
    xp += amount;
  }
  void showXp(){
    cout << "Current XP: " << xp << endl;
  }

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

int main(){
  Player player {"Kevin", 100, 980};

  player.name = "Josh";
  // player.xp += 20; // Error
  player.addXp(20);
  player.displayStatus();


  Player hero {"Hero"};
  cout << "Creating impostor" << endl;
  Player impostor {hero};

  impostor.displayStatus();
}