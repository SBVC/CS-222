#pragma once

template <typename T> class AbstractList
{
public:
	 ~AbstractList();
	
	// Insert element at the current positon.
	virtual void insert(const T& element) = 0;
	
	// Remove the element at the current position and return it.
	virtual T remove() = 0;

	// Add an element to the end of the list.
	virtual void append(const T& element) = 0;

	// Clear the list of all elements.
	virtual void clear() = 0;

	// Move to the start of the list.
	virtual void moveToStart() = 0;

	// Move to the end of the list.
	virtual void moveToEnd() = 0;

	// Move to the next element.
	virtual void next() = 0;

	// Move to the previous element.
	virtual void previous() = 0;

	// Return an integer representing the current position in the list.
	virtual int getCurrentPos() = 0;

	// Move to the position designated by the position parameter.
	virtual void moveToPosition(int position) = 0;

	// Return the element currently pointed to without removing it.
	virtual const T& getElement() const = 0;

	// Return the current number of elements in the list.
	virtual int length() const = 0;
private:

};

template <typename T>
AbstractList<T>::~AbstractList()
{}