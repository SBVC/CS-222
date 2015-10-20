#pragma once
#include "AbstractStack.h"
#include "SinglyLinkedNode.h"
#include <stdexcept>

template <typename T> class LinkedStack : AbstractStack<T>
{
	private:
		int stackSize;
		SinglyLinkedNode<T>* top;

	public:

		LinkedStack();
		~LinkedStack();

		// Re-initialize stack.
		void clear()
		{
			top = NULL;
			stackSize = 0;
		}

		// Push an element onto stack.
		virtual void push(T value)
		{
			top = new SinglyLinkedNode<T>(value, top);
			stackSize++;
		}

		// Pop value off of stack. Throws exception if stack is empty.
		virtual T pop()
		{
			if (stackSize != 0)
			{
				T returnValue = top->element;
				SinglyLinkedNode<T>* newTop = top->next;
				delete top;
				top = newTop;
				stackSize--;
				return returnValue;
			}
			else
			{
				throw std::exception("Stack is empty!");
			}
		}

		// Return a copy of the top value.
		virtual const T peek() const
		{
			if (stackSize != 0)
				{return top->element;}
			else
			{
				throw std::exception("Stack is empty!");
			}
		}

		// Return the size of the stack.
		virtual int size() const
		{
			return stackSize;
		}
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
	top = NULL;
	stackSize = 0;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
	clear();
}