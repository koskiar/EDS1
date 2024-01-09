#include "OrderedList_Task2.h"

template <class T>
void OrderedList_Task2<T>::AddItem(T* inval) {
	if (!IsFull()) {
		op_count++;
		if (num_items == 0) {
			data[END_INDEX] = inval;
			num_items++;
			return;
		}
		for (int i = END_INDEX;  i > 0; i--) {
			op_count++;
			if (*inval < *data[i]) {
				for (int j = num_items; j > i; j--) {
					data[j] = data[j - 1];
					op_count++;
				}
				data[i] = inval;
				num_items++;
				return;
			}
		}
		data[num_items] = inval;
		num_items++;
		return;
	}
	else {
		ListFull Exception; //custom exception
		throw Exception;
	}
}

template <class T>
T* OrderedList_Task2<T>::RemoveItem(T* key) {
	if (!IsEmpty()) {
		for (int i = 0; i < num_items; i++) {
			op_count++;
			if (*key == *data[i]) {
				T* temp = data[i];
				for (int j = i; j < num_items - 1; j++) {
					data[j] = data[j + 1];
					op_count++;
				}
				num_items--;
				return temp;
			}
		}
		/*If we don't return from the above loop, then value wasn't found in the list*/
		NotFound Exception;
		throw Exception; //Design choice: throwing NotFound exception when value isn't found in the list
	}
	else {
		ListEmpty Exception; //custom exception
		throw Exception;
	}
}
template <class T>
bool OrderedList_Task2<T>::IsEmpty() {
	op_count++;
	return num_items == 0;
}

template <class T>
bool OrderedList_Task2<T>::IsFull() {
	op_count++;
	return num_items == MAX_SIZE;
}

template <class T>
void OrderedList_Task2<T>::MakeEmpty() {
	for (int i = 0; i < MAX_SIZE; i++) {
		delete(data[i]);
	}
}
