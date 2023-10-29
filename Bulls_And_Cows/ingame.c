#include<stdio.h>
#include"idiotcheck.h"
#include"bulls_cows.h"
#include "ingame.h"

unsigned int In_Game(unsigned int startnum_)
{
	unsigned int guessnum = 0;

	printf("Target Number is ");
	scanf_s("%du", &startnum_);

	//Проверка стартового числа на условия и его исправление
	while (Is_Idiot(startnum_) == 0)
	{
		printf("\nNew Target Number is ");
		scanf_s("%du", &startnum_);
	}

	while (Bull_Count(startnum_, guessnum) < 5)
	{
		printf("\nYour Guess Number is ");
		scanf_s("%du", &guessnum);

		//Проверка вводимых чисел на условия
		if (Is_Idiot(guessnum) == 0)
		{
			continue;
		}

		//Если победа, то цикл завершается
		if (guessnum == startnum_)
			break;

		//Вывод количества быков и коров
		printf("Bulls: %d  |  Cows: %d\n", Bull_Count(startnum_, guessnum), Cow_Count(startnum_, guessnum) - Bull_Count(startnum_, guessnum));

	}

	printf("\nCongrats!!! You WIN!!!\n");

	return 0;
}
