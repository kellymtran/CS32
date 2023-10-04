//
//  History.cpp
//  CS32 p1
//
//  Created by kelly tran on 4/12/23.
//

#include <stdio.h>
#include "History.h"
#include "globals.h"
#include <iostream>

using namespace std;

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
    {
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++)
            {
                m_grid[i][j] = 0;
            }
        }
    }
}

bool History::record(int r, int c){
    if (r <= 0 || r > m_rows || c <= 0 || c > m_cols)
        return false;
    else
    {
        m_grid[r-1][c-1]++;
        return true;
    }
}

void History::display() const {
    clearScreen();
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            cout << m_grid[i-1][j-1];
        }
        cout << endl;
    }
    cout << endl;
}
