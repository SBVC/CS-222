#pragma once

template <typename T> class AbstractStack
{
	public:
		virtual ~AbstractStack() {};

		// Re-initialize stack.
		virtual void clear() =0;

		// Push an element onto stack.
		virtual void push(T value) =0;

		// Pop value off of stack.
		virtual T pop() =0;

		// Return a copy of the top value.
		virtual const T peek() const =0;

		// Return the size of the stack.
		virtual int size() const =0;

};