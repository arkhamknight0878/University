#include <stdio.h>
#include"functions.h"

int main()
{
	char mirror_str[25];
	unsigned int length = 0;

	str_mirror(mirror_str, "Six_and_xiS");

	printf("%s", mirror_str);

	return 0;
}