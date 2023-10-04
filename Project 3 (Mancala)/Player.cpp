//
//  player.cpp
//  project 3 cs 32
//
//  Created by kelly tran on 5/23/23.
//

#include "Player.h"
#include <chrono>
#include <limits> // For defining initial values of alpha and beta
#include <string>
#include <iostream>
using namespace std;

// Player member function implementations
Player::Player(string name) : m_name(name) {
}

string Player::name() const {
    return m_name;
}

bool Player::isInteractive() const {
    return false; // By default, players are computer players
}

Player::~Player() {
}

// HumanPlayer member function implementations
HumanPlayer::HumanPlayer(string name) : Player(name) {
    
}

bool HumanPlayer::isInteractive() const {
    return true; // HumanPlayer is interactive
}

int HumanPlayer::chooseMove(const Board& b, Side s) const {
    int move;
    
    cout << "Enter your move, " << name() << ": ";
    cin >> move;
    // Validate the move
    while (move < 1 || move > b.holes() || b.beans(s, move) == 0) {
        cout << "Invalid move. Please enter a valid hole number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> move;
    }
    return move;
}

// BadPlayer member function implementations
BadPlayer::BadPlayer(string name) : Player(name) {
    
}

int BadPlayer::chooseMove(const Board& b, Side s) const {
    
    cout << "Loading..." << endl;
    cin.ignore();
    for (int hole = 1; hole <= b.holes(); ++hole) {
        if (b.beans(s, hole) > 0) {
            return hole; // Return the first valid move found
        }
    }
    return -1; // No valid move found
}

// SmartPlayer member function implementations
SmartPlayer::SmartPlayer(string name) : Player(name) {
    
}

bool SmartPlayer::isInteractive() const {
    return false; // SmartPlayer is not interactive
}

int SmartPlayer::chooseMove(const Board& b, Side s) const {
//        cout << "Loading..." << endl;
//        cin.ignore();
//        //help
    auto startTime = std::chrono::high_resolution_clock::now(); //MAKE SURE IT WORKSSKJDHFS EHFOSUEF HSUKFH
    int depth = 1;
    bool maximizingPlayer = (s == SOUTH);
    int bestHole = -1;
    if (maximizingPlayer){
        int bestValue = std::numeric_limits<int>::min();
        for (int hole = 1; hole <= b.holes(); ++hole) {
            if (b.beans(s, hole) > 0) {
                Board bCopy = b;
                Side endSide;
                int endHole;
                if (bCopy.sow(s, hole, endSide, endHole)){
                    if (endHole == POT) {
                        // endhole = 0 implies endhole is on the same side as the player
                        if (bCopy.beansInPlay(s) > 0) {
                            int extraHole = chooseMove(bCopy, s); // player gets another turn
                            bCopy.sow(s, extraHole, endSide, endHole); // player gets another turn
                        }
                        else {
                            // sweeping remaining beans into respective player's pot
                            for (int i = 1; i <= bCopy.holes(); i++) { //loop through the south holes
                                bCopy.moveToPot(s, i, s);
                            }
                        }
                    }
                    else if (endSide == s && bCopy.beans(endSide, endHole) == 1 && bCopy.beans(opponent(s), endHole) > 0) {
                        // Capture beans in the empty hole and the opponent's hole
                        bCopy.moveToPot(s, endHole, s);
                        bCopy.moveToPot(opponent(s), endHole, s);
                    }
                }
                int value = minimax(bCopy, opponent(s), depth, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false);
                if (value > bestValue){
                    bestValue = value;
                    bestHole = hole;
                }
            }
        }
    }
    else{
        int bestValue = std::numeric_limits<int>::max();
        for (int hole = 1; hole <= b.holes(); ++hole) {
            if (b.beans(s, hole) > 0) {
                Board bCopy = b;
                Side endSide;
                int endHole;
                if (bCopy.sow(s, hole, endSide, endHole)){
                    if (endHole == POT) {
                        // endhole = 0 implies endhole is on the same side as the player
                        if (bCopy.beansInPlay(s) > 0) {
                            int extraHole = chooseMove(bCopy, s); // player gets another turn
                            bCopy.sow(s, extraHole, endSide, endHole); // use recursive later for multiple additional turns
                        }
                        else {
                            // sweeping remaining beans into respective player's pot
                            for (int i = 1; i <= bCopy.holes(); i++) { //loop through the south holes
                                bCopy.moveToPot(s, i, s);
                            }
                        }
                    }
                    else if (endSide == s && bCopy.beans(endSide, endHole) == 1 && bCopy.beans(opponent(s), endHole) > 0) {
                        // Capture beans in the empty hole and the opponent's hole
                        bCopy.moveToPot(s, endHole, s);
                        bCopy.moveToPot(opponent(s), endHole, s);
                    }
                }
                int value = minimax(bCopy, opponent(s), depth, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), true);
                if (value < bestValue){
                    bestValue = value;
                    bestHole = hole;
                }
            }
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now(); // Get the current time again
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count(); // Calculate the duration in seconds

    if (duration >= 5) {
        // If the duration exceeds five seconds, return a default move (or handle it as appropriate)
        return -1; // Or any other default move value
    }

    return bestHole;
}

int SmartPlayer::evaluate(const Board& b, Side s) const {
    // Calculate the difference between the number of beans in the player's pot
    // and the opponent's pot
    int playerScore = b.beans(s, POT);
    int opponentScore = b.beans(opponent(s), POT);
    int scoreDifference = playerScore - opponentScore;
    // Return the score difference as the evaluation value
    return scoreDifference;
}

int SmartPlayer::minimax(const Board& b, Side s, int depth, int alpha, int beta, bool maximizingPlayer) const {
    if (depth == 0 || b.beansInPlay(NORTH) == 0 || b.beansInPlay(SOUTH) == 0) {
        // Reached the maximum depth or a terminal state, evaluate the board position
        return evaluate(b, s);
    }
    
    if (maximizingPlayer){
        int maxEval = numeric_limits<int>::min();
        for (int hole = 1; hole <= b.holes(); ++hole){
            if (b.beans(s, hole) > 0){
                Board bCopy = b;
                Side endSide;
                int endHole;
                int eval;
                if (bCopy.sow(s, hole, endSide, endHole)){
                    if (endHole == POT) {
                        //note that sow will always skip the opponent's pot so endhole = 0 implies endhole is on the same side as the player
                        if (bCopy.beansInPlay(s) > 0) {
                            eval = minimax(bCopy, s, depth, alpha, beta, true);//player gets another turn
                        }
                        else {
                            // sweeping remaining beans into respective player's pot
                            for (int i = 1; i <= bCopy.holes(); i++) { //loop through the south holes
                                bCopy.moveToPot(s, i, s);
                            }
                            eval = evaluate(bCopy, s);
                        }
                    }
                    else if (endSide == s && bCopy.beans(endSide, endHole) == 1 && bCopy.beans(opponent(s), endHole) > 0) {
                        // Capture beans in the empty hole and the opponent's hole
                        bCopy.moveToPot(s, endHole, s);
                        bCopy.moveToPot(opponent(s), endHole, s);
                    }
                }
                
                
                eval = minimax(bCopy, s, depth - 1, alpha, beta, false); // is this okay?
                maxEval = max(maxEval, eval);
                alpha = max(alpha, eval);
                if (beta <= alpha){
                    break;
                }
            }
        }
        return maxEval;
        
    }
    else{
        int minEval = numeric_limits<int>::max();
        for (int hole = 1; hole <= b.holes(); ++hole){
            if (b.beans(s, hole) > 0){
                Board bCopy = b;
                Side endSide;
                int endHole;
                int eval;
                if (bCopy.sow(s, hole, endSide, endHole)){
                    if (endHole == POT) {
                        //note that sow will always skip the opponent's pot so endhole = 0 implies endhole is on the same side as the player
                        if (bCopy.beansInPlay(s) > 0) {
                            eval = minimax(bCopy, s, depth, alpha, beta, false);//player gets another turn
                        }
                        else {
                            // sweeping remaining beans into respective player's pot
                            for (int i = 1; i <= bCopy.holes(); i++) { //loop through the south holes
                                bCopy.moveToPot(s, i, s);
                            }
                            eval = evaluate(bCopy, s);
                        }
                    }
                    else if (endSide == s && bCopy.beans(endSide, endHole) == 1 && bCopy.beans(opponent(s), endHole) > 0) {
                        // Capture beans in the empty hole and the opponent's hole
                        bCopy.moveToPot(s, endHole, s);
                        bCopy.moveToPot(opponent(s), endHole, s);
                    }
                }
                eval = minimax(bCopy, s, depth - 1, alpha, beta, true); // is this okay?
                minEval = min(minEval, eval);
                beta = min(beta, eval);
                if (beta <= alpha){
                    break;
                }
            }
        }
        return minEval;
    }
}

