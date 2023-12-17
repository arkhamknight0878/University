#include <stdio.h>
#include "functions.h"

int main()
{
	char string[80];
	int result = my_strcmp("hello", "Hello");

	my_strcpy(string, "Hello world from ");
	my_strcat(string, "NightCity!");

	printf("String = %s\n", string);
	printf("String Length = %u\n", my_strlen(string));

	if (result > 0)
		printf("Str1 > Str2");
	else if (result < 0)
		printf("Str1 < Str2");
	else printf("Str1 = Str2");

	return 0;
}