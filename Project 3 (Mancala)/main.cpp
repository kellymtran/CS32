//
//  main.cpp
//  project 3 cs 32
//
//  Created by kelly tran on 5/23/23.
//
//
#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Side.h"
int main() {
    Board b(6, 4); // Create a board with 6 holes and 4 initial beans per hole
    // Create players
    HumanPlayer human("Alice");
    BadPlayer bad("Bob");
    SmartPlayer smart("Charlie");
    // Create a game and set the players
    Game game(b, &human, &smart); // Play against the smart player
    // Play the game
    game.play();
    return 0;
}

//
//#include "Board.h"
//    #include "Side.h"
//    #include <iostream>
//    #include <cassert>
//    using namespace std;
//
//    void doBoardTests()
//    {
//        Board b(3, 2);
//        assert(b.holes() == 3  &&  b.totalBeans() == 12  &&
//                        b.beans(SOUTH, POT) == 0  &&  b.beansInPlay(SOUTH) == 6);
//        b.setBeans(SOUTH, 1, 1);
//        b.moveToPot(SOUTH, 2, SOUTH);
//        assert(b.totalBeans() == 11  &&  b.beans(SOUTH, 1) == 1  &&
//                    b.beans(SOUTH, 2) == 0  &&  b.beans(SOUTH, POT) == 2  &&
//            b.beansInPlay(SOUTH) == 3);
//        Side es;
//        int eh;
//        b.sow(SOUTH, 3, es, eh);
//        assert(es == NORTH  &&  eh == 3  &&  b.beans(SOUTH, 3) == 0  &&
//                    b.beans(NORTH, 3) == 3  &&  b.beans(SOUTH, POT) == 3  &&
//            b.beansInPlay(SOUTH) == 1  &&  b.beansInPlay(NORTH) == 7);
//    }
//
//    int main()
//    {
//        doBoardTests();
//        cout << "Passed all tests" << endl;
//    }
//
//
//#include "Player.h"
//    #include "Board.h"
//    #include "Side.h"
//    #include <iostream>
//    #include <cassert>
//    using namespace std;
//
//    void doPlayerTests()
//    {
//        HumanPlayer hp("Marge");
//        assert(hp.name() == "Marge"  &&  hp.isInteractive());
//        BadPlayer bp("Homer");
//        assert(bp.name() == "Homer"  &&  !bp.isInteractive());
//        SmartPlayer sp("Lisa");
//        assert(sp.name() == "Lisa"  &&  !sp.isInteractive());
//        Board b(3, 2);
//        b.setBeans(SOUTH, 2, 0);
//        cout << "=========" << endl;
//        int n = hp.chooseMove(b, SOUTH);
//        cout << "=========" << endl;
//        assert(n == 1  ||  n == 3);
//        n = bp.chooseMove(b, SOUTH);
//        assert(n == 1  ||  n == 3);
//        n = sp.chooseMove(b, SOUTH);
//        assert(n == 1  ||  n == 3);
//    }
//
//    int main()
//    {
//        doPlayerTests();
//        cout << "Passed all tests" << endl;
//    }
//
//
//#include "Game.h"
//    #include "Player.h"
//    #include "Board.h"
//    #include "Side.h"
//    #include <iostream>
//    #include <cassert>
//    using namespace std;
//
//    void doGameTests()
//    {
//        BadPlayer bp1("Bart");
//        BadPlayer bp2("Homer");
//        Board b(3, 0);
//        b.setBeans(SOUTH, 1, 2);
//        b.setBeans(NORTH, 2, 1);
//        b.setBeans(NORTH, 3, 2);
//        Game g(b, &bp1, &bp2);
//        bool over;
//        bool hasWinner;
//        Side winner;
//          //    Homer
//          //   0  1  2
//          // 0         0
//          //   2  0  0
//          //    Bart
//        g.status(over, hasWinner, winner);
//        assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
//        g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 2 &&
//        g.beans(SOUTH, 1) == 2 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//
//        g.move(SOUTH);
//          //   0  1  0
//          // 0         3
//          //   0  1  0
//        g.status(over, hasWinner, winner);
//        assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//        g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 0 &&
//        g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
//
//        g.move(NORTH);
//          //   1  0  0
//          // 0         3
//          //   0  1  0
//        g.status(over, hasWinner, winner);
//        assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//        g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//        g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
//
//        g.move(SOUTH);
//          //   1  0  0
//          // 0         3
//          //   0  0  1
//        g.status(over, hasWinner, winner);
//        assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//        g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//        g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 1);
//
//        g.move(NORTH);
//          //   0  0  0
//          // 1         4
//          //   0  0  0
//        g.status(over, hasWinner, winner);
//        assert(over && g.beans(NORTH, POT) == 1 && g.beans(SOUTH, POT) == 4 &&
//        g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//        g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//        assert(hasWinner && winner == SOUTH);
//    }
//
//    int main()
//    {
//        doGameTests();
//        cout << "Passed all tests" << endl;
//    }
//
//int main()
//    {
//        HumanPlayer hp("Marge");
//        SmartPlayer bp("Homer");
//        Board b(3, 2);
//        Game g(b, &hp, &bp);
//        g.play();
//    }

//#include <cassert>
//#include <iostream>
//#include <string>
//
//#include "Player.h"
//#include "Board.h"
//
//void testSmartPlayer() {
//    // Test Case 1: Empty Board
//    {
//        Board board(0, 0);
//        SmartPlayer player("Alice");
//        int move = player.chooseMove(board, SOUTH);
//        assert(move == -1);
//    }
//
//    // Test Case 2: Single Move to Pot
//    {
//        Board board(0, 0);
//        board.setBeans(SOUTH, 1, 1);
//        SmartPlayer player("Alice");
//        int move = player.chooseMove(board, SOUTH);
//        assert(move == 1);
//    }
//
//    // Test Case 3: Multiple Moves with Capturing
//    {
//        Board board(0, 0);
//        board.setBeans(SOUTH, 1, 4);
//        board.setBeans(SOUTH, 3, 6);
//        board.setBeans(SOUTH, 6, 3);
//        board.setBeans(NORTH, 3, 3);
//        board.setBeans(NORTH, 4, 1);
//        board.setBeans(NORTH, 6, 1);
//        SmartPlayer player("Alice");
//        int move = player.chooseMove(board, SOUTH);
//        assert(move == 1 || move == 2 || move == 4);
//    }
//
//    // Test Case 4: Multiple Moves with Extra Turn
//    {
//        Board board(0, 0);
//        board.setBeans(SOUTH, 1, 4);
//        board.setBeans(SOUTH, 6, 3);
//        board.setBeans(NORTH, 3, 3);
//        board.setBeans(NORTH, 4, 1);
//        board.setBeans(NORTH, 6, 1);
//        SmartPlayer player("Alice");
//        int move = player.chooseMove(board, SOUTH);
//        assert(move == 1 || move == 2 || move == 3 || move == 5);
//    }
//
//    // Test Case 5: Maximum Depth Reached
//    {
//        Board board(0, 0);
//        board.setBeans(SOUTH, 1, 4);
//        board.setBeans(SOUTH, 3, 6);
//        board.setBeans(SOUTH, 6, 3);
//        board.setBeans(NORTH, 3, 3);
//        board.setBeans(NORTH, 4, 1);
//        board.setBeans(NORTH, 6, 1);
//        SmartPlayer player("Alice");
//        int move = player.chooseMove(board, SOUTH);
//        // You may need to update the expected move based on the evaluation score
//        assert(move >= 1 && move <= 6);
//    }
//}
//
//int main() {
//    testSmartPlayer();
//    std::cout << "All test cases passed!\n";
//    return 0;
//}
//
//
//#include <cassert>
//#include <chrono>
//#include "Player.h"
//
//void testChooseMoveTime() {
//    // Test case 1: Baseline test
//    {
//        Board board(1, 1);  // 1 hole per side, 1 initial bean per hole
//        SmartPlayer smartPlayer("SmartPlayer");
//
//        auto startTime = std::chrono::steady_clock::now();
//        smartPlayer.chooseMove(board, SOUTH);
//        auto endTime = std::chrono::steady_clock::now();
//
//        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
//        double baselineTime = static_cast<double>(duration) / 1000.0;
//
//        assert(baselineTime <= 5.0);  // Assert that execution time is within 5 seconds
//    }
//
//    // Test case 2: Larger board configuration
//    {
//        Board board(4, 4);  // 4 holes per side, 4 initial beans per hole
//        SmartPlayer smartPlayer("SmartPlayer");
//
//        auto startTime = std::chrono::steady_clock::now();
//        smartPlayer.chooseMove(board, SOUTH);
//        auto endTime = std::chrono::steady_clock::now();
//
//        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
//        double executionTime = static_cast<double>(duration) / 1000.0;
//
//        assert(executionTime <= 5.0);  // Assert that execution time is within 5 seconds
//    }
//
//    // Add more test cases as needed for different scenarios
//
//    std::cout << "All time performance tests passed!" << std::endl;
//}
//
//int main() {
//    testChooseMoveTime();
//
//    return 0;
//}
//
