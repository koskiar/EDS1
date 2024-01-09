#pragma once
#include <string>
#include <iostream>
#include <ctime>

class Person {
public:
	/*Required Constructor*/
	Person(std::string, std::string, int = 0, int = 0, int = 0);

	/*Required Getter Functions*/
	std::string GetName() { return  FN + " " + LN; }
	int GetMNumber() { return MN; }
	int GetAge() { return (2023 - BD); }
	int GetGPA() { return GPA; }
	/*Task 4 display function*/
	void Display();

	/*Required Operator Overloads*/
	friend bool operator<(const Person&, const Person&);
	friend bool operator<(const Person&, const int);

	friend bool operator>(const Person&, const Person&);
	friend bool operator>(const Person&, const int);

	friend bool operator==(const Person&, const Person&);
	friend bool operator==(const Person&, const int);

private:
	std::string FN; //First Name
	std::string LN; //Last Name
	int MN; // Mnumber
	int BD; // Birthday
	int GPA; // GPA
};
