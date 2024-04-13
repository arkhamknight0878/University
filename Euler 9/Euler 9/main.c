#include "Functions.h"

#include <stdio.h>

int main()
{
	size_t max_element = 0;

	printf("Enter Sum of Elements: ");
	scanf_s("%Iu", &max_element);

	size_t res = Euler9(max_element);
	printf("Res = %Iu", res);

	return 0;
}