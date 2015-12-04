#include <iostream>
#include "ShellSort.h"
#include "IntCompare.cpp"
#include "ShellSort2.h"

void printIntArray(int array[], int length) {
    for (int i = 0; i < length - 1; i++)
        std::cout << array[i] << ", ";

    std::cout << array[length - 1] << std::endl;
}

int main() {
    int array[] = { 38, 199, 28, 11, 12, 68, 12, 92, 92, 100, 3, 72, 47, 49, 48, 6, 1, 6, 9, 14, 88, 12, 90, 52, 77, 500, 53, 84, 32, 0, 12, 0, 14, 67 };
    int array2[] = { 38, 199, 28, 11, 12, 68, 12, 92, 92, 100, 3, 72, 47, 49, 48, 6, 1, 6, 9, 14, 88, 12, 90, 52, 77, 500, 53, 84, 32, 0, 12, 0, 14, 67 };
    int length = sizeof(array) / sizeof(array[0]);
	int length2 = sizeof(array2) / sizeof(array2[0]);

	

   std::cout << "Before sort: ";
   printIntArray(array, length);
	
	unsigned __int64 i;
	
	shellSort<int, IntCompare> sorter;
	
	i = __rdtsc();
	sorter.sort(array, length);
	i = __rdtsc() - i;

    std::cout << "After sort: ";
    printIntArray(array, length);
	std::cout << "This sort took " << i << " clock cycles." << std::endl;;

	std::cout << "Before sort: ";
	printIntArray(array2, length2);

	shellSort2<int, IntCompare> sorter2;

	i = __rdtsc();
	sorter2.sort(array2, length2);
	i = __rdtsc() - i;

	std::cout << "After sort: ";
	printIntArray(array, length);
	std::cout << "This sort took " << i << " clock cycles." << std::endl;;

    return 0;
}
