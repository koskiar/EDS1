#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H
#include <exception>

/*Custom exception for when the list is empty and the user attempts to remove an item or look for an item*/
class EmptyList : public std::exception {
public:
	const char* what() const throw() { return "The list is empty, cannot remove an item."; }
};
/*Custom exception for when the user attempts to see an item at a location that is past the end of list*/
class EndOfList : public std::exception {
public:
	const char* what() const throw() { return "The given index is past the end of the list."; }
};
#endif