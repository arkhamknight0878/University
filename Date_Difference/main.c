#include<stdlib.h>
#include"functions.h"
#include"Date.h"

int main()
{
	Date* past = calloc(5, sizeof(unsigned));
	Date* last = calloc(5, sizeof(unsigned));
	Date* diff = calloc(5, sizeof(unsigned));

	date_create(past);
	date_create(last);

	printf("\nFirst Date:\n");
	date_output(past);
	printf("\nSecond Date:\n");
	date_output(last);

	date_difference(past, last, diff);
	printf("\nDifference between dates is:\n");
	date_output(diff);

	return 0;
}