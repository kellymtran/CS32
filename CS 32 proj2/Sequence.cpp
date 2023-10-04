//
//  Sequence.cpp
//  CS 32 proj2
//
//  Created by kelly tran on 4/18/23.
//

#include "Sequence.h"

#include <stdio.h>
#include <iostream>
using namespace std;

Sequence::Sequence() {
    m_size = 0;
}

int Sequence::size() const {
    return m_size;
}

bool Sequence::empty() const {
    if(m_size == 0) {
        return true;
    } else {
        return false;
    }
}

int Sequence::insert(int pos, const ItemType& value) {
if(pos >= DEFAULT_MAX_ITEMS || pos > m_size || pos < 0 ) {

         return -1;

     }
  
    m_size++;
    ItemType temp[DEFAULT_MAX_ITEMS];
    for(int i = 0; i < m_size; i++){
        if(i == pos){
            temp[i] = value;
   
            break;
            
        } else if (i < pos){
            temp[i] = m_array[i];
        }
    }

    for (int i = pos + 1; i < m_size; i++){
        temp[i] = m_array[i-1];
    }
    for (int i = 0; i < m_size; i++){
        m_array[i] = temp[i];
    }


    
    return pos;

}

int Sequence::insert(const ItemType& value) {
    int pos = 0;
    while (pos < m_size && m_array[pos] < value)
    {
        pos++;
    }
    
    for (int i = m_size; i > pos; i--)
    {
        m_array[i] = m_array[i - 1];
    }
    m_array[pos] = value;
    m_size++;
    
    return pos;
}

bool Sequence::erase(int pos) {
    if (pos >= m_size) {
        return false;
    }

    for(int i = pos; i < m_size; i++) {
        m_array[i] = m_array[i+1];
    }
    m_size--;

    return true;
}

int Sequence::remove(const ItemType& value) {
    int counter = 0;

    for(int i = 0; i < m_size; i++) {
        if (value == m_array[i]) {
            for (int j = i; j < m_size; j++) {
                m_array[j] = m_array[j+1];
            }

            m_size--;
            counter++;
        }
    }

    return counter;
}

bool Sequence::get(int pos, ItemType& value) const {
    if (pos < 0 || pos >= m_size || m_array[pos] == value) {
        return false;
    }

    value = m_array[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (pos < 0 || pos >= m_size) {
        return false;
    }

    m_array[pos] = value;
    return true;

}

int Sequence::find(const ItemType& value) {
    for (int i = 0; i < m_size; i++) {
        if (value == m_array[i]) {
            return i;
        }
    }
    return -1;
}

void Sequence::swap(Sequence& other) {
    
}
