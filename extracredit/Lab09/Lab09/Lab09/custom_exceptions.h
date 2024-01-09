#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H
#include <exception>

/*Custom exception for when the binary tree is empty and the user attempts to remove an item or look for an item*/
class TreeIsEmpty : public std::exception {
public:
	const char* what() const throw()
	{
		return "The binary tree is empty, cannot find/remove an item.";
	}
};

/*Custom exception for when the user attempts to add an item to a binary tree which already has that item in it*/
class DuplicateValue : public std::exception {
public:
	const char* what() const throw()
	{
		return "The binary tree already has this value, cannot insert it again.";
	}
};
#endif