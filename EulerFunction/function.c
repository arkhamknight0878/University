#include "function.h"

bool is_relatively_prime(unsigned long long number_, unsigned long long range_)
{
	if (number_ % 2 == 0 && range_ % 2 == 0)
		return false;

	for (int i = 3; i < range_; i += 2)
		if (number_ % i == 0 && range_ % i == 0)
			return false;

	return true;
}

unsigned int euler_function(unsigned long long range_)
{
	unsigned int count = 0;

	if (range_ == 1)
		return 1;

	for (unsigned long long i = 1; i < range_; i++)
	{
		if (is_relatively_prime(i, range_) == true)
			count++;
	}

	return count;
}