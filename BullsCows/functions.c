#include "functions.h"

bool Is_Idiot(unsigned int number_)
{
	unsigned int save = 0;
	unsigned int check_num = 0;
	unsigned int a = 0;

	if ((number_ < 1000) || (number_ > 9999))
		return true;

	while (number_ != 0)
	{
		check_num = number_ % 10;
		save = number_ / 10;

		while (save != 0)
		{
			a = save % 10;

			if (a == check_num)
				return true;

			save /= 10;
		}

		number_ /= 10;
	}

	return false;
}

unsigned int Bulls(unsigned int startnumber_, unsigned int guessnumber_)
{
	unsigned int Bulls = 0;
	unsigned int check_num = 0;
	unsigned int a = 0;

	while (guessnumber_ != 0)
	{
		check_num = guessnumber_ % 10;
		a = startnumber_ % 10;

		if (check_num == a)
			Bulls++;

		guessnumber_ /= 10;
		startnumber_ /= 10;
	}

	return Bulls;
}

unsigned int Cows(unsigned int startnumber_, unsigned int guessnumber_)
{
	unsigned int Cows = 0;
	unsigned int save = 0;
	unsigned int check_num = 0;
	unsigned int a = 0;

	while (guessnumber_ != 0)
	{
		check_num = guessnumber_ % 10;
		save = startnumber_;

		while (save != 0)
		{
			a = save % 10;

			if (check_num == a)
				Cows++;

			save /= 10;
		}

		guessnumber_ /= 10;
	}

	return Cows;
}