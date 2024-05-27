#include "BigNumber.h"

#include <stdio.h>

int main()
{
	BigNumber* bn1 = BN_Create("144");
	BigNumber* bn2 = BN_Create("1");

	printf("Big Number 1: ");
	BN_Print(bn1);
	printf("Big Number 2: ");
	BN_Print(bn2);
	printf("---------------------------------------\n");

	/*BigNumber* sum = BN_Sum(bn1, bn2);
	printf("Big Number 1 + Big Number 2 = ");
	BN_Print(sum);*/

	/*BigNumber* diff = BN_Dif(bn1, bn2);
	printf("Big Number 1 - Big Number 2 = ");
	BN_Print(diff);*/

	/*BigNumber* mult = BN_Mult(bn1, bn2);
	printf("Big Number 1 * Big Number 2 = ");
	BN_Print(mult);*/

	BigNumber* div = BN_Div(bn1, bn2);
	printf("Big Number 1 / Big Number 2 = ");
	BN_Print(div);

	return 0;
}