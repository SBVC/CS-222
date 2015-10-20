#pragma once

template <typename T> class DoublyLinkedNode
{
	public:
		T element;
		DoublyLinkedNode* next;
		DoublyLinkedNode* prev;

		DoublyLinkedNode(const T& value, DoublyLinkedNode* nextNode, DoublyLinkedNode* prevNode);
		DoublyLinkedNode();
				
};

template <typename T>
DoublyLinkedNode<T>::DoublyLinkedNode(const T& value, DoublyLinkedNode* nextNode, DoublyLinkedNode* prevNode)
{
	element = value;
	next = nextNode;
	prev = prevNode;
}

template <typename T>
DoublyLinkedNode<T>::DoublyLinkedNode()
{
	next = NULL;
	prev = NULL;
}

