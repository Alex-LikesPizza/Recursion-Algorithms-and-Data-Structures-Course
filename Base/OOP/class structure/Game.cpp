#include <iostream>
#include "Game.h"

bool Game::is_finished(){
  return finished;
}

void Game::displayStatus(){
  std::cout << score << std::endl;
  std::cout << time << std::endl;
  std::cout << is_finished() << std::endl;
}