#pragma once

template <typename T> class AbstractQueue
{
	public:
		// Reinitialize the queue;
		virtual void clear() =0;

		//Queue an element.
		virtual void enqueue(T value) =0;

		// Remove the element from the fron of the queue.
		virtual T dequeue() =0;

		// Show the element at the front of the list.
		virtual T showFront() =0;

};