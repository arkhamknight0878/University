#include "functions.h"

bool is_prime(unsigned long long number_)
{
	if (number_ % 2 == 0)
		return false;

	for (int divisor = 3; divisor < sqrt((double)number_); divisor += 2)
	{
		if (number_ % divisor == 0)
			return false;
	}

	return true;
}

unsigned long long n_element(unsigned position_)
{
	if (position_ == 1)
		return 2;

	unsigned long long res = 3;
	int i = 1;

	while (i <= position_)
	{
		if (is_prime(res))
			i++;

		res += 2;
	}

	return res;
}