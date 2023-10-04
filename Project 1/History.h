//
//  History.h
//  CS32 p1
//
//  Created by kelly tran on 4/12/23.
//

#ifndef History_h
#define History_h

#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
private:
    int m_rows;
    int m_cols; 
    char m_grid[MAXROWS][MAXCOLS];
};


#endif /* History_h */
