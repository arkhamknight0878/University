#include"Functions.h"

#include<stdlib.h>
#include<string.h>

#include"MyStr.h"

BN* BG_Create(digit* number_)
{
	BN* bn = malloc(sizeof(BN));
	if (bn == NULL || number_ == NULL)
		return NULL;

	bn->size = strlen(number_);

	bn->big_number = calloc(bn->size, sizeof(digit));
	if (bn->big_number == NULL || !bn->big_number || !IsIntString(bn->big_number))
	{
		free(bn->big_number);
		return NULL;
	}

	for (unsigned i = 0; i < bn->size; ++i)
	{
		bn->big_number[i] = number_[i] - '0';
	}

	return bn;
}
