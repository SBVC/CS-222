#include <iostream>
#include "MergeSort.h"
#include "IntCompare.cpp"

int main()
{

	int intArray[] = { 100, 19, 11, 15, 37, 82, 46, 71, 99, 15, 3, 59, 95 };
	int temp[13];

	mergeSort<int, IntCompare> sorter;

	sorter.sort(intArray, temp, 0, 12);

	for (int i = 0; i < (sizeof(intArray)/sizeof(*intArray)-1) ; i++)
	{
		std::cout << intArray[i] << ", ";
	}
	std::cout << intArray[(sizeof(intArray) / sizeof(*intArray) - 1)] << std::endl;
	
	return 0;
}

