//---------------------------------------------------------------------------
// File: SortedListDriver.cpp
// Author: Snehal Jogdand
// Date: 10/23/2019
// Program 2: Merge Sorted List
//
//---------------------------------------------------------------------------
// DESCRIPTION:
// The program tests the sorted list class by having it build two sorted 
// lists, each composed of 50 elements generated randomly, printing their 
// contents to cout, merging them to create a new sorted list with 100 
// elements, and then printing its contents to cout. 
//---------------------------------------------------------------------------
// MERGE IMPLEMENTATION:
//  The algorithm for merge implementation
//    1. Find the max of first and second header pointer and set as new list head
//    2. Traverse both lists until any one of the list is null
//       2.a. Add the max of the two currently traversed node to the new list
//       2.b. Move to next node only for the list whose node is now added to new list
//    3. Check which list still has remaining nodes 
//       3.a. Add all those nodes to the new list
//---------------------------------------------------------------------------
// ASSUMPTIONS:
//    Input:
//       There is no user input. The list is randomly generated each containing
//       50 random int values each. The valid range of the values are -999 to 999.
//    Exiting Program:
//       Program will exit after printing the merge output.
//    Output:
//       The program will print the two randomly generated sorted list and
//       the merged sorted list each on new line
//
//       Example output for 5 values each in the list: 
//       -10 -2 -2 -2 6
//       -10 -8 -6 -5 3
//       -10 -10 -8 -6 -5 -2 -2 -2 3 6
//---------------------------------------------------------------------------

#include <iostream>
#include "SortedList.h"
#include <random>

using namespace std;

//----------------------------------------------------------------------------
// main
// The main function to execute the SortedList program
int main()
{
   default_random_engine generator;
   uniform_int_distribution<int> uniform(-999, 999);

   SortedList firstList;
   SortedList secondList;

   for (int i = 0; i < 50; i++) firstList.insertSorted(uniform(generator));
   for (int i = 0; i < 50; i++) secondList.insertSorted(uniform(generator));

   firstList.print();
   secondList.print();

   SortedList mergedList = firstList.merge(secondList);
   mergedList.print();
}