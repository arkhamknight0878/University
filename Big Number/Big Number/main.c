#include"BigNumber.h"
#include"Functions.h"

int main()
{
	unsigned size = 0;

	printf("Enter the size of Number:\n");
	scanf_s("%u", &size);

	char* big_number_arr = calloc(size, sizeof(char));
	if (big_number_arr == NULL)
		return -1;

	BG_RandArr(size, big_number_arr);

	return 0;
}