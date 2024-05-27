#include "MyStr.h"

bool Is_IntArr(digits* str_)
{
	if (str_ == NULL)
		return;

	if (*str_ == '-')
		++str_;

	while (*str_)
	{
		if (*str_ < '0' || *str_ > '9')
			return false;

		++str_;
	}

	return true;
}

size_t StrLen(digits* str_)
{
	if (str_ == NULL)
		return;

	size_t length = 0;

	while (*str_)
	{
		++length;
		++str_;
	}

	return length;
}
