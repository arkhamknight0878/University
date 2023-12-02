#include <string.h>
#include"mystring.h"

int main()
{
	char sourse[] = "Hello From Night";
	char dest[100] = "Night";
	int res = 0;

	my_strcpy(dest, sourse);
	my_strcat(dest, "City");
	printf("String is = %s\n", dest);

	res = my_strcmp("City1", "City1");
	printf("my_strcmp returned %d\n", res);

	printf("%s", strstr("Big Red Fox", "Red"));

	return 0;
}