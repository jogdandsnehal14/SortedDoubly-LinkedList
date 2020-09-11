//---------------------------------------------------------------------------
// File: Node.h
// Author: Snehal Jogdand
// Date: 10/23/2019
// Program 2: Merge Sorted List
//
// DESCRIPTION:
// Node: 
//  The header file for Node class
//  Provides the set of variables and functions to process a Node
//---------------------------------------------------------------------------

#ifndef NODE_
#define NODE_

//---------------------------------------------------------------------------
// Node: The header file for Node class
//  Provides the set of variables and functions to process a Node
//---------------------------------------------------------------------------
class Node
{
private:
   int item;   // A data item
   Node* prev; // Pointer to previous node
   Node* next; // Pointer to next node

public:
   Node();
   Node(const int& anItem);
   Node(const int& anItem, Node* prevNodePtr, Node* nextNodePtr);
   void setItem(const int& anItem);
   void setPrev(Node* prevNodePtr);
   void setNext(Node* nextNodePtr);
   int getItem() const;
   Node* getPrev() const;
   Node* getNext() const;
}; // end Node
#endif