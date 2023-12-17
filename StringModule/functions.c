#include "functions.h"

unsigned int my_strlen(const char* StrSrc_)
{
	unsigned int length = 0;

	if (!StrSrc_)
		return NULL;

	for (; StrSrc_[length] != '\0'; length++);

	return length;
}

char* str_mirror(char* StrReult_, const char* Str_)
{
	unsigned int length = my_strlen(Str_);
	Str_ += length - 1;

	while (*Str_)
	{
		*StrReult_ = *Str_;
		StrReult_++;
		Str_--;
	}

	*StrReult_ = '\0';

	return StrReult_;
}