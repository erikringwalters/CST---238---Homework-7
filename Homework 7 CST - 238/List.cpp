/*
* Title: List.cpp
* Abstract: This program is the implementation of the list class.
* Author: XXXX
* ID:XXXX
* Date:XX/XX/XX
*/

/*-- List.cpp------------------------------------------------------------

This file implements List member functions.

-------------------------------------------------------------------------*/

#include <cassert>
using namespace std;

#include "List.h"

//--- Definition of class constructor
List::List()
	: mySize(0)
{}

//--- Definition of empty()
bool List::empty() const
{
	return mySize == 0;
}

//--- Definition of display()
void List::display(ostream & out) const
{
	for (int i = 0; i < mySize; i++)
		out << myArray[i] << "  ";
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const List & aList)
{
	aList.display(out);
	return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos)
{
	if (mySize == CAPACITY)
	{
		cerr << "*** No space for list element -- terminating "
			"execution ***\n";
		exit(1);
	}
	if (pos < 0 || pos > mySize)
	{
		cerr << "*** Illegal location to insert -- " << pos
			<< ".  List unchanged. ***\n";
		return;
	}

	// First shift array elements right to make room for item

	for (int i = mySize; i > pos; i--)
		myArray[i] = myArray[i - 1];

	// Now insert item at position pos and increase list size  
	myArray[pos] = item;
	mySize++;
}

//--- Definition of erase()
void List::erase(int pos)
{
	if (mySize == 0)
	{
		cerr << "*** List is empty ***\n";
		return;
	}
	if (pos < 0 || pos >= mySize)
	{
		cerr << "Illegal location to delete -- " << pos
			<< ".  List unchanged. ***\n";
		return;
	}

	// Shift array elements left to close the gap
	for (int i = pos; i < mySize; i++)
		myArray[i] = myArray[i + 1];

	// Decrease list size
	mySize--;
}


bool List::addItem(ElementType item)
{
	int pos = 0;

	if (mySize == CAPACITY)
	{
		cerr << "*** No space for list element ***\n";
		return false;
	}

	//locate position
	for (int i = 0; i < mySize; i++)
	{
		if (myArray[i] < item)
			pos++;
	}

	// First shift array elements right to make room for item
	for (int i = mySize; i > pos; i--)
		myArray[i] = myArray[i - 1];

	// Now insert item at position pos and increase list size  
	myArray[pos] = item;
	mySize++;

	return true;
}


//-- Definition  of deleteItem()
bool List::deleteItem(ElementType item)
{
	bool found = false;

	if (mySize == 0)
	{
		cerr << "*** List is empty ***\n";
		return false;
	}

	// Search for item; if exists,
	// Shift array elements left to close the gap
	for (int i = 0; i < mySize; i++)
	{
		if (myArray[i] == item)
		{
			for (int j = i; j < mySize; j++)
				myArray[j] = myArray[j + 1];

			// Decrease list size and check i again
			mySize--;
			i--;
			found = true;
		}
	}
	return found;
}


//-- Definition of findLast()
int List::findLast(ElementType item)
{
	for (int i = mySize - 1; i >= 0; i--)
	{
		if (myArray[i] == item)
		{
			return i;
		}
	}
	return -1;
}

//Erik's code to count the duplicates of each value.
void List::countDuplicates()
{
	ElementType max = INT_MIN;
	
	for (int i = 0; i < mySize; i++)
	{
		if (myArray[i] > max)
		{
			max = myArray[i];
		}
	}
	const ElementType constantMax = max;
	ElementType *countHowManyOfThisValue = new ElementType[constantMax];
	for (int i = 0; i < max; i++)
	{
		*(countHowManyOfThisValue + i) = 0;
		cout << *(countHowManyOfThisValue + i) << endl;
	}
	//countHowManyOfThisValue[max];
	for (int i = 0; i < mySize; i++)
	{
		for (int j = 0; j < mySize; j++)
		{
			if (myArray[i] == myArray[j])
			{
				*(countHowManyOfThisValue+i) += 1;
			}
		}
	}
	for (int i = 0; i < max; i++)
	{
		if (*(countHowManyOfThisValue + i) > 0)
		{
			cout << *(countHowManyOfThisValue + i) << " --> " << i << endl;
		}
	}
}