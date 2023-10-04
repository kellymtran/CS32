//
//  Game.h
//  CS32 p1
//
//  Created by kelly tran on 4/12/23.
//

#ifndef Game_h
#define Game_h

#include "globals.h"
#include <string>
#include <iostream>
#include <random>

using namespace std;

class Arena;

class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    string takePlayerTurn();
};

#endif /* Game_h */
