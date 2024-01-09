#pragma once
#include "OrderedList.h"

template<class T>
class OrderedList_Task2 :public OrderedList<T> {
public:
	/*Constructor*/
	OrderedList_Task2() :OrderedList<T>() {}

	/*Required Functions*/
	void AddItem(T* inval);
	T* RemoveItem(T* key); //Design choice: throws NotFound exception when value isn't found in the list
	bool IsEmpty();
	bool IsFull();
	void MakeEmpty();
	/*Useful Getter Functions*/
	int get_num_items() { return num_items; }
	int get_op_count() { return op_count; }

private:
	const int END_INDEX = MAX_SIZE;
	const int MAX_SIZE = 10; //needs to be changed to 50 and 10 while doing task 4
	T** data = new T * [MAX_SIZE]; //array of pointer elements
	int num_items = 0; //holds the number of items currently in the list
	int op_count = 0; //counts number of operations
};