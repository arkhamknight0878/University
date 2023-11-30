#include <stdio.h>
#include "ingame.h"
#include "functions.h"

unsigned int InGame(unsigned int startnum_)
{
	unsigned int GuessNum = 0;

	while (Is_Idiot(startnum_) == true)
	{
		printf("\nNumber should contain four non-repeated digits, try again.\nYour new number is ");
		scanf_s("%u", &startnum_);
	}

	while (Bulls(startnum_, GuessNum) < 5)
	{
		printf("\nEnter your guess.\nYour guess number is ");
		scanf_s("%u", &GuessNum);

		while (Is_Idiot(GuessNum) == true)
		{
			printf("\nNumber should contain four non-repeated digits, try again.\nYour new guess number is ");
			scanf_s("%u", &GuessNum);
		}

		if (GuessNum == startnum_)
			break;

		printf("Bulls: %u  |  Cows: %u\n", Bulls(startnum_, GuessNum), Cows(startnum_, GuessNum) - Bulls(startnum_, GuessNum));
	}

	printf("\nCongrats!!! You WON!!!\n");

	return 0;
}
