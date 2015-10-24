#pragma once
#include "BinarySearchTreeNode.h"
#include <iostream>

template <typename Key, typename T> class BinarySearchTree
{
	private:

		BinarySearchTreeNode<Key, T>* root;
		int nodeCount;

		void clearTree(BinarySearchTreeNode<Key, T>* currentRoot);
		BinarySearchTreeNode<Key, T>* findMin(BinarySearchTreeNode<Key, T>* currentRoot);
		BinarySearchTreeNode<Key, T>* insertNode(BinarySearchTreeNode<Key, T>* currentRoot, const Key& key, const T& value);
		T findVal(BinarySearchTreeNode<Key, T>* rootNode, const Key& key) const;
		BinarySearchTreeNode<Key, T>* deleteMin(BinarySearchTreeNode<Key, T>* currentRoot);
		void printer(BinarySearchTreeNode<Key, T>* currentRoot, int level) const;
		BinarySearchTreeNode<Key, T>* removeNode(BinarySearchTreeNode<Key, T>* currentRoot, const Key& key);
	

	public:
		
		BinarySearchTree()
		{
			root = NULL;
			nodeCount = 0;
		}

		~BinarySearchTree()
		{
			clearTree(root);
		}

		void insert(const Key& key, const T& value)
		{
			root = insertNode(root, key, value);
			nodeCount++;
		}

		T remove(const Key& key)
		{
			T searchedValue = findVal(root, key);
			if (searchedValue != NULL)
			{
				root = removeNode(root, key);
				nodeCount--;
			}
			return searchedValue;
		}

		T removeRoot()
		{
			if (root != NULL)
			{
				T rootValue = root->element();
				root = removeNode(root, root->key());
				nodeCount--;
				return rootValue;
			}
			else
				return NULL;
		}

		void print() const
		{
			if (root == NULL)
				{std::cout << "The tree is empty." << std::endl;}
			else
				{printer(root, 0);}
		}

		int size() const
			{return nodeCount;}
};

template <typename Key, typename T>
 void BinarySearchTree<Key,T>::clearTree(BinarySearchTreeNode<Key, T>* currentRoot)
{
	if (currentRoot == NULL)
	{
		return;
	}
	clearTree(currentRoot->left());
	clearTree(currentRoot->right());
	delete currentRoot;
}

template <typename Key, typename T>
BinarySearchTreeNode<Key, T>* BinarySearchTree<Key, T>::findMin(BinarySearchTreeNode<Key, T>* currentRoot)
{
	if (currentRoot->left() == NULL)
		{return currentRoot;}
	else
		{return findMin(currentRoot->left());}
}

template <typename Key, typename T>
BinarySearchTreeNode<Key, T>* BinarySearchTree<Key, T>::insertNode(BinarySearchTreeNode<Key, T>* currentRoot, const Key& key, const T& value)
{
	if (currentRoot == NULL)
	{
		return new BinarySearchTreeNode<Key, T>(key, value, NULL, NULL);
	}
	if (key < currentRoot->key())
	{
		currentRoot->setleft(insertNode(currentRoot->left(), key, value));
	}
	else
	{
		currentRoot->setRight(insertNode(currentRoot->right(), key, value));
	}
	return currentRoot;
}

template <typename Key, typename T>
 T BinarySearchTree<Key, T>::findVal(BinarySearchTreeNode<Key, T>* rootNode, const Key& key) const
{
	if (rootNode == NULL)
		return NULL;
	else if (key < rootNode->key())
	{
		return findVal(rootNode->left(), key);
	}
	else if (key > rootNode->key())
	{
		return findVal(rootNode->right(), key);
	}
	else
		return rootNode->element();

}

 template <typename Key, typename T>
 BinarySearchTreeNode<Key, T>* BinarySearchTree<Key, T>::deleteMin(BinarySearchTreeNode<Key, T>* currentRoot)
 {
	 if (currentRoot->left() == NULL)
		{return currentRoot->right();}
	 else
	 {
		 currentRoot->setleft(deleteMin(currentRoot->left()));
		 return currentRoot;
	 }
 }

 template <typename Key, typename T>
 BinarySearchTreeNode<Key, T>* BinarySearchTree<Key, T>::removeNode(BinarySearchTreeNode<Key, T>* currentRoot, const Key& key)
 {
	 if (currentRoot == NULL)
	 {
		 return NULL;
	 }
	 else if (key < currentRoot->key())
	 {
		 currentRoot->setleft(removeNode(currentRoot->left(), key));
	 }
	 else if (key > currentRoot->key())
	 {
		 currentRoot->setRight(removeNode(currentRoot->right(), key));
	 }
	 else
	 {
		 BinarySearchTreeNode<Key, T>* toBeRemoved = currentRoot;

		 if (currentRoot->left() == NULL)
		 {
			 currentRoot = currentRoot->right();
			 delete toBeRemoved;
		 }
		 else if (currentRoot->right() == NULL)
		 {
			 currentRoot = currentRoot->left();
			 delete toBeRemoved;
		 }
		 else
		 {
			 toBeRemoved = findMin(currentRoot->right());
			 currentRoot->setElement(toBeRemoved->element());
			 currentRoot->setKey(toBeRemoved->key());
			 currentRoot->setRight(deleteMin(currentRoot->right()));
			 delete toBeRemoved;
		 }
	 }
	 return currentRoot;
 }

 template <typename Key, typename T>
 void BinarySearchTree<Key, T>::printer(BinarySearchTreeNode<Key, T>* currentRoot, int level) const
 {
	 if (currentRoot == NULL)
		{return;}
	else
	{
		 printer(currentRoot->left(), level +1);
		 for (int i = 0; i < level; i++)
			{std::cout << " ";}
		 std::cout << currentRoot->key() << std::endl;
		 printer(currentRoot->right(), level + 1);
	}
 }
