#include "LinkedList.h"
#include <stdlib.h>
#include <iostream>
#include <string>

template <class T>
Node<T>::Node(T* inVal) {
	data = inVal;
	next = nullptr;
}


template <class T>
List<T>::List() {
	head = nullptr;
	length = 0;
	P_next = nullptr;
	P_prev = nullptr;
}

template <class T>
List<T>::~List() {
	Node<T>* temp = head;
	Node<T>* delPtr;
	while (temp != nullptr) {
		delPtr = temp;
		temp = temp->next;
		delete delPtr;
	}
}

template <class T>
void List<T>::AddItem(T* inVal) {
	if (head == nullptr) { //if we are inserting integers to an empty list
		head = new Node<T>(inVal);
		length++;
		return;
	}
	if (*inVal < *head->data) { //if we are inserting integers to the front of the list
		Node<T>* h = new Node<T>(inVal);
		h->next = head;
		head = h;
		length++;
	}
	else { //if we are inserting integers to somewhere in the middle of the list, or to the back (end) of the list
		Node<T>* temp = head;
		while (temp->next != nullptr && *temp->next->data < *inVal) {
			temp = temp->next;
		}
		Node<T>* newNode = new Node<T>(inVal);
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
	}
}

template <class T>
T* List<T>::GetItem(int key) { //key is the SKU, returns a nullptr if not found
	if (IsEmpty()) {
		EmptyList ex; //custom exception
		throw ex;
	}

	if (*head->data == key) { //handling special case: when the first element in the list is the key to be returned
		Node<T>* temp = head;
		head = head->next;
		T* retVal = temp->data;
		delete temp;
		length--;
		return retVal;
	}

	Node<T>* temp = head;
	while (temp->next != nullptr && !(*temp->next->data == key)) {
		temp = temp->next;
	}
	if (temp->next == nullptr) { //if the data was not found
		return nullptr;
	}
	Node<T>* retPtr = temp->next;
	temp->next = temp->next->next;
	T* retVal = retPtr->data;
	delete retPtr;
	length--;
	return retVal;
}

template <class T>
bool List<T>::IsInList(int key) {
	if (IsEmpty()) {
		EmptyList ex; //custom exception
		throw ex;
	}
	Node<T>* temp = head;
	while (temp != nullptr) {
		if (*temp->data == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template <class T>
bool List<T>::IsEmpty() {
	return length == 0;
}

template <class T>
int List<T>::Size() {
	return length;
}

template <class T>
T* List<T>::SeeNext() { //uses P_next
	if (IsEmpty()) {
		EmptyList ex; //custom exception
		throw ex;
	}

	if (P_next == nullptr) {
		P_next = head;
	}
	else {
		P_next = P_next->next;
	}

	if (P_next == nullptr) { //reached the end of list
		return nullptr;
	}
	return P_next->data;
}

template <class T>
T* List<T>::SeePrev() { //uses P_prev i think, dont know how to do this
	if (IsEmpty()) {
		EmptyList ex; //custom exception
		throw ex;
	}
	return nullptr; //dont know what to do
}

template <class T>
T* List<T>::SeeAt(int index) {
	if (IsEmpty()) {
		EmptyList ex; //custom exception
		throw ex;
	}
	if (index >= length) {
		EndOfList ex;
		throw ex;
	}

	Node<T>* temp = head;
	if (index == 0) {
		P_next = temp;
		return temp->data;
	}
	for (int i = 1; i <= index; i++) {
		temp = temp->next;
	}
	P_next = temp;
	return temp->data;
}

template <class T>
T* List<T>::DisplayASCII() { //cannot be called twice in a row for some reason
	if (IsEmpty()) {
		EmptyList ex;
		throw ex;
	}
	int size = Size();
	T* current;

	for (int i = 0; i < size; i++) {
		if (!(i == 0)) {
			std::cout << "|" << std::endl; //doesn't actually print the spaces for this statement or the other one
			std::cout << "v" << std::endl;
		}
		current = SeeNext();
		current->Display();
	}
	current = nullptr;
}

template <class T>
void List<T>::Reset() {
	P_next = nullptr;
}