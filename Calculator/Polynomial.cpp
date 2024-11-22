#include "Polynomial.h"
#include "Function.h"

Polynomial::Polynomial()
{
	pow = 0;
	arr = nullptr;

	name = new char[2];
	strspy(name, "a");
	
}

Polynomial::Polynomial(size_t numerator_)
{
	pow = numerator_;

	arr = new double[pow];

	for (size_t i = 0; i < pow; ++i)
		arr[i] = i + 1;
}
