#include<stdio.h>
#include"idiotcheck.h"
#include"bulls_cows.h"
#include "ingame.h"

unsigned int In_Game(unsigned int startnum_)
{
	unsigned int guessnum = 0;

	printf("Target Number is ");
	scanf_s("%du", &startnum_);

	//�������� ���������� ����� �� ������� � ��� �����������
	while (Is_Idiot(startnum_) == 0)
	{
		printf("\nNew Target Number is ");
		scanf_s("%du", &startnum_);
	}

	while (Bull_Count(startnum_, guessnum) < 5)
	{
		printf("\nYour Guess Number is ");
		scanf_s("%du", &guessnum);

		//�������� �������� ����� �� �������
		if (Is_Idiot(guessnum) == 0)
		{
			continue;
		}

		//���� ������, �� ���� �����������
		if (guessnum == startnum_)
			break;

		//����� ���������� ����� � �����
		printf("Bulls: %d  |  Cows: %d\n", Bull_Count(startnum_, guessnum), Cow_Count(startnum_, guessnum) - Bull_Count(startnum_, guessnum));

	}

	printf("\nCongrats!!! You WIN!!!\n");

	return 0;
}
