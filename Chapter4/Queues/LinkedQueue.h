#pragma once
#include "AbstractQueue.h"
#include "SinglyLinkedNode.h"
#include <stdexcept>


template <typename T> class LinkedQueue : AbstractQueue<T>
{
	private:
		int size;
		SinglyLinkedNode<T>* front;
		SinglyLinkedNode<T>* back;
	public:

		LinkedQueue();
		~LinkedQueue();

		void clear()
		{
			while (front->next != NULL)
			{
				back = front->next;
				front->next = front->next->next;
				delete back;
			}
			back = front;
			size = 0;
		}

		
		void enqueue(T value)
		{
			back->next = new SinglyLinkedNode<T>(value, NULL);
			back = back->next;
			size++;
		}

		
		T dequeue()
		{
			if (size > 0)
			{
				T frontValue = front->next->element;
				SinglyLinkedNode<T>* toBeRemoved = front->next;
				front->next = toBeRemoved->next;
				if (toBeRemoved == back)
					{back = front;}
				delete toBeRemoved;
				size--;
				return frontValue;
			}
			else
			{
				throw std::exception("Queue is empty!");
			}
		}

		
		T showFront()
		{
			return front->next->element;
		}
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	front = back = new SinglyLinkedNode<T>();
	size = 0;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	clear();
	delete front;
}