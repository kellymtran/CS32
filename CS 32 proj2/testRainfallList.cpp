//
//  testRainfallList.cpp
//  CS 32 proj2
//
//  Created by kelly tran on 4/18/23.
//

#include <stdio.h>

#include <iostream>

#include "RainfallList.h"

#include <cassert>


using namespace std;



int main() {

    RainfallList rain;

    unsigned long rainfall_1 = 160;

    unsigned long rainfall_2 = -1;

    unsigned long rainfall_3 = 471;

    unsigned long rainfall_4 = 20;

    unsigned long rainfall_5 = 20;

    assert(rain.add(rainfall_1) == 1);

    assert(rain.size() == 1);

    assert(rain.add(rainfall_4) == 1);

    assert(rain.size() == 2);

    assert(rain.add(rainfall_2) == 0);

    assert(rain.size() == 2);

    assert(rain.add(rainfall_3) == 0);

    assert(rain.size() == 2);

    assert(rain.maximum() == 160);

    assert(rain.minimum() == 20);

    assert(rain.remove(rainfall_1) == 1);

    assert(rain.size() == 1);

    assert(rain.add(rainfall_1) == 1);

    assert(rain.add(rainfall_5) == 1);

    assert(rain.size() == 3);

    assert(rain.remove(rainfall_5) == 1);

    assert(rain.size() == 2);



    cout << "Passed all tests!" << endl;

}
