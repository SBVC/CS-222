#include <iostream>
#include "Heap.h"
#include "IntComparorLargerPriority.cpp"

int main()
{
	
	int intArray[10] = { 5,6,1,3,10,2,4,9,7,8 };
	
	Heap<int, IntComparorLargerPriority> heap(intArray, 30, 10);

	for (int i = 0; i < heap.size(); i++)
	{
		std::cout << heap.showElement(i) << " ";
	}

	heap.insert(15);
	std::cout << std::endl;

	for (int i = 0; i < heap.size(); i++)
	{
		std::cout << heap.showElement(i) << " ";
	}

	heap.remove(1);
	std::cout << std::endl;

	for (int i = 0; i < heap.size(); i++)
	{
		std::cout << heap.showElement(i) << " ";
	}

	heap.removeTop();
	std::cout << std::endl;

	for (int i = 0; i < heap.size(); i++)
	{
		std::cout << heap.showElement(i) << " ";
	}

	return 0;
}