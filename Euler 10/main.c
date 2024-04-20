#include <stdio.h>
#include <time.h>

#include "Functions.h"

int main()
{
	size_t max_number = 0;
	printf("Enter Upper Bound: ");
	scanf_s("%Iu", &max_number);

	time_t start, end;

	start = clock();

	printf("Sum of Prime Elements < %Iu is %Iu\n", max_number, EratosthenesSieve_Sum(max_number));

	end = clock();

	double time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;

	printf("Time taken: %f", time_taken);

	return 0;
}