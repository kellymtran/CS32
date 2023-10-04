////
////  newSequence.cpp
////  CS 32 proj2
////
////  Created by kelly tran on 4/18/23.
////
//
//#include <stdio.h>
//
//#include "newSequence.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//Sequence::Sequence() {
//
//    m_size = 0;
//    itemset = new ItemType[DEFAULT_MAX_ITEMS];
//    max_array = DEFAULT_MAX_ITEMS;
//}
//
//Sequence::Sequence(int size) {
//    if (size < 0)
//    {
//        exit(1);
//    }
//    itemset = new ItemType[size];
//    max_array = size;
//    m_size = 0;
//}
//
//Sequence::Sequence(const Sequence& other) {
//    m_size = other.size();
//    max_array = other.max_array;
//    itemset = new ItemType[other.max_array];
//
//    for (int i = 0; i < other.size(); i++)
//    {
//        itemset[i] = other.itemset[i];
//    }
//}
//
//Sequence::~Sequence() {
//    delete[] itemset;
//}
//
//Sequence& Sequence::operator=(const Sequence& erf) {
//    if (this != &erf)
//    {
//        Sequence temp(erf);
//        swap(temp);
//    }
//    return *this;
//}
//
//int Sequence::size() const {
//    return m_size;
//}
//
//bool Sequence::empty() const {
//    if (m_size == 0) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//
//int Sequence::insert(int pos, const ItemType& value) {
//    if (pos < 0 || pos > size() || (pos == size() && m_size == max_array)) {
//        return -1;
//    }
//
//    if (m_size == max_array) {
//        m_arr[m_size] = value;
//    }
//    
//    for (int i = m_size; i > pos; i--) {
//            itemset[i] = itemset[i - 1];
//        }
//        itemset[pos] = value;
//    
//    m_size++;
//    return pos;
//}
//
//int Sequence::insert(const ItemType& value) {
//    int pos = 0;
//    while (pos < m_size && itemset[pos] < value)
//    {
//        pos++;
//    }
//    if (m_size == max_array)
//    {
//        return -1;
//    }
//    for (int i = m_size; i > pos; i--)
//    {
//        itemset[i] = itemset[i - 1];
//    }
//    itemset[pos] = value;
//    m_size++;
//    return pos;
//}
//
//bool Sequence::erase(int pos) {
//    if (pos > m_size || pos < 0) {
//        return false;
//    }
//
//    if (pos == m_size - 1) {
//        m_size--;
//        return true;
//    }
//    else {
//        for (int i = pos; i < m_size - 1; i++) {
//            m_arr[i] = m_arr[i + 1];
//        }
//        m_size--;
//    }
//    return true;
//}
//
//int Sequence::remove(const ItemType& value) {
//    int count = 0;
//    for (int i = 0; i < m_size; i++) {
//        if (m_arr[i] == value) {
//            count++;
//
//            for (int j = i; j < m_size - 1; j++) {
//                m_arr[j] = m_arr[j + 1];
//            }
//            m_size--;
//        }
//    }
//    return count;
//}
//
//bool Sequence::get(int pos, ItemType& value) const {
//    if (pos > m_size || pos < 0) {
//        return false;
//    }
//
//    value = m_arr[pos];
//    return true;
//}
//
//bool Sequence::set(int pos, const ItemType& value) {
//    if (pos > m_size || pos < 0) {
//        return false;
//    }
//
//    m_arr[pos] = value;
//    return true;
//}
//
//int Sequence::find(const ItemType& value) const {
//    for (int i = 0; i < m_size; i++) {
//        if (m_arr[i] == value) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//void Sequence::swap(Sequence& other) {
//    int temp_size = other.m_size;
//    other.m_size = m_size;
//    m_size = temp_size;
//
//    int temp_max_array = other.max_array;
//    other.max_array = max_array;
//    max_array = temp_max_array;
//
//    ItemType* temp_itemset = other.itemset;
//    other.itemset = itemset;
//    itemset = temp_itemset;
//}
