#ifndef _GAME_H_ // this or #pragma once
#define _ACCOUNT_H_ 

class Game{
  private:
    bool finished = false;
  public:
    int score = 0;
    int time = 0;

    void inlineDef(){
      score += 1;
    }
    bool is_finished();
    void displayStatus();
};

#endif