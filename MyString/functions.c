#include"functions.h"
#include<string.h>

char* my_strcpy(char *StrDest_, const char *StrSrc_)
{
	if (!StrDest_ || !StrSrc_)
		return NULL;

	while (*StrSrc_)
	{
		*StrDest_ = *StrSrc_;
		StrDest_++;
		StrSrc_++;
	}

	*StrDest_ = '\0';

	return StrDest_;
}

unsigned int my_strlen(const char* StrSrc_)
{
	unsigned int StrLen = 0;

	if (!StrSrc_)
		return 0;

	for (; StrSrc_[StrLen] != '\0'; ++StrLen);

	return StrLen;
}

char* my_strcat(char* StrDest_, const char* StrSrc_)
{
	if (!StrDest_ || !StrSrc_)
		return NULL;

	for (; *StrDest_ != '\0'; StrDest_++);

	while (*StrSrc_)
	{
		*StrDest_ = *StrSrc_;
		StrDest_++;
		StrSrc_++;
	}

	*StrDest_ = '\0';

	return StrDest_;
}

int my_strcmp(const char* Str_, const char* StrSearch_)
{
	if (!Str_ || !StrSearch_)
		return NULL;

	while (*StrSearch_)
	{
		if (*Str_ > *StrSearch_)
			return 1;
		else if (*Str_ < *StrSearch_)
			return -1;
		else return 0;

		Str_++;
		StrSearch_++;
	}

	return Str_;
}