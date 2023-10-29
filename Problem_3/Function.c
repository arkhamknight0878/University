#include<stdio.h>
#include"math.h"
#include"Function.h"

bool Is_Prime(unsigned long long int x)
{
	if (x % 2 == 0)
		return false;

	for (unsigned int n1 = 3; n1 < sqrt((double)x) + 1; n1 += 2)
	{
		if (x % n1 == 0)
		{
			return false;
		}
	}

	return true;
}