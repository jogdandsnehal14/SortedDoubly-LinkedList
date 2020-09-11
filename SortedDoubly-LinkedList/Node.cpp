///---------------------------------------------------------------------------
// File: Node.cpp
// Author: Snehal Jogdand
// Date: 10/23/2019
// Program 2: Merge Sorted List
//
// DESCRIPTION:
// Node: 
//  The class file for Node class
//  Provides the implementation of variables and functions to process a Node
//---------------------------------------------------------------------------

#include "Node.h"

Node::Node() : item(0), prev(nullptr), next(nullptr)
{
} // end default constructor

Node::Node(const int& anItem) : item(anItem), prev(nullptr), next(nullptr)
{
} // end constructor

Node::Node(const int& anItem, Node* prevNodePtr, Node* nextNodePtr) :
   item(anItem), prev(prevNodePtr), next(nextNodePtr)
{
} // end constructor

void Node::setItem(const int& anItem)
{
   item = anItem;
} // end setItem

void Node::setPrev(Node* prevNodePtr)
{
   prev = prevNodePtr;
}  // end setPrev

void Node::setNext(Node* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

int Node::getItem() const
{
   return item;
} // end getItem

Node* Node::getPrev() const
{
   return prev;
}  // end getPrev

Node* Node::getNext() const
{
   return next;
} // end getNext