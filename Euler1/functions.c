#include"functions.h"

bool Is_Mult35(unsigned long long number_)
{
	if (number_ % 3 == 0 || number_ % 5 == 0)
		return true;
	else return false;
}