#include <iostream>
#include "ShellSort.h"
#include "IntCompare.cpp"

void printIntArray(int array[], int length) {
    for (int i = 0; i < length - 1; i++)
        std::cout << array[i] << ", ";

    std::cout << array[length - 1] << std::endl;
}

int main() {
    int array[] = { 38, 199, 28, 11, 12, 68, 12, 92, 92, 100, 3, 72, 47, 49, 48 };

    std::cout << "Before sort: ";
    printIntArray(array, 15);

    shellSort<int, IntCompare> sorter;

    sorter.sort(array, 15);

    std::cout << "After sort: ";
    printIntArray(array, 15);

    return 0;
}
