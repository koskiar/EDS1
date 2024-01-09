#include "BST.h"
#include <iostream>

template <class T>
Node<T>::Node(T* inVal) {
	data = inVal;
	left = nullptr;
	right = nullptr;
}

/*Constructor and Destructor*/
template <class T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	EmptyTree(root);
}

template <class T>
void BinaryTree<T>::EmptyTree() { //this is what the user will call to empty the tree
	EmptyTree(root);
	root = nullptr;
}

template <class T>
void BinaryTree<T>::EmptyTree(Node<T>* toEmpty) { //this is the actual recursive function that empties the tree
	if (toEmpty == nullptr) {
		return;
	}
	else {
		EmptyTree(toEmpty->left);
		EmptyTree(toEmpty->right);

		delete toEmpty;
		return;
	}
}

template <class T>
void BinaryTree<T>::Insert(T* inVal) {
	if (root == nullptr) {
		root = new Node<T>(inVal);
	}
	else {
		Node<T>* temp = root;
		while ((*inVal < *temp->data && temp->left != nullptr) || (*inVal > *temp->data && temp->right != nullptr)) {
			if (*inVal < *temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		if (*inVal < *temp->data) {
			temp->left = new Node<T>(inVal);
			Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
		}
		else if (*inVal > *temp->data) {
			temp->right = new Node<T>(inVal);
			Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
		}

		else { //if a value is equal to another in the tree, an error is thrown
			DuplicateValue ex;
			throw ex;
		}
	}
}

template <class T>
Node<T>* BinaryTree<T>::Find(T findVal) { //here findVal will have data type string (word) that you want to search for in the tree
	if (root == nullptr) {
		TreeIsEmpty ex;
		throw ex;
	}
	Node<T>* temp = root;
	while (temp != nullptr) {
		if (*temp->data == findVal) {
			return temp;
		}
		if (*temp->data > findVal) {
			temp = temp->left;
		}
		else if (*temp->data < findVal) { //prolly can just use else, since all the other cases are taken care of
			temp = temp->right;
		}
	}
	return nullptr; //if not found
}

template <class T>
Node<T>* BinaryTree<T>::Remove(T findVal) { //cases: empty tree, not found, root with no child, root with 1 child, root with 2 children, leaf, middle node with 1 child, middle node with 2 children

	if (Find(findVal) == nullptr) { //deals with empty tree and not found cases, if this doesnt throw an error then the value to remove was found so now we can tackle other cases
		return nullptr; //if not found
	}

	if (*root->data == findVal) { //deal with case: removing the root
		if (root->left == nullptr && root->right == nullptr) { //Deals with root with no child
			Node<T>* retNode = root;
			delete(root);
			root = nullptr;
			return retNode;
		}
		else if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr)) { //Deals with root with 1 child
			Node<T>* toDelete = root;
			if (root->left != nullptr) { //root has only left child
				root = root->left;
			}
			else { //root has only right child
				root = root->right;
			}
			Node<T>* retNode = toDelete;
			delete toDelete;
			return retNode;
		}
		else { //Deals with root with 2 children
			T* replaceVal = FindSmallestLarger(root->right); //the way we are doing this: we move the right node of the node we are looking to remove, then we continue to move left from that right node till we reach its left-most leaf node (this left-most leaf will be the smallest value (among the right nodes of the node we plan to remove) which is still larger than the node we want to remove)
			Node<T>* removeVal = Remove(*replaceVal); //this essentially is removing a leaf node
			Node<T>* retNode = root;
			root = removeVal;
			Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof. Do I really need to balance while removing a root with 2 children. Removing roots with 0 or 1 child never requires balancing.
			return retNode;
		}
	}

	Node<T>* temp = root;
	while ((temp->left != nullptr && *temp->left->data != findVal) || (temp->right != nullptr && *temp->right->data != findVal)) { //finds the parent node of the node we are looking for
		if (*temp->data < findVal && *temp->right->data != findVal) {
			temp = temp->right;
		}
		else if (*temp->data > findVal && *temp->left->data != findVal) {
			temp = temp->left;
		}
		else {
			break;
		}
	}

	if ((temp->left != nullptr && temp->left->right == nullptr && temp->left->left == nullptr) ||
		(temp->right != nullptr && temp->right->right == nullptr && temp->right->left == nullptr)) { //Deals with leaf case

		if (temp->left != nullptr && *temp->left->data == findVal) {
			Node<T>* retNode = temp->left;
			delete(temp->left);
			temp->left = nullptr;
			Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
			return retNode;
		}
		else if (temp->right != nullptr && *temp->right->data == findVal) {
			Node<T>* retNode = temp->right;
			delete(temp->right);
			temp->right = nullptr;
			Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
			return retNode;
		}
	}
	else if ((temp->left != nullptr && temp->left->right == nullptr && temp->left->left != nullptr) || (temp->left != nullptr && temp->left->right != nullptr && temp->left->left == nullptr) || (temp->right != nullptr && temp->right->right == nullptr && temp->right->left != nullptr) || (temp->right != nullptr && temp->right->right != nullptr && temp->right->left == nullptr))
	{ //Deals with middle node with 1 child

		Node<T>* toDelete;
		if (findVal < *temp->data) {
			toDelete = temp->left;
			if (toDelete->left != nullptr) { //in this case we know that the middle node we are looking for has only 1 child, which will either be to the left or to the right of that middle node
				temp->left = toDelete->left;
				Node<T>* retNode = toDelete;
				delete toDelete;
				Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
				return retNode;
			}
			else {
				temp->left = toDelete->right;
				Node<T>* retNode = toDelete;
				delete toDelete;
				Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
				return retNode;
			}
		}
		else {
			toDelete = temp->right;
			if (toDelete->left != nullptr) {
				temp->right = toDelete->left;
				Node<T>* retNode = toDelete;
				delete toDelete;
				Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
				return retNode;
			}
			else {
				temp->right = toDelete->right;
				Node<T>* retNode = toDelete;
				delete toDelete;
				Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
				return retNode;
			}
		}
	}
	else { //deals with removing a middle node with 2 children
		Node<T>* toDelete;
		if (findVal < *temp->data) {
			toDelete = temp->left;
		}
		else {
			toDelete = temp->right;
		}
		T* replaceVal = FindSmallestLarger(toDelete->right); //the way we are doing this: we move the right node of the node we are looking to remove, then we continue to move left from that right node till we reach its left-most leaf node (this left-most leaf will be the smallest value (among the right nodes of the node we plan to remove) which is still larger than the node we want to remove)
		Node<T>* removeVal = Remove(*replaceVal); //this essentially is removing a leaf node
		Node<T>* retNode = toDelete;
		toDelete = removeVal;
		Height(root, nullptr); //I think this is all we need for balancing. Just confirm with prof
		return retNode;
	}
}

template <class T>
T* BinaryTree<T>::FindSmallestLarger(Node<T>* temp) {
	while (temp->left != nullptr) {
		temp = temp->left;
	}
	return temp->data;
}

template <class T>
int BinaryTree<T>::Size(Node<T>* findSize) {
	if (findSize == nullptr) {
		return 0;
	}
	else {
		return 1 + Size(findSize->left) + Size(findSize->right);
	}
}

template <class T>
T** BinaryTree<T>::GetAllAscending() { //user calls this
	T** arr = new T * [Size(root)];
	int* index = new int(0);

	GetAllAscending(root, arr, index);

	delete index;
	return arr;
}

template <class T>
void BinaryTree<T>::GetAllAscending(Node<T>* n, T** arr, int* index) { //recursive function that actually sorts data and adds it to the array
	if (n == nullptr) {
		return;
	}

	GetAllAscending(n->left, arr, index);
	arr[*index] = n->data;
	*index++;

	GetAllAscending(n->right, arr, index);
	return;
}

template <class T>
T** BinaryTree<T>::GetAllDescending() { //user calls this
	T** arr = new T * [Size(root)];
	int* index = new int(0);

	GetAllDescending(root, arr, index);

	delete index;
	return arr;
}

template <class T>
void BinaryTree<T>::GetAllDescending(Node<T>* n, T** arr, int* index) { //recursive function that actually sorts data and adds it to the array
	if (n == nullptr) {
		return;
	}

	GetAllDescending(n->right, arr, index);
	arr[*index] = n->data;
	*index++;

	GetAllAscending(n->left, arr, index);
	return;
}

template <class T>
int BinaryTree<T>::Height(Node<T>* current, Node<T>* parent) {
	if (current == nullptr) {
		return 0;
	}
	int L = Height(current->left, current);
	int R = Height(current->right, current);

	//call the 4 rotates if neccessary to balance the tree from the bottom up
	if (R > L + 1) {
		if (Height(current->right->left, current->right) > Height(current->right->right, current->right)) {
			RotateRightLeft(parent, current); //double check if this is the right command
		}
		else {
			RotateLeft(parent, current);
		}
		R--; //pretty sure these updates to R and L values need to happen as well
		L++;
	}
	else if (L > R + 1) {
		if (Height(current->left->right, current->left) > Height(current->left->left, current->left)) {
			RotateLeftRight(parent, current);
		}
		else {
			RotateRight(parent, current);
		}
		L--; //pretty sure these updates to R and L values need to happen as well
		R++;
	}

	if (L > R) {
		return L + 1;
	}
	return R + 1;
}

template <class T>
void BinaryTree<T>::RotateLeft(Node<T>* parent, Node<T>* pivot) {
	if (parent == nullptr) {//if the pivot is the root (it doesn't have a parent)
		root = pivot->right;
		pivot->right = pivot->right->left;
		root->left = pivot;
	}
	else if (parent->data > pivot->data) { //if the parent data is the bigger than the pivot data
		parent->left = pivot->right;
		pivot->right = pivot->right->left;
		parent->left->left = pivot;
	}
	else { //if the parent data is the smaller than the pivot data
		parent->right = pivot->right;
		pivot->right = pivot->right->left;
		parent->right->left = pivot;
	}
}

template <class T>
void BinaryTree<T>::RotateRight(Node<T>* parent, Node<T>* pivot) {
	if (parent == nullptr) {//if the pivot is the root (it doesn't have a parent)
		root = root->left;
		pivot->left = pivot->left->right;
		root->right = pivot;
	}
	else if (parent->data > pivot->data) { //this basically means the parent node is towards the top right of the pivot node, or worded differently: the pivot node is the left child of the parent node
		parent->left = parent->left->left;
		pivot->left = pivot->left->right;
		parent->left->right = pivot;
	}
	else { //this basically means the parent node is towards the top left of the pivot node, or worded differently: the pivot node is the right child of the parent node
		parent->right = parent->right->left;
		pivot->left = pivot->left->right;
		parent->right->right = pivot;
	}
}

template <class T>
void BinaryTree<T>::RotateRightLeft(Node<T>* parent, Node<T>* pivot) {
	if (parent == nullptr) {//if the pivot is the root (it doesn't have a parent)
		root = pivot->right->left;
		pivot->right->left = root->right;
		root->right = pivot->right;
		pivot->right = root->left;
		root->left = pivot;
	}
	else if (parent->data > pivot->data) { //this basically means the parent node is towards the top right of the pivot node, or worded differently: the pivot node is the left child of the parent node
		parent->left = pivot->right->left;
		pivot->right->left = parent->left->right;
		parent->left->right = pivot->right;
		pivot->right = parent->left->left;
		parent->left->left = pivot;
	}
	else { //this basically means the parent node is towards the top left of the pivot node, or worded differently: the pivot node is the right child of the parent node
		parent->right = pivot->right->left;
		pivot->right->left = parent->right->right;
		parent->right->right = pivot->right;
		pivot->right = parent->right->left;
		parent->right->left = pivot;
	}
}

template <class T>
void BinaryTree<T>::RotateLeftRight(Node<T>* parent, Node<T>* pivot) {
	if (parent == nullptr) {//if the pivot is the root (it doesn't have a parent)
		root = pivot->left->right;
		pivot->left->right = root->left;
		root->left = pivot->left;
		pivot->left = root->right;
		root->right = pivot;
	}
	else if (parent->data > pivot->data) { //this basically means the parent node is towards the top right of the pivot node, or worded differently: the pivot node is the left child of the parent node
		parent->left = pivot->left->right;
		pivot->left->right = parent->left->left;
		parent->left->left = pivot->left;
		pivot->left = parent->left->right;
		parent->left->right = pivot;
	}
	else { //this basically means the parent node is towards the top left of the pivot node, or worded differently: the pivot node is the right child of the parent node
		parent->right = pivot->left->right;
		pivot->left->right = parent->right->left;
		parent->right->left = pivot->left;
		pivot->left = parent->right->right;
		parent->right->right = pivot;
	}
}