//---------------------------------------------------------------------------
// File: SortedListInterface.h
// Author: Snehal Jogdand
// Date: 10/23/2019
// Program 2: Merge Sorted List
//
// DESCRIPTION:
// SortedList: 
//  The header file for SortedList class
//  Provides the set of variables and functions to process a sorted list
//---------------------------------------------------------------------------

#ifndef SORTED_LIST_
#define SORTED_LIST_

#include "Node.h"
#include "SortedListInterface.h"

//---------------------------------------------------------------------------
// SortedList: 
//  The header file for SortedList class
//  Provides the set of variables and functions to process a sorted list
//---------------------------------------------------------------------------
class SortedList : public SortedListInterface<int>
{
private:
   Node* headPtr; // Pointer to first node in chain
   int itemCount; // Current count of bag items

   /** Gets the previous node of the entry element. */
   Node* getNodeBefore(const int& anEntry) const;

   /** Gets the pointer to the node of the entry element. */
   Node* getPointerTo(const int& target) const;

public:

   /** constructor */
   SortedList();

   /** copy constructor */
   SortedList(const SortedList& other);

   /** destructor */
   virtual ~SortedList();

   /** Inserts an entry into this sorted list in its proper order */
   bool insertSorted(const int& newEntry);

   /** Removes the first or only occurrence of the given entry */
   bool removeSorted(const int& anEntry);

   /** Merges the two sorted list and returns the newly formed sorted list */
   SortedList merge(const SortedList& other) const;

   /** Prints the current list to console */
   void print();

   /** Gets the position of the first or only occurrence of the given
    entry in this sorted list */
   int getPosition(const int& newEntry) const;

   /** Sees whether this list is empty. */
   bool isEmpty() const;

   /** Gets the current number of entries in this list. */
   int getLength() const;

   /** Removes the entry at a given position from this list. */
   bool remove(int position);

   /** Removes all entries from this list. */
   void clear();

   /** Gets the entry at the given position in this list. */
   int getEntry(int position) const;
}; // end SortedList
#endif