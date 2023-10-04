////
////  testnewSequence.cpp
////  CS 32 proj2
////
////  Created by kelly tran on 4/18/23.
////
//
//#include <stdio.h>
//
//#include "newSequence.h"
//#include <iostream>
//#include <cassert>
//#include <string>
//using namespace std;
//
//int main()
//{
//    Sequence a(1000);   // a can hold at most 1000 items
//    Sequence b(5);      // b can hold at most 5 items
//    Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
//    ItemType v = 'Hi';
//
//    // No failures inserting 5 items into b
//    for (int k = 0; k < 5; k++)
//        assert(b.insert(v) != -1);
//
//    // Failure if we try to insert a sixth item into b
//    assert(b.insert(v) == -1);
//
//    // When two Sequences' contents are swapped, their capacities are
//    // swapped as well:
//    a.swap(b);
//    assert(a.insert(v) == -1 && b.insert(v) != -1);
//    cout << "nice" << endl;
//}
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started:
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
