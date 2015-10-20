#include <iostream>
#include "LinkedStack.h"

int main()
{
	LinkedStack<int> stack = LinkedStack<int>();
	for (int i = 0; i < 10; i = i + 2)
	{
		stack.push(i);
		std::cout << stack.peek() << std::endl;
	}
	try
	{
		for (int i = 0; i < 10; i++)
		{
			int topValue = stack.pop();
			std::cout << topValue << std::endl;
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}