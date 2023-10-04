//
//  testSequence.cpp
//  CS 32 proj2
//
//  Created by kelly tran on 4/18/23.
//
//
#include <stdio.h>

#include "Sequence.h"

#include <string>

#include <iostream>

#include <cassert>

using namespace std;



int main()

{

    Sequence s;
    ItemType x;

    s.insert(0, <#const ItemType &value#>)
    s.insert(0, "lavash");

    s.insert(0, "tortilla");

    assert(s.size() == 2);

    ItemType x = "injera";

    assert(s.get(0, x) && x == "tortilla");

    assert(s.get(1, x) && x == "lavash");

    assert(s.insert("Pain") == 0);

    assert(s.get(0, x) && x == "Pain");

    assert(s.get(1, x) && x == "tortilla");

    assert(s.insert(0, "Help") == 0);

    assert(s.get(0, x) && x == "Help");

    assert(s.get(1, x) && x == "Pain");

    assert(s.erase(0) == 1);

    assert(s.get(0, x) && x == "Pain");

    assert(s.insert(0, "Pain") == 0);

    assert(s.insert(5, "wrong") == -1);

    assert(s.get(0, x) && x == "Pain");

    assert(s.get(1, x) && x == "Pain");

    assert(s.get(2, x) && x == "tortilla");

    assert(s.size() == 4);

    assert(s.remove("Pain") == 2);

    assert(s.get(0, x) && x == "tortilla");

    assert(s.set(0, "Pain again") == 1);

    assert(s.get(0, x) && x == "Pain again");


    cout << "Passed all tests" << endl;

}
