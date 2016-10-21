/*
* Title: listtester.cpp
* Abstract: This program is the driver of the list class.
* Author: XXXX
* ID:XXXX
* Date:XX/XX/XX
*/

//--- listtester.cpp: Program to test List class.

#include <iostream>
using namespace std;

#include "List.h"

int main()
{
	List scoreList;
	 cout << "Constructing scoreList\n";
	 // Test addItem() by adding 80.5, 100.0, 89.0, 75.5, and 100.0.
	 scoreList.addItem(2);
	 scoreList.addItem(2);
	 scoreList.addItem(2);
	 scoreList.addItem(3);
	 scoreList.addItem(4);
	 scoreList.addItem(3);
	 scoreList.addItem(5);
	 scoreList.addItem(6);
	 scoreList.addItem(5);
	//CST238 Page 2 of 2 Homework 6
	//cout << scoreList << endl;
	cout << "Duplicate counter test: " << endl;
	scoreList.countDuplicates();
	return 0;
}