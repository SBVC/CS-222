#include <iostream>
#include "LinkedQueue.h"

int main()
{
	LinkedQueue<int> queue = LinkedQueue<int>();

	queue.enqueue(10);
	queue.enqueue(20);
	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.showFront() << std::endl;
	try
	{
		std::cout << queue.dequeue() << std::endl;
		std::cout << queue.dequeue() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

