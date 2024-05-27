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
	{
		big_number->number[i] = *number_ - '0';
		number_++;
	}

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

bool Is_Equal(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return;

	for (size_t i = 0; i < bn1_->size; i++)
	{
		if (bn1_->number[i] != bn2_->number[i])
			return false;
	}

	return true;
}

BigNumber* BN_Dif(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return NULL;

	if (bn1_->is_negative == bn2_->is_negative)
		return BN_Sum(bn1_, bn2_);

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (!result)
		return NULL;

	result->size = ((bn1_->size >= bn2_->size) ? bn1_->size : bn2_->size) + 1;

	result->number = (digits*)calloc(result->size, sizeof(digits));
	if (!result->number)
	{
		free(result);
		return NULL;
	}

	BigNumber* greater_bn = (bn1_->size > bn2_->size) ? bn1_ : bn2_;
	BigNumber* lesser_bn = (bn1_->size < bn2_->size) ? bn1_ : bn2_;

	if (bn1_->size == bn2_->size)
	{
		if (Is_Equal(bn1_, bn2_))
		{
			BigNumber* temp = (BigNumber*)realloc(result, 1);
			if (!temp)
			{
				free(result->number);
				free(result);
				return NULL;
			}
			else
			{
				result = temp;
				result->number[0] = '0';
				return result;
			}
		}

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

	digits remainder = 1;
	digits dig_diff = 0;

	for (int i = lesser_bn->size - 1; i >= 0; i--)
	{
		if (greater_bn->number[i + difference] < lesser_bn->number[i])
		{
			greater_bn->number[(i + difference) - 1]--;
			dig_diff = greater_bn->number[i + difference] + 10 - lesser_bn->number[i];
		}
		else
			dig_diff = greater_bn->number[i + difference] - lesser_bn->number[i];

		result->number[i + difference + 1] = dig_diff;
	}

	size_t j = difference;
	for (int i = difference; i > 0; i--)
	{
		result->number[i] = greater_bn->number[j - 1];
		--j;
	}

	greater_bn->is_negative = (greater_bn == bn1_) ? bn1_->is_negative : bn2_->is_negative;
	lesser_bn->is_negative = (lesser_bn == bn1_) ? bn1_->is_negative : bn2_->is_negative;

	if (greater_bn->is_negative == true && lesser_bn->is_negative == false)
		result->is_negative = true;
	else result->is_negative = false;

	return result;
}

BigNumber* BN_Sum(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return NULL;

	if (bn1_->is_negative != bn2_->is_negative)
		return BN_Dif(bn1_, bn2_);

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (result == NULL)
		return NULL;

	result->size = ((bn1_->size <= bn2_->size) ? bn2_->size : bn1_->size) + 1;
	result->is_negative = bn1_->is_negative;

	result->number = (digits*)calloc(result->size, sizeof(digits));
	if (!result->number)
	{
		free(result);
		return NULL;
	}
	
	BigNumber* greater_bn;
	BigNumber* least_bn;

	if (bn1_->size == bn2_->size)
	{
		greater_bn = bn1_;
		least_bn = bn2_;
	}
	else
	{
		greater_bn = (bn1_->size >= bn2_->size) ? bn1_ : bn2_;
		least_bn = (bn1_->size <= bn2_->size) ? bn1_ : bn2_;
	}

	size_t difference = greater_bn->size - least_bn->size;

	size_t remainder = 0;
	digits dig_sum = 0;

	for (int i = least_bn->size - 1; i >= 0; i--)
	{
		dig_sum = greater_bn->number[i + difference] + least_bn->number[i] + remainder;

		remainder = dig_sum / 10;

		result->number[i + difference + 1] = dig_sum % 10;
	}

	size_t j = difference;
	for (int i = difference; i > 0; i--)
	{
		dig_sum = greater_bn->number[j - 1] + remainder;
		result->number[i] = dig_sum % 10;
		remainder = dig_sum / 10;
		--j;
	}

	return result;
}

BigNumber* BN_Mult(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return NULL;

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (!result)
		return NULL;

	if (bn1_->number[0] == '0' || bn2_->number[0] == '0')
	{
		result->number = (digits*)calloc(1, sizeof(digits));
		if (!result->number)
		{
			free(result);
			return NULL;
		}

		result->number[0] = '0';
		result->size = 1;
		result->is_negative = false;

		return result;
	}



	return result;
}
