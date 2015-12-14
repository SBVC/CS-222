#include <iostream>
#include <cstdlib>
#define MAX 50

#include "tst.h"

using namespace std;


int main() {

	TST tree;
	
	tree.insertWord("trip");
	tree.insertWord("dog");
	tree.insertWord("rain");
	tree.insertWord("rainy");

	cout << "The following is a traversal of the 3-ary search tree:\n";
	tree.traverseTST();

	if (tree.searchTST("trip"))
		cout << "trip has been found in the 3-ary search tree.\n";
	else
		cout << "trip has not been found in the 3-ary search tree.\n";
	if (tree.searchTST("rainy"))
		cout << "rainy has been found in the 3-ary search tree.\n";
	else
		cout << "rainy has not been found in the 3-ary search tree.\n";
	if (tree.searchTST("cat"))
		cout << "cat has been found in the 3-ary search tree.\n";
	else
		cout << "cat has not been found in the 3-ary search tree.\n";



	return 0;
}