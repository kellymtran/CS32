////
////  RainfallList.cpp
////  CS 32 proj2
////
////  Created by kelly tran on 4/18/23.
////
//
////#include "Sequence.h"
//#include "RainfallList.h"
//#include <iostream>
//
//using namespace std;
//
//RainfallList::RainfallList()
//{}
//
//bool RainfallList::add(unsigned long rainfall)
//{
//    if (rainfall >= 0 && rainfall <= 400)
//    {
//        return m_rainfall.insert(m_rainfall.size(), rainfall);
//    }
//    return false;
//}
//// If the rainfall is valid (a value from 0 to 400) and the rainfall list
//// has room for it, add it to the rainfall list and return true.
//// Otherwise, leave the rainfall list unchanged and return false.
//
//bool RainfallList::remove(unsigned long rainfall)
//{
//    return m_rainfall.erase(m_rainfall.find(rainfall));
//
//}
//// Remove one instance of the specified rainfall from the rainfall list.
//// Return true if a rainfall was removed; otherwise false.
//
//int RainfallList::size() const
//{
//    return m_rainfall.size();
//}// Return the number of rainfalls in the list.
//
//unsigned long RainfallList::minimum() const
//{
//    if (size() == 0)
//    {
//        return NO_RAINFALLS;
//    }
//
//    unsigned long min;
//    m_rainfall.get(0, min);
//
//    unsigned long temp;
//    for (int i = 1; i < size(); i++) {
//        m_rainfall.get(i, temp);
//        if (temp < min)
//        {
//            min = temp;
//        }
//    }
//    return min;
//}
//// Return the lowest-valued rainfall in the rainfall list.  If the list is
//// empty, return NO_RAINFALLS.
//
//unsigned long RainfallList::maximum() const
//{
//    if (size() == 0)
//    {
//        return NO_RAINFALLS;
//    }
//
//    unsigned long max;
//    m_rainfall.get(0, max);
//
//    unsigned long temp;
//    for (int i = 1; i < size(); i++) {
//        m_rainfall.get(i, temp);
//        if (temp > max)
//        {
//            max = temp;
//        }
//    }
//    return max;
//}
//// Return the highest-valued rainfall in the rainfall list.  If the list is
//// empty, return NO_RAINFALLS.
