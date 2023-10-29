#include<stdio.h>
#include"Eyler.h"

unsigned long long Problem_3(const unsigned long long number_)
{
	unsigned long long number = number_;
	unsigned long long n2 = 2;

	while (number % 2 == 0)
		number /= 2;
	n2++;

	while (n2 < number)
	{
		if (number % n2 == 0)
		{
			if (Is_Prime(n2) == 1)
			{
				while (number % n2 == 0)
					number /= n2;
			}
		}
		n2 += 2;
	}
	return number;
}