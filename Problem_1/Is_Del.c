#include"Is_Del.h"
#include<math.h>


bool Is_Del(unsigned long long number)
{
	unsigned long long n1 = number;

	if (n1 % 3 == 0 || n1 % 5 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}