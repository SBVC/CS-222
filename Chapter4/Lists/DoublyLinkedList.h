#pragma once
#include "AbstractList.h"
#include "DoublyLinkedNode.h"
#include <stdexcept>

template <typename T> class DoublyLinkedList : AbstractList<T>
{
	private:
		DoublyLinkedNode<T>* head;
		DoublyLinkedNode<T>* tail;
		DoublyLinkedNode<T>* current;
		int size;

		void initialize()
		{
			
			head = new DoublyLinkedNode<T>();
			tail = new DoublyLinkedNode<T>(NULL, NULL, head);
			head->next = tail;
			current = head;
			
			size = 0;
		}

		void removeAll()
		{
			while (head != NULL)
			{
				current = head;
				head = head->next;
				delete current;
			}
		}

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		void insert(const T& value)
		{
			if (current != head && current != tail)
			{
				current->next = current->next->prev = new DoublyLinkedNode<T>(value, current->next, current);
			}
			else if (current == head)
			{
				head->next = head->next->prev = new DoublyLinkedNode<T>(value, head->next, head);
			}
			else
			{
				tail->prev = tail->prev->next = new DoublyLinkedNode<T>(value, tail, tail->prev);
			}
			
			size++;
		}

		T remove()
		{
			if (current == tail || current == head)
				{return NULL;}
			else
			{
				DoublyLinkedNode<T>* toBeRemoved = current;
				T returnValue = current->element;

				
				current->next->prev = current->prev;
				current = current->prev->next = current->next;
				current = current->next;
				delete toBeRemoved;
				size--;
				return returnValue;
			}
			
		}

		void append(const T& value)
		{
			tail->prev = tail->prev->next = new DoublyLinkedNode<T>(value, tail, tail->prev);
			size++;
		}

		void clear()
		{
			removeAll();
			initialize();
		}

		void moveToStart()
		{
			current = head->next;
			if (current == tail)
			{
				current = head;
			}
		}

		void moveToEnd()
		{
			current = tail->prev;
			
		}

		void next()
		{
			if (current != tail->prev && current != tail)
				{current = current->next;}
		}

		void previous()
		{
			if (current != head->next)
				{current = current->prev;}
		}

		int getCurrentPos()
		{
			DoublyLinkedNode<T>* temp = head;
			int i = -1;
			while (temp != current)
			{
				temp = temp->next;
				i++;
			}
			return i;
		}

		void moveToPosition(int position)
		{
			if (position < -1 || position > size)
				{throw std::out_of_range("Not a valid position.");}
			else
			{
				current = head;
				for (int i = 0; i < position; i++)
					{current = current->next;}
			}
		}

		const T& getElement() const
		{
			if (current == NULL)
				{throw std::exception("No value present.");}
			else
				{return current->element;}
		}

		int length() const
		{return size;}
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	initialize();
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	removeAll();
}
