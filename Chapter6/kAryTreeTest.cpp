//Demonstration of the various functions of a k-ary tree, borrowed from binary tree code

#include <iostream>
#include <cstdlib>

#include "kAryTree.cpp"

using namespace std;

int main() {

	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 90 };
	KAT myTree;
	int input = 0;

	//Print the binary search tree before array is passed into it
	cout << "Printing the tree in order\nBefore adding numbers\n";
	myTree.PrintInOrder;
	for (int i = 0; i < 16; i++) {
		myTree.AddLeaf(TreeKeys[i]);
	}
	//Print tree after array is passed in
	cout << "Printing the tree in order\nAfter adding numbers\n";
	myTree.PrintInOrder();
	cout << endl;


	//For printing values in the tree
	/*
	for (int i = 0; i < 16; i++) {
	myTree.PrintChildren(TreeKeys[i]);
	cout << endl;
	}
	*/

	//For findSmallest function
	//cout << "The smalest value in the tree is " << myTree.FindSmallest() << endl;;

	//Demonstrate RemoveNode function
	cout << "Enter a key value to delete. Enter -1 to stop the process\n";
	while (input != -1) {
		cout << "Delete Node: ";
		cin >> input;
		{if (input != -1) {
			cout << endl;
			myTree.RemoveNode(input);
			myTree.PrintInOrder();
			cout << endl;
		}}
	}

	return 0;
}