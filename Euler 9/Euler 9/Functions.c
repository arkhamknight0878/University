#include "Functions.h"

#include <math.h>
#include <stdio.h>

size_t Euler9(size_t el_sum_)
{
	for (size_t a = 0; a < el_sum_; a++)
	{
		for (size_t b = 0; b < a; b++)
		{
			double c = sqrt(pow((double)a, 2) + pow((double)b, 2));

			if ((a + b + c) == el_sum_)
				return (size_t)(a * b * c);
		}
	}
}