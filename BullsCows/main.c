#include <stdio.h>
#include "ingame.h"
#include"functions.h"

int main()
{
	unsigned int StartNum = 0;
	printf("Enter start number ");
	scanf_s("%ud", &StartNum);
	printf("%u", InGame(StartNum));

	return 0;
}