//
//  board.cpp
//  project 3 cs 32
//
//  Created by kelly tran on 5/23/23.
//

#include "Board.h"
Board::Board(int nHoles, int nInitialBeansPerHole) {
    if (nHoles <= 0)
        m_nHoles = 1;
    else
        m_nHoles = nHoles;
    if (nInitialBeansPerHole < 0)
        m_nInitialBeansPerHole = 0;
    else
        m_nInitialBeansPerHole = nInitialBeansPerHole;
    // Initialize the board
    m_board.resize(NSIDES);
    for (int side = 0; side < NSIDES; ++side) {
        m_board[side].resize(m_nHoles + 1, m_nInitialBeansPerHole);
        m_board[side][POT] = 0;
    }
}

Board::Board(const Board& other){
    m_nHoles = other.m_nHoles;
    m_board.resize(NSIDES);
    for (int side = 0; side < NSIDES; ++side) {
        m_board[side].resize(m_nHoles + 1);
        m_board[side][POT] = other.m_board[side][POT];
        for (int hole = 1; hole <= m_nHoles; ++hole){
            m_board[side][hole] = other.m_board[side][hole];
        }
    }
}

int Board::holes() const {
    return m_nHoles;
}

int Board::beans(Side s, int hole) const {
    if (hole < 0 || hole > m_nHoles)
        return -1;
    return m_board[s][hole];
}

int Board::beansInPlay(Side s) const {

    int beansCount = 0;
    if(s == SOUTH){
        for (int hole = 1; hole <= m_nHoles; ++hole)
                beansCount += m_board[SOUTH][hole];
    }
    if(s == NORTH){
        for (int hole = 1; hole <= m_nHoles; ++hole)
                beansCount += m_board[NORTH][hole];
    }
    return beansCount;
}


int Board::totalBeans() const {
    int totalBeansCount = 0;
    for (int side = 0; side < NSIDES; ++side) {
        for (int hole = 0; hole <= m_nHoles; ++hole)
            totalBeansCount += m_board[side][hole];
    }
    return totalBeansCount;
}

bool Board::sow(Side s, int hole, Side& endSide, int& endHole) {
    if (hole <= 0 || hole > m_nHoles || m_board[s][hole] == 0 || hole == POT)
        return false;

    int beansToSow = m_board[s][hole];
    m_board[s][hole] = 0;
    Side currentSide = s;
    int currentHole = hole;

    while (beansToSow > 0) {
        if (currentSide == NORTH){
            currentHole--;
            if (currentHole == 0) {
                // Switch sides
                // currentSide = opponent(currentSide);
        
                if (currentSide == s) {
                    // Reached s's pot, add a bean and continue
                    m_board[currentSide][POT]++;
                    beansToSow--;
                }
                
                currentSide = opponent(currentSide);
                currentHole = 0;

            }
            else {
                // Place a bean in the current hole
                m_board[currentSide][currentHole]++;
                beansToSow--;
            }
        }
        else if (currentSide == SOUTH){
            currentHole++;
            if (currentHole == m_nHoles + 1) {
                // Switch sides

                if (currentSide == s) {
                    // Reached s's pot, add a bean and continue
                    m_board[currentSide][POT]++;
                    beansToSow--;
                }
                
                currentSide = opponent(currentSide);
                currentHole = m_nHoles + 1;
            }
            else {
                // Place a bean in the current hole
                m_board[currentSide][currentHole]++;
                beansToSow--;
            }
        }
    }
    
    if (currentHole == 0 || currentHole == m_nHoles + 1) { //if currenthole is pot
            currentHole = 0;
    }
    

    endSide = currentSide;
    endHole = currentHole;
    return true;
}


bool Board::moveToPot(Side s, int hole, Side potOwner) {
    if (hole <= 0 || hole > m_nHoles)
        return false;
    
    else {
        m_board[potOwner][POT] += m_board[s][hole];
        m_board[s][hole] = 0;
        return true;
    }
}

bool Board::setBeans(Side s, int hole, int beans) {
    if (hole < 0 || hole > m_nHoles || beans < 0)
        return false;

    // Update the bean count in the indicated hole or pot
    m_board[s][hole] = beans;

    return true;
}

