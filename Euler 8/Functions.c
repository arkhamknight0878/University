#include "Functions.h"

#include<stdio.h>

unsigned long long Euler(char* number_, size_t size_, size_t mult_amount_)
{
	if (number_ == NULL)
		return NULL;

	if (mult_amount_ > size_)
	{
		printf("Muliplyer Amount is BIGGER than size of number");
		return 1;
	}

	unsigned long long res = 0;
	size_t delta = mult_amount_;

	for (size_t i = 0; i < size_ - mult_amount_; i++)
	{
		unsigned long long mult = 1;

		for (size_t j = i; j < delta; j++)
			mult *= number_[j] - '0';

		delta++;

		if (mult > res)
			res = mult;
	}

	return res;
}