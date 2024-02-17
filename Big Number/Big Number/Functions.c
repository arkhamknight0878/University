#include"Functions.h"

unsigned MyStr_len(char* str_)
{
	unsigned str_len = 0;

	if (!str_)
		return 0;

	for (; str_[str_len] != 0; ++str_len);

	return str_len;
}

BG* BG_create(char* big_number_, BG* res_)
{
	res_->size = MyStr_len(big_number_);
	res_->big_number = malloc(res_->size, sizeof(unsigned));

	if (!big_number_ || !res_->big_number)
		return NULL;

	while (*big_number_)
	{
		*res_->big_number = *big_number_;
		res_->big_number++;
		big_number_++;
	}

	*res_->big_number = '\0';

	return res_;
}

void BG_out(BG* big_number_)
{
	for (unsigned i = 0; i != big_number_->size; i++)
	{
		printf("%c", *big_number_->big_number);
		big_number_->big_number++;
	}
}