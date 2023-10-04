//
//  game.cpp
//  project 3 cs 32
//
//  Created by kelly tran on 5/23/23.
//

#include "Game.h"
#include "Board.h"
#include <iomanip>
#include <string>
using namespace std;

Game::Game(const Board& b, Player* south, Player* north)
    : m_board(b), m_southPlayer(south), m_northPlayer(north), m_currentPlayer(SOUTH) {
}

void Game::display() const {
    cout << "Current Board:" << endl;
    // Display North player's side
    cout << "        " << m_northPlayer -> name();
//    for (int hole = 1; hole <= m_board.holes(); ++hole) {
//        cout << setw(3) << hole << " ";
//    }
    cout << endl;
    cout << " " << setw(3) << " ";
    for (int hole = 1; hole <= m_board.holes(); ++hole) {
        cout << setw(3) << m_board.beans(NORTH, hole) << " ";
    }
    //cout << setw(3) << m_board.beans(NORTH, POT) << endl;
    cout << setw(3) << endl << m_board.beans(NORTH, POT);
    // Display the pot
    //cout << setw(3) << m_board.beans(NORTH, POT) << " ";
    for (int hole = 1; hole <= m_board.holes(); ++hole) {
        cout << "    ";
    }
    cout << setw(3) << "    " << m_board.beans(SOUTH, POT) << endl;
    // Display South player's side
    cout << " " << setw(3) << " ";
    for (int hole = 1; hole <= m_board.holes(); ++hole) {
        cout << setw(3) << m_board.beans(SOUTH, hole) << " ";
    }
    //cout << setw(3) << m_board.beans(SOUTH, POT) << endl;
    cout << setw(3) << endl;
    cout << "         " << m_southPlayer -> name();
    cout << endl;
}

void Game::status(bool& over, bool& hasWinner, Side& winner) const {
    if (m_board.beansInPlay(NORTH) != 0 && m_board.beansInPlay(SOUTH) != 0) { // game ongoing
        over = false;
        hasWinner = false;
        return;
    }
    over = true;
    
    if (m_board.beansInPlay(NORTH) == 0 || m_board.beansInPlay(SOUTH) == 0) {
        over = true;
        int northPot = m_board.beans(NORTH, POT);
        int southPot = m_board.beans(SOUTH, POT);
        if (northPot == southPot) {
            hasWinner = false;
        }
        else {
            hasWinner = true;
            if (northPot > southPot) {
                winner = NORTH;
            } else {
                winner = SOUTH;
            }
        }
    }
}

bool Game::move(Side s) {
    int endHole;
    Side endSide;
    display();
    
    if (m_board.beansInPlay(m_currentPlayer) == 0){
        return false;
    }
    
    if (m_currentPlayer == SOUTH) {
        int hole = m_southPlayer->chooseMove(m_board, m_currentPlayer);
        if (!m_southPlayer->isInteractive()) {
            //indicate what moves the computer player makes
            promptToContinue();
            cout << m_southPlayer->name() + " chooses hole " + to_string(hole) << endl;
        }
        
        if (m_board.sow(m_currentPlayer, hole, endSide, endHole)) {
            if (endHole == POT) {
                display();
                if (m_board.beansInPlay(SOUTH) > 0) {
                    cout << m_southPlayer->name() + " go again." << endl;
                    return move(s); //player gets another turn
                }
            }
            else if (endSide == m_currentPlayer && m_board.beans(endSide, endHole) == 1 && m_board.beans(opponent(m_currentPlayer), endHole) > 0) {
                // capture
                m_board.moveToPot(m_currentPlayer, endHole, m_currentPlayer);
                m_board.moveToPot(opponent(m_currentPlayer), endHole, m_currentPlayer);
                display();
            }
        }
    }
    else { //turn = north
        int hole = m_northPlayer->chooseMove(m_board, m_currentPlayer);
        if (!m_northPlayer->isInteractive()) {
            promptToContinue();
            cout << m_northPlayer->name() + " chooses hole " + to_string(hole) << endl;
        }
        
        if (m_board.sow(m_currentPlayer, hole, endSide, endHole)) {
            if (endHole == POT) {
                display();
                if (m_board.beansInPlay(NORTH) > 0) {
                    cout << m_northPlayer->name() + " goes again." << endl;
                    return move(s); //player gets another turn
                }
            }
            else if (endSide == m_currentPlayer && m_board.beans(endSide, endHole) == 1 && m_board.beans(opponent(m_currentPlayer), endHole) > 0) {
                // capture
                m_board.moveToPot(m_currentPlayer, endHole, m_currentPlayer);
                m_board.moveToPot(opponent(m_currentPlayer), endHole, m_currentPlayer);
                display();
            }
        }
    }
    
    if (m_board.beansInPlay(NORTH) == 0) { //game is over
        cout << "Sweeping " + m_southPlayer->name() + "'s beans..." << endl;
        for (int i = 1; i <= m_board.holes(); i++) { //loop through the south holes
            m_board.moveToPot(SOUTH, i, SOUTH);
        }
        return false;
    }
    else if (m_board.beansInPlay(SOUTH) == 0) {
        cout << "Sweeping " + m_northPlayer->name() + "'s beans..." << endl;
        for (int i = 1; i <= m_board.holes(); i++) { //loop through north's holes
            m_board.moveToPot(NORTH, i, NORTH);
        }
        return false;
    }
    m_currentPlayer = opponent(m_currentPlayer);
    return true;
}

void Game::play() {
    
    while (true) {
        //how to call move
        move(m_currentPlayer);
        
        if (m_board.beansInPlay(m_currentPlayer) != 0){
            if (m_currentPlayer == SOUTH) {
                if (m_southPlayer->isInteractive()) {
                    promptToContinue();
                }
//                if (!m_southPlayer->isInteractive()) {
//                    promptToContinue();
//                }
            } else {
                if (m_northPlayer->isInteractive()) {
                    promptToContinue();
                }
//                if (!m_northPlayer->isInteractive()) {
//                    promptToContinue();
//                }
            }
            
        }
        
        if (!move(m_currentPlayer)) {
            // Sweep beans into the opponent's pot if no valid move is available
            for (int i = 1; i <= m_board.holes(); i++) {
                int beans = m_board.beans(m_currentPlayer, i);
                if (beans > 0) {
                    m_board.moveToPot(m_currentPlayer, i, opponent(m_currentPlayer));
                }
            }
            m_currentPlayer = opponent(m_currentPlayer);
            
        }
        
        bool over;
        bool hasWinner;
        Side winner;
        status(over, hasWinner, winner);
        if (over) {
            display();
            if (hasWinner) {
                cout << "WINNER IS " << (winner == SOUTH ? m_southPlayer->name() : m_northPlayer->name()) << " RAHHHHHHH" << endl;
            } else {
                cout << "draw :(" << endl;
            }
            break;
        }
    }
}

int Game::beans(Side s, int hole) const {
    return m_board.beans(s, hole);
}
void Game::promptToContinue() const {
    cout << "This is for suspense. Press Enter." << endl;
    cin.ignore(1000000, '\n'); // Wait for user to press ENTER
}
