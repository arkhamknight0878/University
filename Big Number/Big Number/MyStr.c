#include "MyStr.h"

bool IsIntString(digit* str_)
{
	while (*str_)
	{
		if (*str_ < '0' || *str_ > '9')
			return false;
		str_++;
	}

	return true;
}
