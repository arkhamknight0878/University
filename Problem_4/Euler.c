#include"Euler.h"
#include"Function.h"

unsigned long long Problem_4(unsigned long long MaxPol_)
{
	unsigned long long MaxPol = MaxPol_;
	unsigned long long Mult = 0;
	for (unsigned long long m1 = 100; m1 < 1000; m1++)
	{
		for (unsigned long long m2 = 100; m2 < 1000; m2++)
		{
			if (Is_Polin(m1 * m2) == 1)
			{
				Mult = m1 * m2;
				if (Mult > MaxPol)
					MaxPol = Mult;
			}
		}
	}

	return MaxPol;
}