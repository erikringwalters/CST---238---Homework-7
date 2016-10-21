#pragma once
/*
* Title: List.h
* Abstract: This program is the header of the list class.
* Author: XXXX
* ID:XXXX
* Date:XXXX
*/

/*-- List.h ---------------------------------------------------------------

This header file defines the data type List for processing lists.
Basic operations are:
Constructor
empty:    Check if list is empty
insert:   Insert an item
erase:    Remove an item
display:  Output the list
<<:       Output operator

addItem:    Insert an item (keep ascending order)
deleteItem: Remove an Item
findLast:   Search an item

-------------------------------------------------------------------------*/

#include <iostream>

#ifndef LIST
#define LIST

const int CAPACITY = 10;
typedef int ElementType;

class List
{
public:

	List();  /* Constructor */
	bool empty() const;
	void insert(ElementType item, int pos);
	void erase(int pos);
	bool addItem(ElementType item);
	bool deleteItem(ElementType item);
	int findLast(ElementType item);
	void display(ostream & out) const;
	void countDuplicates();
	void deleteDuplicates(ElementType item);
	void reverseList(ElementType item);
private:
	int mySize;                     // current size of list stored in myArray
	ElementType myArray[CAPACITY];  // array to store list elements
}; //--- end of List class

   //------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);

#endif