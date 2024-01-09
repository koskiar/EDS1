#pragma once
#include "custom_exceptions.h"

template <class T>
class Node {
public:
	T* data;
	Node* left;
	Node* right;

	//add constructor
	Node(T* inVal);
};

template <class T>
class BinaryTree {

public:
	/*Constructor and Destructor*/
	BinaryTree();
	~BinaryTree();

	/*Required Functions*/
	void Insert(T* inVal);
	Node<T>* Find(T findVal); //here findVal will have data type (string, since we are looking for a word) that you want to search for in the tree
	Node<T>* Remove(T findVal); //here findVal will have data type (string, since we are looking for a word) that you want to remove from the tree
	int Size(Node<T>* findSize); //finds the number of nodes in the BST
	T** GetAllAscending(); //user calls this function to get an array with BST data in ascending order, then this function calls the recursive GetAllAscending function
	T** GetAllDescending(); //user calls this function to get an array with BST data in descending order, then this function calls the recursive GetAllDescending function
	void EmptyTree(); //user calls this function to delete all nodes in the BST, then this function calls the recursive EmptyTree function

private:

	Node<T>* root;

	/*Required Functions*/
	void GetAllAscending(Node<T>* n, T** arr, int* index); //this the the recursive function that actually fills an array with the data in ascending order
	void GetAllDescending(Node<T>* n, T** arr, int* index); //this the the recursive function that actually fills an array with the data in descending order
	void EmptyTree(Node<T>* toEmpty); //this the the recursive function that actually deletes all nodes in the BST

	T* FindSmallestLarger(Node<T>* temp); //used to help remove a root/middle node with 2 children. This finds the smallest value in the tree which is still 
	//larger than the node we are looking to remove

	int Height(Node<T>* current, Node<T>* parent); //This Height function will do the tree balacing for us, call it inside the Insert() and Remove() functions to make sure tree remains 
	//balanced after every insert and remove, passing the root as the first parameter and nullptr as the second parameter (since root doesn't have a parent)

	void RotateLeft(Node<T>* parent, Node<T>* pivot); //Used when unbalanced tree looks like:   1
	//										 \
													  //									      2
													  //									       \
													  //                                            3
													  //the pivot would be the node with value 1, the parent is another node above 1 (in case of no parents of 1, 1 is the root)

	void RotateRight(Node<T>* parent, Node<T>* pivot); //Used when unbalanced tree looks like:  3
	//									   /	
	//									  2
	//									 /
	//									1
	//the pivot would be the node with value 3, the parent is another node above 3 (in case of no parents of 3, 3 is the root)

	void RotateRightLeft(Node<T>* parent, Node<T>* pivot); //Used when unbalanced tree looks like: 1
	//                                       \
														   //										 3
														   //										/
														   //									   2

	void RotateLeftRight(Node<T>* parent, Node<T>* pivot); //used when unbalanced tree looks like: 3
	//									  /
	//									 1
	//									  \
														   //									   2


};