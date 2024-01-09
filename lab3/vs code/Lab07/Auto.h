#pragma once
#include <iostream>
#include <random>
class Auto
{
public:
	/*getter*/
	int getstorage() { return storage; }

	/*setter*/
	void setStorage(int num);

	/*functions*/
	void autogen();

private:

	int storage = 0;
	protected:
	const int MAX_size = 101;
};