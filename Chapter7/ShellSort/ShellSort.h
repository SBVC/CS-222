#pragma once
#include <iostream>

template <typename T, typename Comparitor>
class shellSort {
    private:
        void insertionSort(T array[], int length, int increment) {
            for (int i = 0; i < length - increment; i += increment) {
                for (int j = i + increment; j < length; j += increment) {
                    //std::cout << "Comparing " << array[i] << " and " << array[j] << std::endl;
                    if (Comparitor::hasPriority(array[j], array[i])) {
                        //std::cout << "Swaping." << std::endl;
                        T swap = array[i];
                        array[i] = array[j];
                        array[j] = swap;
                    }
                }
            }
        }

    public:
        void sort(T array[], int length) {
            for (int i = length / 2; i > 0; i /= 2) {
                //std::cout << "Comparing at increment " << i << std::endl;
                insertionSort(array, length, i);
            }
        }
};
