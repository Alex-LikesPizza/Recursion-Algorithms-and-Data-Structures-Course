#include <iostream>
#include "Game.h"
using namespace std;


int main(){
  Game game;
  game.score += 10;
  game.time = 1;
  game.inlineDef();
  game.displayStatus();
}