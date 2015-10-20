#pragma once

template <typename T> class SinglyLinkedNode
{
	public:
		T element;
		SinglyLinkedNode* next;

		SinglyLinkedNode(T& value, SinglyLinkedNode* next);
		~SinglyLinkedNode();
	
};

template <typename T>
SinglyLinkedNode<T>::SinglyLinkedNode(T& value, SinglyLinkedNode* nextNode)
{
	element = value;
	next = nextNode;
}

template <typename T>
SinglyLinkedNode<T>::~SinglyLinkedNode()
{}