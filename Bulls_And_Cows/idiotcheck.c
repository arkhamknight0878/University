#include "idiotcheck.h"
#include<stdio.h>

bool Is_Idiot(unsigned int num_)
{
	int check = 0;
	int a = 1;
	int save = 0;

	//Проверка на длинну числа
	if (num_ < 1000)
	{
		printf("!!!Number must contain 4 digits!!!\n");
		return false;
	}

	if (num_ > 9999)
	{
		printf("!!!Number must contain 4 digits!!!\n");
		return false;
	}

	//Проверка на повтор цифр
	while (num_ >= 1)
	{
		check = num_ % 10;
		save = num_;
		a = 1;

		while (a >= 1)
		{
			save /= 10;
			a = save % 10;

			if (check == a)
			{
				printf("!!!Digits in numbers should not be repeated!!!\n");
				return false;
			}
		}

		num_ /= 10;
	}


	return true;
}
