#include <iostream>
#include "QuickSort.h"
#include "IntCompare.cpp"

int main()
{
	int testArray[25] = { 22, 67, 12, 19, 111, 90, 77, 35, 72, 55, 84, 68, 49, 39, 40, 18, 63, 34, 74, 28, 26, 99, 82, 61, 15};

	QuickSort<int, IntCompare> quick;

	quick.quickSort(testArray, 0, 24);


	for (int i = 0; i < (sizeof(testArray) / sizeof(*testArray) - 1); i++)
	{
		std::cout << testArray[i] << ", " ;
	}

	std::cout << testArray[(sizeof(testArray) / sizeof(*testArray) - 1)] << std::endl;

	return 0;
}