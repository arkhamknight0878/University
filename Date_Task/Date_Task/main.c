#include<stdlib.h>
#include"functions.h"
#include"Date.h"

int main()
{
	Date* earlier = calloc(6, sizeof(unsigned));
	Date* later = calloc(6, sizeof(unsigned));
	Date* diff = calloc(6, sizeof(unsigned));

	date_create(earlier);
	date_create(later);

	printf("\nEarlier Date:\n");
	date_output(earlier);
	printf("\nLater Date:\n");
	date_output(later);

	date_difference(earlier, later, diff);
	printf("\nDifference between dates is:\n");
	date_output(diff);

	return 0;
}