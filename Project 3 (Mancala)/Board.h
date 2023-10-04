//
//  board.h
//  project 3 cs 32
//
//  Created by kelly tran on 5/23/23.
//

#ifndef BOARD_H
#define BOARD_H
#include "Side.h"
#include <vector>
using namespace std;

class Board {
public:
    Board(const Board& other); // copy constructor
    
    Board(int nHoles, int nInitialBeansPerHole);
    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side& endSide, int& endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);
private:
    int m_nHoles;
    int m_nInitialBeansPerHole;
    vector<vector<int>> m_board;
};
#endif // BOARD_H

