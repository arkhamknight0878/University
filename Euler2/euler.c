#include"euler.h"
#include"functions.h"

unsigned long long Sum_of_EvenFib(const unsigned long long MaxFib_)
{
	unsigned long long Sum = 0;
	unsigned long long Fib = 0;
	unsigned long long Frst = 0;
	unsigned long long Scnd = 1;

	while (Fib <= MaxFib_)
	{
		Fib = Frst + Scnd;
		Frst = Scnd;
		Scnd = Fib;

		if (Is_Even(Fib) == 1)
			Sum += Fib;
	}

	return Sum;
}