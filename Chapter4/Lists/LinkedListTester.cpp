#include <iostream>
#include "DoublyLinkedList.h"

void displayIntLinkedList(DoublyLinkedList<int>&);

int main()
{
	DoublyLinkedList<int> linkedList;

	// Check initialized position;
	std::cout << linkedList.getCurrentPos() << std::endl;

	// Test consecutive inserts.
	for (int i = 5; i > 0; i--)
	{
		linkedList.insert(i);
		std::cout << linkedList.getCurrentPos() << std::endl;
		displayIntLinkedList(linkedList);
	}

	// Test consecutive appends. 
	for (int i = 10; i > 0; i--)
	{
		linkedList.append(i);
		std::cout << linkedList.getCurrentPos() << std::endl;
		displayIntLinkedList(linkedList);
	}

	// Test removes.
	linkedList.moveToStart();
	for (int i = 0; i < 15; i++)
	{
		try 
		{
			int checkValue = linkedList.remove();
			std::cout << checkValue << std::endl;
			displayIntLinkedList(linkedList);
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	// Repopulate list.
	linkedList.moveToStart();
	for (int i = 1; i < 6; i++)
	{
		linkedList.insert(i);
	}
	displayIntLinkedList(linkedList);
	
	// Test next.
	linkedList.moveToStart();
	try
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << linkedList.getCurrentPos() << std::endl;
			linkedList.next();
		}
	} 
	catch(std::exception e)
	{
		std::cout << e.what();
	}

	//Test previous
	linkedList.moveToEnd();
	
	try
	{
		for (int i = 0; i < 11; i++)
		{
			linkedList.previous();
			std::cout << linkedList.getCurrentPos() << std::endl;
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

}
	

void displayIntLinkedList(DoublyLinkedList<int>& list)
{
	int currentPosition = list.getCurrentPos();

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

	list.moveToPosition(currentPosition);
}