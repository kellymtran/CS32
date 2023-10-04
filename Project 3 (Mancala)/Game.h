//
//  game.h
//  project 3 cs 32
//
//  Created by kelly tran on 5/23/23.
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
class Game {
public:
    Game(const Board& b, Player* south, Player* north);
    void display() const;
    void status(bool& over, bool& hasWinner, Side& winner) const;
    bool move(Side s);
    void play();
    int beans(Side s, int hole) const;
private:
    Board m_board;
    Player* m_southPlayer;
    Player* m_northPlayer;
    Side m_currentPlayer;
    void promptToContinue() const;
};
#endif // GAME_H

