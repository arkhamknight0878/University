#include "functions.h"
#include <math.h>

bool Is_Prime(unsigned long long divisor_)
{
	if (divisor_ % 2 == 0)
		return false;

	for (int i = 3; i < divisor_; i += 2)
	{
		if (divisor_ % i == 0)
			return false;
	}

	return true;
}