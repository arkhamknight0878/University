#include"euler.h"
#include"functions.h"

unsigned long long Sum_of_Mult(unsigned long long range_)
{
	unsigned long long Sum = 0;
	for (int i = 1; i < range_; i++)
	{
		if (Is_Mult35(i) == 1)
			Sum += i;
	}

	return Sum;
}