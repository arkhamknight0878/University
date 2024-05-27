#include "BigNumber.h"
#include "MyStr.h"

#include <stdio.h>

struct BigNumber
{
	digits* number;		// Array of Digits
	size_t size;		// Size of Big Number
	bool is_negative;	// Negative Checker
};

BigNumber* BN_Create(digits* number_)
{
	if (number_ == NULL || StrLen(number_) == 0 || Is_IntArr(number_) == false)
		return NULL;

	BigNumber* big_number = (BigNumber*)malloc(sizeof(BigNumber));
	if (big_number == NULL)
		return NULL;

	size_t size = StrLen(number_);

	if (*number_ == '-')
	{
		big_number->is_negative = true;
		big_number->size = size - 1;
		++number_;
	}
	else
	{
		big_number->is_negative = false;
		big_number->size = size;
	}

	big_number->number = (digits*)calloc(big_number->size, sizeof(digits));
	if (big_number->number == NULL)
	{
		free(big_number);
		return NULL;
	}

	for (size_t i = 0; i < big_number->size; ++i)
		big_number->number[i] = number_[i] - '0';

	return big_number;
}

void BN_Delete(BigNumber** big_number_)
{
	if (big_number_ == NULL)
		return;

	free((*big_number_)->number);
	free(*big_number_);

	*big_number_ = NULL;
}

void BN_Print(BigNumber* big_number_)
{
	if (big_number_ == NULL)
		return;

	if (big_number_->is_negative == true)
		printf("-");

	for (size_t i = 0; i < big_number_->size; ++i)
		printf("%u", big_number_->number[i]);

	printf("\n");
}

BigNumber* BN_Dif(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return NULL;

	if (bn1_->is_negative == true && bn2_->is_negative == true)
		return BN_Sum(bn1_, bn2_);

	BigNumber* res = (BigNumber*)malloc(sizeof(BigNumber));
	if (!res)
		return NULL;

	res->size = (bn1_->size >= bn2_->size) ? bn1_->size : bn2_->size;

	res->number = (digits*)calloc(res->size, sizeof(digits));
	if (!res->number)
	{
		free(res);
		return NULL;
	}

	BigNumber* greater_bn = (bn1_->size >= bn2_->size) ? bn1_ : bn2_;
	BigNumber* lesser_bn = (bn1_->size <= bn2_->size) ? bn1_ : bn2_;

	greater_bn->is_negative = (greater_bn == bn1_) ? bn1_->is_negative : bn2_->is_negative;
	lesser_bn->is_negative = (lesser_bn == bn1_) ? bn1_->is_negative : bn2_->is_negative;

	if (bn1_->size == bn2_->size)
	{
		for (size_t i = 0; i < bn1_->size; i++)
		{
			if (bn1_->number[i] > bn2_->number[i])
			{
				greater_bn = bn1_;
				lesser_bn = bn2_;

				break;
			}
			else if (bn1_->number[i] < bn2_->number[i])
			{
				greater_bn = bn2_;
				lesser_bn = bn1_;

				break;
			}
		}
	}

	size_t difference = greater_bn->size - lesser_bn->size;

	for (int i = greater_bn->size; i >= 0; i--)
	{
		digits dig_diff = 0;

		if (greater_bn->number[i] < lesser_bn->number[i - 1])
		{
			greater_bn->number[i - 1]--;
			dig_diff = greater_bn->number[i] + 10 - lesser_bn->number[i - difference];
		}
		else
			dig_diff = greater_bn->number[i] - lesser_bn->number[i - difference];

		res->number[i] = dig_diff;
	}

	if (greater_bn->is_negative == true && lesser_bn->is_negative == false)
		res->is_negative = true;
	else res->is_negative = false;

	return res;
}

BigNumber* BN_Sum(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return NULL;

	if (bn1_->is_negative != bn2_->is_negative)
		return BN_Dif(bn1_, bn2_);

	BigNumber* res = (BigNumber*)malloc(sizeof(BigNumber));
	if (res == NULL)
		return NULL;

	res->size = ((bn1_->size <= bn2_->size) ? bn2_->size : bn1_->size) + 1;

	res->number = (digits*)calloc(res->size, sizeof(digits));
	if (!res->number)
	{
		free(res);
		return NULL;
	}
	
	BigNumber* greater_bn = (bn1_->size >= bn2_->size) ? bn1_ : bn2_;
	BigNumber* least_bn = (bn1_->size <= bn2_->size) ? bn1_ : bn2_;

	size_t difference = greater_bn->size - least_bn->size;

	res->is_negative = bn1_->is_negative;

	size_t remainder = 0;

	for (int i = greater_bn->size; i >= 0; i--)
	{
		digits dig_sum = greater_bn->number[i] + least_bn->number[i - difference] + remainder;

		remainder = dig_sum / 10;

		res->number[i] = dig_sum % 10;
	}

	return res;
}