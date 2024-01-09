#pragma once
#include "custom_exceptions.h"

template <class T>
class Node {
public:
	T* data;
	Node* next;
	//add constructor to populate data = inval, and next = nullptr
	Node(T* inVal);
};
template <class T>
class List {
private:
	Node<T>* head;
	int length;
	Node<T>* P_next; //used for the GetNext() function
	Node<T>* P_prev; //maybe needed for SeePrev()

public:
	/*Constructor and Destructor*/
	List();
	~List();
	/*Required functions*/
	void AddItem(T* inVal);
	T* GetItem(int key); //key is the SKU, returns a nullptr if not found
	bool IsInList(int key); //key is the SKU
	bool IsEmpty();
	int Size(); //returns length
	T* SeeNext(); //uses P_next
	T* SeePrev(); //uses P_prev?? i think?
	T* SeeAt(int index); //list index goes from 0 to length-1
	T* DisplayASCII();
	void Reset();
};