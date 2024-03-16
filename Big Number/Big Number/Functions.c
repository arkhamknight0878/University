#include"Functions.h"

#include<stdlib.h>
#include<string.h>

#include"MyStr.h"

BN* BN_Create(digit* number_)
{
	if (number_ == NULL || strlen(number_) == 0 || !IsIntString(number_))
		return NULL;

	BN* bn = (BN*)malloc(sizeof(BN));
	if (bn == NULL)
		return NULL;

	size_t size = strlen(number_);

	if (*number_ == '-')
	{
		bn->size = size - 1;
		bn->is_negative = true;
		number_++;
	}
	else
	{
		bn->size = size;
		bn->is_negative = false;
	}

	bn->big_number = (digit*)calloc(bn->size, sizeof(digit));
	if (bn->big_number == NULL)
	{
		free(bn);
		return NULL;
	}

	for (unsigned i = 0; i < bn->size; ++i)
	{
		bn->big_number[i] = number_[i] - '0';
	}

	return bn;
}

void BN_Print(BN* bn_)
{
	if (bn_ == NULL)
	{
		printf("Number is empty!\n");
		return;
	}

	if (bn_->is_negative)
		printf("-");

	for (size_t i = 0; i < bn_->size; ++i)
		printf("%u", bn_->big_number[i]);

	printf("\n");
}

void BN_Delete(BN** number_)
{
	free((*number_)->big_number);
	free(*number_);

	*number_ = NULL;
}

BN* BN_Adition(BN* frst_term_, BN* scnd_term_)
{
	if (frst_term_ == NULL || scnd_term_ == NULL)
		return NULL;

	BN* bn = (BN*)malloc(sizeof(BN));
	if (bn == NULL)
		return NULL;

	size_t size = max(frst_term_->size, scnd_term_->size) + 1;

	bn->big_number = (digit*)calloc(size, sizeof(digit));
	if (bn->big_number == NULL)
	{
		free(bn);
		return NULL;
	}

	bn = frst_term_;

	for (int i = size - 2; i >= 0; --i)
	{
		size_t e = 0;
		if ((frst_term_->big_number[i] + scnd_term_->big_number[i]) >= 10)
			 e = 1;

		bn->big_number[i] += scnd_term_->big_number[i];
		bn->big_number[i] %= 10;

		bn->big_number[i - 1] += e;
	}

	return bn;
}
