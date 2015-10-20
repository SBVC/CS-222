#include "ArrayList.h"
#include <iostream>
#include <string>
#include <exception>

void displayIntArrayList(ArrayList<int>&);

int main()
{
	ArrayList<int> ListArray(10); // Create an array based list.

	// Test normal append and append beyond array capacity.
	try 
	{
		std::cout << "Appending elements to list." << "\n";
		for (int i = 0; i < 120; i += 10)
		{
			ListArray.append(i);
			displayIntArrayList(ListArray);
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	} 
	
	// Test normal remove and attempted move to invalid position.
	try
	{
		std::cout << "Testing removal of elements." << "\n";
		for (int i = 2; i < 20; i += 2)
		{
			ListArray.moveToPosition(i);
			int removed = ListArray.remove();
			std::cout << "Element at position " << ListArray.getCurrentPos() << ", (" << removed << "), was removed." << "\n";
			displayIntArrayList(ListArray);
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	}
	
	// Test list clear.
	std::cout << "Clearing list. List now is:" << "\n";
	ListArray.clear();
	displayIntArrayList(ListArray);

	// Repopulate list.
	std::cout << "Creating new new list." << "\n";
	for (int i = 0; i < 9; i++)
	{
		ListArray.append(i);
	}

	std::cout << "New list is:" << "\n";
	displayIntArrayList(ListArray);
	std::cout << "New list length is " << ListArray.length() << "\n";
	
	// Test moveTo and getPosition functions. 
	std::cout << "Moving to start." << "\n";
	ListArray.moveToStart();
	std::cout << "Current position is "<< ListArray.getCurrentPos() << "\n";
	std::cout << "Moving to end." << "\n";
	ListArray.moveToEnd();
	std::cout << "Current position is " << ListArray.getCurrentPos() << "\n";

	// Test normal next and previous functions.
	try
	{
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Moving one position back." << "\n";
			ListArray.previous();
			std::cout << "Current position is " << ListArray.getCurrentPos() << "\n";
		}

		for (int i = 0; i < 4; i++)
		{
			std::cout << "Moving one position forward." << "\n";
			ListArray.next();
			std::cout << "Current position is " << ListArray.getCurrentPos() << "\n";
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	}

	// Test moving past start.
	try
	{
		std::cout << "Moving to start" << "\n";
		ListArray.moveToStart();
		std::cout << "Position is: " << ListArray.getCurrentPos() << "\n";
		std::cout << "Moving back one position." << "\n";
		ListArray.previous();
		std::cout << "Position is: " << ListArray.getCurrentPos() << "\n";
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	}
	// Test moving past end.
	try
	{
		std::cout << "Moving to end" << "\n";
		ListArray.moveToEnd();
		std::cout << "Position is: " << ListArray.getCurrentPos() << "\n";
		std::cout << "Moving forward one position." << "\n";
		ListArray.next();
		std::cout << "Position is: " << ListArray.getCurrentPos() << "\n";
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	}


	return 0;
}

void displayIntArrayList(ArrayList<int>& list)
{
	std::cout << "(";
	if (list.length() > 0)
	{
		for (list.moveToStart(); list.getCurrentPos() < list.length() - 1; list.next())
		{
			std::cout << list.getElement() << ", ";
		}
		std::cout << list.getElement();
	}
	
	std::cout << ")\n";
}
