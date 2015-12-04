#pragma once


template <typename T, typename Comparitor>
class shellSort2 {
private:
	void swap(T array[], int position1, int position2)
	{
		T temp = array[position1];
		array[position1] = array[position2];
		array[position2] = temp;
	}

	void incrementedInsertionSort(T array[], int length, int increment) 
	{
		for (int i = increment; i < length; i += increment) 
		{
			for (int j = i; (j >= increment) && (Comparitor::hasPriority(array[j], array[j-increment])); j -= increment) 
			{
					swap(array, j, j-increment);
			}
		}
	}


public:
	void sort(T array[], int length) 
	{
		for (int i = length / 2; i > 1; i /= 2) 
		{
			for (int j = 0; j < i; j++)
				{incrementedInsertionSort(array, length-j, i);}
		}

		incrementedInsertionSort(array, length, 1);
	}
};
