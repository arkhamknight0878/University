#include<stdlib.h>
#include"functions.h"
#include"Date.h"

int main()
{
	Date* earlier = malloc(sizeof(Date));
	if (earlier == NULL)
		return 1;

	Date* later = malloc(sizeof(Date));
	if (later == NULL)
		return 1;

	Date* diff = malloc(sizeof(Date));
	if (diff == NULL)
		return 1;

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