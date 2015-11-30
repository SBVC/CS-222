#pragma once

template <typename T, typename Comparitor>
class shellSort {
    private:
        void insertionSort(T array[], int length, int increment) {
            // for everything we're comparing this iteration
            for (int i = increment; i < length; i += increment) //NOTE may be an error, doesn't check last value?
                // for everything that isn't sorted (I don't understand this part...)
                for (int j = i; (j >= increment) && Comparitor::hasPriority(array[j], array[j-increment]); j -= increment) {
                    // swap the values
                    T swap = array[j];
                    array[j] = array[j-increment];
                    array[j-increment] = swap;
                }
        }
    public:
        void sort(T array[], int length) {
            for (int i = length/2; i > 2; i /= 2) // for each increment, each pass
                for (int j = 0; j < i; j++)       // sort each sublist
                    insertionSort(&array[j], length-j, i); // I don't understand this part
        }
};
