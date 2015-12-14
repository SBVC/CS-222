#include <iostream>
#include <cstdlib>
#define MAX 50

#include "tst.h"

using namespace std;

TST::TST() {
	root = NULL;
}

//Create a 3-ary search tree node
TST::node* TST::newNode(char data) {
	node* temp = new node;
	temp->data = data;
	temp->isEndOfString = 0;
	temp->left = temp->eq = temp->right = NULL;
	return temp;
}

//Insert a new word into the 3-ary search tree
void TST::insertWord(char *word) {
	insertWordPrivate(&root, word);
}
//Have the public function pass to private one to manipulate private variables
void TST::insertWordPrivate(node** root, char *word) {
	if (!(*root))
		*root = newNode(*word);
	if ((*word) < (*root)->data)
		insertWordPrivate(&((*root)->left), word);
	else if ((*word) > (*root)->data)
		insertWordPrivate(&((*root)->right), word);
	else {
		if (*(word + 1))
			insertWordPrivate(&((*root)->eq), word + 1);
		else
			(*root)->isEndOfString = 1;
	}
}

//Traverse Utility function
void TST::traverseTSTUtil(node* root, char* buffer, int depth) {
	if (root) {
		traverseTSTUtil(root->left, buffer, depth);
		buffer[depth] = root->data;
		if (root->isEndOfString) {
			buffer[depth + 1] = '\0';
			cout << buffer << endl;
		}
		traverseTSTUtil(root->eq, buffer, depth + 1);
		traverseTSTUtil(root->right, buffer, depth);
	}
}

//Traverse 3-ary search tree
void TST::traverseTST() {
	char buffer[MAX];
	traverseTSTUtil(root, buffer, 0);
}

//Search for a given word in the tree
int TST::searchTST(char *word) {
	return searchTSTPrivate(root, word);
}
//Use buffer to pass to private function again
int TST::searchTSTPrivate(node *root, char *word) {
	if (!root)
		return 0;
	if (*word < (root)->data)
		return searchTSTPrivate(root->left, word);
	else if (*word>(root)->data)
		return searchTSTPrivate(root->right, word);
	else {
		if (*(word + 1) == '\0')
			return root->isEndOfString;
		return searchTSTPrivate(root->eq, word + 1);
	}
}

//Use tree deconstructor
TST::~TST() {
	RemoveSubtree(root);
}

void TST::RemoveSubtree(node* Ptr) {
	if (Ptr != NULL) {
		if (Ptr->left != NULL) {
			RemoveSubtree(Ptr->left);
		}
		if (Ptr->eq!= NULL) {
			RemoveSubtree(Ptr->eq);
		}
		if (Ptr->right != NULL) {
			RemoveSubtree(Ptr->right);
		}
		cout << "Deleting the node containing key " << Ptr->data << endl;
		delete Ptr;
	}
}