#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H
#include "custom_exceptions.h"

template<class T>
class OrderedList { //design choice: list will be ordered in ascending order (smallest to largest)
public:
	/*Constructor*/
	OrderedList();

	/*Destructor*/
	~OrderedList();

	/*Required Functions*/
	virtual void AddItem(T* inval);
	virtual T* RemoveItem(T* key); //Design choice: throws NotFound exception when value isn't found in the list
	bool IsEmpty();
	bool IsFull();
	void MakeEmpty();

	/*Useful Getter Functions*/
	int get_num_items() { return num_items; }
	int get_op_count() { return op_count; }

protected:
	const int MAX_SIZE = 10; //needs to be changed to 50 and 10 while doing task 4
	T** data = new T * [MAX_SIZE]; //array of pointer elements
	int num_items = 0; //holds the number of items currently in the list
	int op_count = 0; //counts number of operations
};
#endif