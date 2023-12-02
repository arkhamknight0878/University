#include"mystring.h"


//STRCMP, STRSTR

unsigned int my_strlen(const char* Str_)
{
	if (!Str_)
		return 0;

	unsigned int length = 0;
	for (; Str_[length] != '\0'; ++length);

	return length;
}

char* my_strcpy(char* StrDest_, const char* StrSrc_)
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

int my_strcmp(const char* Str1_, const char* Str2_)
{
	if (!Str1_ || !Str2_)
		return NULL;

	while (*Str2_)
	{
		if (*Str1_ > *Str2_)
			return *Str1_ - *Str2_;

		if (*Str1_ < *Str2_)
			return *Str1_ - *Str2_;

		Str1_++;
		Str2_++;
	}

	return 0;
}

char* my_strstr(const char* Str_, const char* StrSearch_)
{
	char* res;
	
	if (!Str_ || !StrSearch_)
		return NULL;

	while (*Str_)
	{
		if (*Str_ == *StrSearch_)
		{
			char* tmpStr = Str_;
			char* tmpStrSearch = StrSearch_;

			while (*tmpStr)
			{
				if (*tmpStr != *tmpStrSearch)
					break;

				*res = *tmpStr;

				res++;
				tmpStr++;
				tmpStrSearch++;
			}
		}
		
		Str_++;
	}

	return res;
}