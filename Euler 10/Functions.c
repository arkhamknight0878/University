#include "Functions.h"

#include <stdlib.h>

size_t EratosthenesSieve_Sum(size_t max_number_)
{
	bool* prime_arr = (bool*)calloc(max_number_, sizeof(bool));
	if (prime_arr == NULL)
		return NULL;

	for (size_t i = 2; i < max_number_; i++)
		prime_arr[i] = true;

	for (size_t i = 2; i * i < max_number_; i++)
	{
		if (prime_arr[i] == true)
		{
			for (size_t j = i * i; j < max_number_; j += i)
			{
				prime_arr[j] = false;
			}
		}
	}

	size_t sum = 0;
	for (size_t i = 2; i < max_number_; i++)
	{
		if (prime_arr[i] == true)
			sum += i;
	}

	return sum;
}
