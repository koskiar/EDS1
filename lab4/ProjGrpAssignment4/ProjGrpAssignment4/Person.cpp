#include "Person.h"
#include <iostream>
#pragma warning(disable : 4996)

Person::Person(std::string fn, std::string ln, int mn, int bd, int gpa) {
	FN = fn;
	LN = ln;
	MN = mn;
	BD = bd;
	GPA = gpa;
}

/*Required Operator Overloads*/
bool operator<(const Person& p1, const Person& p2) { return p1.MN < p2.MN; }
bool operator<(const Person& p, const int mn) { return p.MN < mn; }

bool operator>(const Person& p1, const Person& p2) { return p1.MN > p2.MN; }
bool operator>(const Person& p, const int mn) { return p.MN > mn; }

bool operator==(const Person& p1, const Person& p2) { return p1.MN == p2.MN; }
bool operator==(const Person& p, const int mn) { return p.MN == mn; }

void Person::Display() {
	std::cout << "____________________" << std::endl;
	std::cout << "Name: " + GetName() << std::endl;
	std::cout << "MNumber: M" << GetMNumber() << std::endl;
	std::cout << "Age: " << GetAge() << std::endl;
	std::cout << "GPA: " << GetGPA() << std::endl;
	std::cout << "____________________" << std::endl;
}