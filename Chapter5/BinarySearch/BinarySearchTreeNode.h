#pragma once

template <typename Key, typename T> class BinarySearchTreeNode
{
	private:
	Key K;
	T value;

	BinarySearchTreeNode* leftChild;
	BinarySearchTreeNode* rightChild;

	public:

	BinarySearchTreeNode()
	{
		leftChild = NULL;
		rightChild = NULL;
	}

	BinarySearchTreeNode(Key k, T element, BinarySearchTreeNode* left = NULL, BinarySearchTreeNode* right = NULL)
	{
		K = k;
		value = element;
		leftChild = left;
		rightChild = right;
	}

	T& element()
	{
		return value;
	}
	
	void setElement(const T& element)
	{
		value = element;
	}

	Key& key()
	{
		return K;
	}

	void setKey(Key& k)
	{
		K = k;
	}

	BinarySearchTreeNode* left() const
	{
		return leftChild;
	}

	void setleft(BinarySearchTreeNode* node)
	{
		leftChild = node;
	}

	BinarySearchTreeNode* right()  const
	{
		return rightChild;
	}

	void setRight(BinarySearchTreeNode* node)
	{
		rightChild = node;
	}

	bool isLeaf()
	{
		return (leftChild == NULL) && (rightChild == NULL)
	}
};