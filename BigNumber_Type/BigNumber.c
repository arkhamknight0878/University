#include "BigNumber.h"
#include "MyStr.h"

#include <stdio.h>

struct BigNumber
{
	number* number;		// Array of Digits
	size_t size;		// Size of Big Number
	bool is_negative;	// Negative Checker
};

BigNumber* BN_Create(number* number_)
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

	big_number->number = (number*)calloc(big_number->size, sizeof(number));
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

void Shift_left(BigNumber* bn_)
{
	if (!bn_)
		return;

	size_t zero_counter = 0;

	for (size_t i = 0; bn_->number[i] == 0; i++)
		zero_counter++;

	for (size_t i = 0; i < zero_counter; ++i)
	{
		for (size_t j = 0; j < (bn_->size) - 1; ++j)
			bn_->number[j] = bn_->number[j + 1];
	}

	number* temp = (number*)realloc(bn_->number, (bn_->size - zero_counter));
	if (!temp)
	{
		free(bn_);
		return;
	}
	else
	{
		bn_->number = temp;
		bn_->size = bn_->size - zero_counter;
	}
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

	result->number = (number*)calloc(result->size, sizeof(number));
	if (!result->number)
	{
		free(result);
		return NULL;
	}

	BigNumber* greater_bn = (bn1_->size > bn2_->size) ? bn1_ : bn2_;
	BigNumber* least_bn = (bn1_->size < bn2_->size) ? bn1_ : bn2_;

	if (bn1_->size == bn2_->size)
	{
		if (Is_Equal(bn1_, bn2_))
		{
			number* temp = (number*)realloc(result->number, 1);
			if (!temp)
			{
				free(result->number);
				free(result);
				return NULL;
			}
			else
			{
				result->number = temp;

				result->number[0] = 0;
				result->size = 1;
				result->is_negative = false;

				return result;
			}
		}

		for (size_t i = 0; i < bn1_->size; i++)
		{
			if (bn1_->number[i] > bn2_->number[i])
			{
				greater_bn = bn1_;
				least_bn = bn2_;

				break;
			}
			else if (bn1_->number[i] < bn2_->number[i])
			{
				greater_bn = bn2_;
				least_bn = bn1_;

				break;
			}
		}
	}

	size_t difference = greater_bn->size - least_bn->size;

	number remainder = 1;
	number dig_diff = 0;

	for (int i = least_bn->size - 1; i >= 0; i--)
	{
		if (greater_bn->number[i + difference] < least_bn->number[i])
		{
			greater_bn->number[(i + difference) - 1]--;
			dig_diff = greater_bn->number[i + difference] + 10 - least_bn->number[i];
		}
		else
			dig_diff = greater_bn->number[i + difference] - least_bn->number[i];

		result->number[i + difference + 1] = dig_diff;
	}

	size_t j = difference;
	for (int i = difference; i > 0; i--)
	{
		result->number[i] = greater_bn->number[j - 1];
		--j;
	}

	greater_bn->is_negative = (greater_bn == bn1_) ? bn1_->is_negative : bn2_->is_negative;
	least_bn->is_negative = (least_bn == bn1_) ? bn1_->is_negative : bn2_->is_negative;

	if (greater_bn->is_negative == true && least_bn->is_negative == false)
		result->is_negative = true;
	else result->is_negative = false;

	Shift_left(result);

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

	result->number = (number*)calloc(result->size, sizeof(number));
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
	number dig_sum = 0;

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

	Shift_left(result);

	return result;
}

BigNumber* BN_Mult(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return NULL;

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (!result)
		return NULL;

	if (bn1_->number[0] == 0 || bn2_->number[0] == 0)
	{
		result->number = (number*)calloc(1, sizeof(number));
		if (!result->number)
		{
			free(result);
			return NULL;
		}

		result->number[0] = 0;
		result->size = 1;
		result->is_negative = false;

		return result;
	}

	if (bn1_->is_negative == bn2_->is_negative)
		result->is_negative = false;
	else
		result->is_negative = true;

	result->size = bn1_->size + bn2_->size;

	result->number = (number*)calloc(result->size, sizeof(number));
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

	for (int i = least_bn->size - 1; i >= 0; --i)
	{
		for (int j = greater_bn->size - 1; j >= 0; --j)
		{
			size_t index = result->size - (greater_bn->size - j) - (least_bn->size - i) + 1;
			result->number[index] = (greater_bn->number[j]) * (least_bn->number[i]);
		}
	}

	for (int i = result->size - 1; i > 0; --i)
	{
		result->number[i - 1] += result->number[i] / 10;
		result->number[i] %= 10;
	}

	Shift_left(result);

	return result;
}

bool Is_Min_BN(BigNumber* bn1_, BigNumber* bn2_)
{
	if (bn1_->size < bn2_->size)
		return false;
	else if (bn1_->size > bn2_->size)
		return true;
	else
	{
		for (size_t i = 0; i < bn1_->size; i++)
		{
			if (bn1_->number[i] != bn2_->number[i])
				return false;
		}
	}

	return true;
}

BigNumber* BN_Div(BigNumber* bn1_, BigNumber* bn2_)
{
	if (!bn1_ || !bn2_)
		return NULL;

	if ((bn1_->size > bn2_->size && bn1_->number[0] == 0) || (bn2_->size > bn1_->size && bn2_->number[0] == 0))
	{
		printf("Seriously?\nYou Have Been Banned...");
		return NULL;
	}

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (!result)
		return NULL;

	result->size = (bn1_->size > bn2_->size) ? (bn1_->size - bn2_->size) : (bn2_->size - bn1_->size);

	result->number = (number*)calloc(result->size, sizeof(number));
	if (!result->number)
	{
		free(result);
		return NULL;
	}

	if (bn1_->number[0] == 0 || bn2_->number[0] == 0)
	{
		number* temp = (number*)realloc(result->number, 1);
		if (!temp)
		{
			free(result->number);
			free(result);
			return NULL;
		}
		else
		{
			result->number = temp;

			result->number[0] = 0;
			result->size = 1;
			result->is_negative = false;

			return result;
		}
	}

	if (bn1_->size == bn2_->size)
	{
		if (Is_Equal(bn1_, bn2_))
		{
			number* temp = (number*)realloc(result->number, 1);
			if (!temp)
			{
				free(result->number);
				free(result);
				return NULL;
			}
			else
			{
				result->number = temp;

				result->number[0] = 1;
				result->size = 1;
				result->is_negative = false;

				return result;
			}
		}
	}

	if (bn1_->is_negative != bn2_->is_negative)
		result->is_negative = true;
	else
		result->is_negative = false;

	result = BN_Create("0");

	BigNumber* ones = (BigNumber*)malloc(sizeof(BigNumber));
	if (ones == NULL)return NULL;

	ones = BN_Create("1");

	BigNumber* temp = (BigNumber*)malloc(sizeof(BigNumber));
	if (temp == NULL)return NULL;
	int cpy = bn1_->is_negative;
	*temp = *bn1_;

	while (temp->is_negative == cpy && !(temp->size == 1 && temp->number[0] == 0) && Is_Min_BN(bn1_, bn2_) == true)
	{
		result = BN_Sum(result, ones);
		temp = BN_Dif(temp, bn2_);
	}

	return result;
}

