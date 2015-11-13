//The header file for the K-ary implementation. borrowed from code for a binary search tree

#pragma once

class KAT {			//KAT=K-Ary Tree
private:

	struct node {
		int key;
		node* left;
		node* right;
	};

	node* root;

	void AddLeafPrivate(int key, node* Ptr);
	void PrintInOrderPrivate(node* Ptr);
	node* ReturnNodePrivate(int key, node* Ptr);
	int FindSmallestPrivate(node* Ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);
	node* CreateLeaf(int key);
	node* ReturnNode(int key);
	void RemoveSubtree(node* Ptr);

public:

	KAT();
	~KAT();
	void AddLeaf(int key);
	void PrintInOrder();
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key);


};