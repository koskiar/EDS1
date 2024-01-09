#include "Auto.h"

void Auto::setStorage(int num)
{
	storage = num;
};
void Auto::autogen()
{
	storage = rand() %MAX_size;
}
