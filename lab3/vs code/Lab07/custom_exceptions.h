#pragma once
#include <exception>

/*Custom exception for when the list is full and the user attempts to add an item to it*/
class ListFull : public std::exception {
public:
	const char* what() const throw()
	{
		return "The list is full, cannot add an item.";
	}
};

/*Custom exception for when the list is empty and the user attempts to remove an item from it*/
class ListEmpty : public std::exception {
public:
	const char* what() const throw()
	{
		return "The list is empty, cannot remove an item.";
	}
};

/*Custom exception for when a value is not found in the list*/
class NotFound : public std::exception {
public:
	const char* what() const throw()
	{
		return "The value wasn't found in the ordered list.";
	}
};