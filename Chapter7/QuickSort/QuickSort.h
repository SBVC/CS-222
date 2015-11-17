#pragma once

template <typename T, typename Comparitor>
class QuickSort
{
	public:

	void quickSort(T Array[], int startIndex, int endIndex)
	{
		if (endIndex <= startIndex)
			return;
		else
		{
			int pivotIndex = findPivot(Array, startIndex, endIndex);
			swap(Array, pivotIndex, endIndex);
			int partitionIndex = partition(Array, startIndex - 1, endIndex, Array[endIndex]);
			swap(Array, partitionIndex, endIndex);
			quickSort(Array, startIndex, partitionIndex - 1);
			quickSort(Array, partitionIndex + 1, endIndex);
		}
	}

	private:

	int findPivot(T Array[], int startIndex, int endIndex)
	{
		return (startIndex + endIndex) / 2;
	}

	void swap(T Array[], int index1, int index2)
	{
		T temp = Array[index1];
		Array[index1] = Array[index2];
		Array[index2] = temp;
	}

	int partition(T Array[], int left, int right, T& pivot)
	{
		do
		{
			do
			{left++;}
			while (Comparitor::hasPriority(Array[left], pivot));

			while (left < right)
			{
				right--;
				if (!Comparitor::hasPriority(pivot, Array[right]))
					{break;}
			}
			swap(Array, left, right);

		} while (left < right);
		return left;
	}

};