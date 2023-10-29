#include"Function.h"

unsigned long long Reverse(unsigned long long Num_)
{
	unsigned long long Num = Num_;
	unsigned long long Rev_Num = 0;
	unsigned long long Last_Dig = 0;

	while (Num > 0)
	{
		Last_Dig = Num % 10;
		Rev_Num = Rev_Num * 10 + Last_Dig;
		Num /= 10;
	}

	return Rev_Num;
}

bool Is_Polin(unsigned long long Rev_Num_)
{
	return Rev_Num_ == Reverse(Rev_Num_);
}