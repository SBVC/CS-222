#pragma once
#include <stdexcept>

template <typename T, typename Comparitor> class Heap
{
	private:

	T* heapArray;
	int maxCapacity;
	int currentCapacity;

	void siftDown(int position);
	void heapify();
	void swap(T* heap, int position1, int position2);
	

	public:

	Heap(T* heap, int max, int current)
	{
		maxCapacity = max;
		currentCapacity = current;

		heapArray = new T[maxCapacity];
		for (int i = 0; i < currentCapacity; i++)
		{
			heapArray[i] = heap[i];
		}
		
		heapify();
	}

	bool isLeaf(int position) const
	{
		return (position >= currentCapacity / 2) && (position < currentCapacity);
	}

	int leftChildPosition(int position) const
	{
		return 2 * position + 1;
	}

	int rightChildPositon(int position) const
	{
		return 2 * position + 2;
	}

	int parentPosition(int position) const
	{
		return (position - 1) / 2;
	}

	int size() const
	{
		return currentCapacity;
	}

	void insert(const T& value);

	T remove(int position);

	T removeTop();

	T showElement(int position)
	{
		return heapArray[position];
	}
};

template <typename T, typename Comparitor>
void Heap<typename T, typename Comparitor>::heapify()
{
	for (int i = (currentCapacity / 2) - 1; i >= 0; i--)
	{
		siftDown(i);
	}
}

template <typename T, typename Comparitor>
void Heap<typename T, typename Comparitor>::swap(T* heap, int position1, int position2)
{
	T temp = heap[position1];
	heap[position1] = heap[position2];
	heap[position2] = temp;
}

template <typename T, typename Comparitor>
void Heap<typename T, typename Comparitor>::siftDown(int position)
{
	while (!isLeaf(position))
	{
		int mostPriority = leftChildPosition(position);
		int rightChild = rightChildPositon(position);

		if ((rightChild < currentCapacity) && (Comparitor::hasPriority(heapArray[rightChild], heapArray[mostPriority])))
		{
			mostPriority = rightChild;
		}

		if (Comparitor::hasPriority(heapArray[position], heapArray[mostPriority]))
			{return;}
		else
		{
			swap(heapArray, position, mostPriority);
			position = mostPriority;
		}
	}
}

template <typename T, typename Comparitor>
void Heap<typename T, typename Comparitor>::insert(const T& value)
{
	if (currentCapacity < maxCapacity)
	{
		int currentPosition = currentCapacity;
		heapArray[currentCapacity] = value;
		currentCapacity++;

		while ((currentPosition > 0) && Comparitor::hasPriority(heapArray[currentPosition], heapArray[parentPosition(currentPosition)]))
		{
			swap(heapArray, currentPosition, parentPosition(currentPosition));
			currentPosition = parentPosition(currentPosition);
		}
	}
	else
	{
		throw std::exception("Heap full.");
	}
}

template <typename T, typename Comparitor>
T Heap<typename T, typename Comparitor>::remove(int position)
{
	T returnValue = heapArray[position];

	if (position >= 0 && position < currentCapacity)
	{
		if (position == currentCapacity -1)
			{currentCapacity--;}
		else
		{
			swap(heapArray, position, currentCapacity-1);
			currentCapacity--;

			while ((position > 0) && Comparitor::hasPriority(heapArray[position], heapArray[parentPosition(position)]))
			{
				swap(heapArray, position, parentPosition(position));
				position = parentPosition(position);
			}
			
			if (currentCapacity > 0)
				{siftDown(position);}
		}

		return returnValue;
	}
	else
	{
		throw std::exception("Heap empty.");
	}
}

template <typename T, typename Comparitor>
T Heap<typename T, typename Comparitor>::removeTop()
{
	if (currentCapacity > 0)
	{
		T returnValue = heapArray[0];

		swap(heapArray, 0, currentCapacity);
		currentCapacity--;
		if (currentCapacity > 0)
		{
			siftDown(0);
		}
		
		return returnValue;
	}
	else
	{
		throw std::exception("Heap empty.");
	}
}