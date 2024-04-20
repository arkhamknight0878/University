#include "Function.h"

#include <stdlib.h>

unsigned long long Sum_of_Mult35(unsigned long long upper_bound_)
{
	unsigned long long sum = 0;

	for (size_t i = 3; i < upper_bound_; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	return sum;
}