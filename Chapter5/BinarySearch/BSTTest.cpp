
#include <iostream>
#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"
#include <string>

int main()
{
	BinarySearchTree<int, float> BST;
	
	BST.insert(27, 27);
	BST.insert(11, 11);
	BST.insert(25, 25);
	BST.insert(28, 26);
	BST.insert(19, 19);
	BST.print();
	std::cout << std::endl <<std::endl;
	BST.removeRoot();
	BST.print();
	BST.remove(11);
	std::cout << std::endl << std::endl;
	BST.print();

	return 0;
}