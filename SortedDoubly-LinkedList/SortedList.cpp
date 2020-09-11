//---------------------------------------------------------------------------
// File: SortedList.cpp
// Author: Snehal Jogdand
// Date: 10/23/2019
// Program 2: Merge Sorted List
//
// DESCRIPTION:
// The program creates a Doubly-Linked List that implements the Carrano and 
// Henry sorted list interface as presented in chapter 12, section 12.1.1. 
//---------------------------------------------------------------------------

#include "SortedList.h"
#include <iostream>

using namespace std;

/** Default constructor for SortedList class. */
SortedList::SortedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

/** The copy constructor for SortedList class
    @pre  None.
    @param other  The new sorted list to copy from */
SortedList::SortedList(const SortedList& other)
{
   itemCount = other.itemCount;
   Node* origChainPtr = other.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr; // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node();
      headPtr->setItem(origChainPtr->getItem());

      // Copy remaining nodes
      Node* newChainPtr = headPtr; // Points to last node in new chain
      origChainPtr = origChainPtr->getNext(); // Advance original-chain pointer

      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         int nextItem = origChainPtr->getItem();

         // Create a new node containing the next item
         Node* newNodePtr = new Node(nextItem);

         // Link new node to end of new chain
         newNodePtr->setPrev(newChainPtr);
         newChainPtr->setNext(newNodePtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while

      newChainPtr->setNext(nullptr); // Flag end of chain
   } // end if
}

/** Gets the previous node of the entry element.
    @pre  None.
    @post  The pointer to the previous node.
    @param anEntry  The entry to locate.
    @return  Either the pointer to the previous node if it exists
    or a null pointer. */
Node* SortedList::getNodeBefore(const int& anEntry) const
{
   Node* curPtr = headPtr;
   Node* prevPtr = nullptr;

   while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
   {
      prevPtr = curPtr;
      curPtr = curPtr->getNext();
   }  // end while

   return prevPtr;
}

/** Gets the pointer to the node of the entry element.
    @pre  None.
    @post  The pointer to the found node.
    @param anEntry  The entry to locate.
    @return  Either the pointer to the node if it exists
    or a null pointer. */
Node* SortedList::getPointerTo(const int& anEntry) const
{
   bool found = false;
   Node* curPtr = headPtr;

   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while

   return curPtr;
}

/** Inserts an entry into this sorted list in its proper order
       so that the list remains sorted.
    @pre  None.
    @post  newEntry is in the list, and the list is sorted.
    @param newEntry  The entry to insert into the sorted list.
    @return  True if insertion is successful, or false if not. */
bool SortedList::insertSorted(const int& newEntry)
{
   Node* newNodePtr = new Node(newEntry);
   Node* prevPtr = getNodeBefore(newEntry);

   if (isEmpty() || (prevPtr == nullptr)) // Add at beginning
   {
      newNodePtr->setNext(headPtr);
      headPtr = newNodePtr;
   }
   else // Add after node before
   {
      Node* aftPtr = prevPtr->getNext();
      newNodePtr->setNext(aftPtr);
      newNodePtr->setPrev(prevPtr);
      if (prevPtr != nullptr) prevPtr->setNext(newNodePtr);
      if (aftPtr != nullptr) aftPtr->setPrev(newNodePtr);
   } // end if

   itemCount++;
   return true;
}

/** Removes the first or only occurrence of the given entry from this
       sorted list.
    @pre  None.
    @post  If the removal is successful, the first occurrence of the
       given entry is no longer in the sorted list, and the returned
       value is true. Otherwise, the sorted list is unchanged and the
       returned value is false.
    @param anEntry  The entry to remove.
    @return  True if removal is successful, or false if not. */
bool SortedList::removeSorted(const int& anEntry)
{
   Node* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      Node* prev = entryNodePtr->getPrev();
      Node* next = entryNodePtr->getNext();

      if (prev != nullptr) prev->setNext(next);
      if (next != nullptr) {
         if (entryNodePtr == headPtr) headPtr = next;
         next->setPrev(prev);
      }

      // Delete node
      Node* nodeToDeletePtr = entryNodePtr;

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      nodeToDeletePtr->setPrev(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;

      itemCount--;
   } // end if

   return canRemoveItem;
}

/** Merges the two sorted list and returns the newly formed sorted list.
    @pre  None.
    @post  The pointer to the newly formed sorted list is returned.
       The sorted list is unchanged.
    @param other  The other sorted list to merge with.
    @return  The pointer to the newly formed sorted list is returned. */
SortedList SortedList::merge(const SortedList& other) const
{
   SortedList mergedList;
   int count = 0;
   Node* first = headPtr;
   Node* second = other.headPtr;

   if (first == nullptr && second == nullptr)
   {
      return mergedList;
   }

   // set the head of the new merged list by comparing the head elements
   // of the two sorted lists
   Node* current = new Node();
   if (first == nullptr && second != nullptr)
   {
      current->setItem(second->getItem());
      second = second->getNext();
   }
   else if (first != nullptr && second == nullptr)
   {
      current->setItem(first->getItem());
      first = first->getNext();
   }
   else if (first->getItem() < second->getItem())
   {
      current->setItem(first->getItem());
      first = first->getNext();
   }
   else
   {
      current->setItem(second->getItem());
      second = second->getNext();
   }

   // set the head pointer of the newly created merged list
   mergedList.headPtr = current;
   count++;

   // merge the list while the length of the two lists are equal
   while (first != nullptr && second != nullptr)
   {
      Node* newNode;

      if (first->getItem() < second->getItem())
      {
         newNode = new Node(first->getItem());
         first = first->getNext();
      }
      else
      {
         newNode = new Node(second->getItem());
         second = second->getNext();
      }

      newNode->setPrev(current);
      current->setNext(newNode);
      current = current->getNext();
      count++;
   }

   // in case the two lists are of different length
   // add the remaining elements to the merged list
   Node* rest = first == nullptr ? second : first;
   while (rest != nullptr)
   {
      Node* newNode = new Node(rest->getItem());
      newNode->setPrev(current);
      current->setNext(newNode);
      rest = rest->getNext();
      current = current->getNext();
      count++;
   }

   mergedList.itemCount = count;
   return mergedList;
}

/** Prints the current list to console. Each value is followed by space.
    @pre  None.
    @post  The current list is printed to the console. */
void SortedList::print()
{
   Node* current = headPtr;

   while (current != nullptr) {
      cout << current->getItem() << " ";
      current = current->getNext();
   }

   cout << endl;
}

/** Gets the position of the first or only occurrence of the given
    entry in this sorted list. In case the entry is not in the list,
    determines where it should be if it were added to the list.
    @pre  None.
    @post  The position where the given entry is or belongs is returned.
       The sorted list is unchanged.
    @param anEntry  The entry to locate.
    @return  Either the position of the given entry, if it occurs in the
    sorted list, or the position where the entry would occur, but as a
    negative integer. */
int SortedList::getPosition(const int& anEntry) const
{
   Node* current = headPtr;
   int position = -1;
   bool found = false;

   while (current != nullptr && !found)
   {
      if (current->getItem() == anEntry) found = true;
      current = current->getNext();
      position++;
   }

   return found ? position : -1;
}

/** Sees whether this list is empty. */
bool SortedList::isEmpty() const
{
   return itemCount == 0;
}

/** Gets the current number of entries in this list. */
int SortedList::getLength() const
{
   return itemCount;
}

/** Removes the entry at a given position from this list. */
bool SortedList::remove(int position)
{
   int anEntry = getEntry(position);
   return removeSorted(anEntry);
}

/** Removes all entries from this list. */
void SortedList::clear()
{
   Node* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      nodeToDeletePtr->setPrev(nullptr);
      delete nodeToDeletePtr;

      nodeToDeletePtr = headPtr;
   } // end while

   itemCount = 0;
}  // end clear

/** Gets the entry at the given position in this list. */
int SortedList::getEntry(int position) const
{
   Node* current = headPtr;
   int currPosition = 0;

   while (current != nullptr && currPosition != position)
   {
      current = current->getNext();
      currPosition++;
   }

   return current == nullptr ? -1 : current->getItem();
}

/** Destroys this sorted list and frees its assigned memory. */
SortedList::~SortedList()
{
   clear();
} // end destructor