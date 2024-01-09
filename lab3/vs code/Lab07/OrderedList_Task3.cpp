#include "OrderedList_Task3.h"

template <class T>
void OrderedList_Task3<T>::AddItem(T* inval) {
	if (!IsFull()) {
		op_count++;
		if (num_items == 0) {
			data[0] = inval;
			op_count++;
			num_items++;
			return;
		}
		for (int i = 0; i < num_items; i++) {
			if (*inval < *data[i] && data[i - 1] != nullptr) {
				for (int j = num_items; j > i; j--) {
					data[j] = data[j - 1];
					op_count++;
				}
				data[i] = inval;
				num_items++;
				op_count++;
				return;
			}else if (*inval < *data[i] && data[i - 1] == nullptr) {
				op_count++;
				data[i] = inval;
				num_items++;
				return;
			}
		}
	}else{
		ListFull Exception; //custom exception
		throw Exception;
	}
}
template <class T>
T* OrderedList_Task3<T>::RemoveItem(T* key) {
	if (!IsEmpty()) {
		for (int i = 0; i < num_items; i++) {
			if (*key == *data[i]) {
				op_count++;
				data[i] = nullptr;
				T* temp = data[i];
				num_items--;
				return temp;
			}
		}
		/*If we don't return from the above loop, then value wasn't found in the list*/
		NotFound Exception;
		throw Exception; //Design choice: throwing NotFound exception when value isn't found in the list
	}
	else {
		//ListEmpty Exception; //custom exception
		//throw Exception;
	}
}

template <class T>
bool OrderedList_Task3<T>::IsEmpty() {
	op_count++;
	return num_items == 0;
}

template <class T>
bool OrderedList_Task3<T>::IsFull() {
	op_count++;
	return num_items == MAX_SIZE;
}

template <class T>
void OrderedList_Task3<T>::MakeEmpty() {
	for (int i = 0; i < MAX_SIZE; i++) {
		delete(data[i]);
	}
}