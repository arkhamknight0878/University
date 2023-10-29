#include "euler.h"

unsigned long long Problem_5(unsigned long long num_)
{
	for (int i = 1; i < 21; i++)
	{
		if (num_ % i == 0)
			continue;
		else
		{
			num_++;
			i = 1;
		}
	}

	return num_;
}
