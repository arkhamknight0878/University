#include "bulls_cows.h"

//Подсчёт коров
int Cow_Count(unsigned int startnum_, unsigned int guessnum_)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int check = 0;
	int cows = 0;

	a = startnum_ % 10;
	startnum_ /= 10;
	b = startnum_ % 10;
	startnum_ /= 10;
	c = startnum_ % 10;
	startnum_ /= 10;
	d = startnum_;

	while (guessnum_ >= 1)
	{
		check = guessnum_ % 10;
		if ((check == a) || (check == b) || (check == c) || (check == d))
			cows++;
		guessnum_ /= 10;
	}
	return cows;
}

//Подсчёт быков
int Bull_Count(unsigned int startnum_, unsigned int guessnum_)
{
	int a = 0;
	int check = 0;
	int bulls = 0;

	while (guessnum_ >= 1)
	{
		a = startnum_ % 10;
		check = guessnum_ % 10;

		if (check == a)
			bulls++;

		startnum_ /= 10;
		guessnum_ /= 10;
	}
	return bulls;
}
