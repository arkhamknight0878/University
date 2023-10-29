#include"Euler.h"
#include"Is_Del.h"

unsigned long long Problem_1(const unsigned long long number_)
{
	unsigned long long n2 = number_;
	unsigned long long Sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (Is_Del(n2))
			Sum += n2;

		n2++;
	}

	return Sum;
}