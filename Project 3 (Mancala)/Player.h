//
//  player.h
//  project 3 cs 32
//
//  Created by kelly tran on 5/23/23.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <chrono> // For measuring time
#include <limits> // For defining initial values of alpha and beta
#include "Board.h"
#include "Side.h"
using namespace std;
class Player {
public:
    Player(string name);
    string name() const;
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const = 0;
    virtual ~Player();
private:
    string m_name;
};
class HumanPlayer : public Player {
public:
    HumanPlayer(string name);
    bool isInteractive() const;
    int chooseMove(const Board& b, Side s) const;
};
class BadPlayer : public Player {
public:
    BadPlayer(string name);
    int chooseMove(const Board& b, Side s) const override;
};
class SmartPlayer : public Player {
public:
    SmartPlayer(string name);
    bool isInteractive() const;
    int chooseMove(const Board& b, Side s) const;
private:
    int evaluate(const Board& b, Side s) const;
    int minimax(const Board& b, Side s, int depth, int alpha, int beta, bool maximizingPlayer) const;
};
#endif // PLAYER_H

