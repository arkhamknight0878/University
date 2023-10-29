#include"Eyler.h"

unsigned long long Problem_2(const unsigned int number_)
{
	unsigned long long sum = 0;
	unsigned int n1 = 1;
	unsigned int n2 = 2;
	unsigned int i = 0;
	while (n2 < number_)
	{
		if (n2 % 2 == 0)
			sum = sum + n2;

		i = n2;
		n2 = n2 + n1;
		if (n2 >= number_)
			break;
		n1 = i;
	}
	return sum;

}