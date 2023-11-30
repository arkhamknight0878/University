#include "euler.h"
#include "functions.h"

unsigned long long Max_Divisor(unsigned long long number_)
{
	unsigned long long Max = 0;
	unsigned long long Divisor = 2;

	if (number_ % 2 == 0)
		return Divisor;

	Divisor++;

	while (Divisor < number_)
	{
		if ((number_ % Divisor == 0) && (Is_Prime(Divisor) == 1))
		{
			while (number_ % Divisor == 0)
				number_ /= Divisor;
		}
		Divisor += 2;
	}

	return number_;
}