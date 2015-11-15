#pragma once
#include <vector>

template < typename T, typename Comparitor>
class mergeSort
{
	public:
	void sort(T Array[], T tempArray[], int startIndex, int endIndex)
	{
		if (startIndex == endIndex)
			return;
		else
		{
			int mid = (startIndex + endIndex) / 2;
			sort(Array, tempArray, startIndex, mid);
			sort(Array, tempArray, mid+1, endIndex);

			for (int i = startIndex; i <= endIndex; i++)
			{
				tempArray[i] = Array[i];
			}

			int leftIndex = startIndex;
			int rightIndex = mid + 1;

			for (int current = startIndex; current <= endIndex; current++)
			{
				if (leftIndex >= mid + 1)
				{
					Array[current] = tempArray[rightIndex];
					rightIndex++;
				}
				else if (rightIndex > endIndex)
				{
					Array[current] = tempArray[leftIndex];
					leftIndex++;
				}
				else if (Comparitor::hasPriority(tempArray[leftIndex], tempArray[rightIndex]))
				{
					Array[current] = tempArray[leftIndex];
					leftIndex++;
				}
				else
				{
					Array[current] = tempArray[rightIndex];
					rightIndex++;
				}
					
			}
		}
	}
};