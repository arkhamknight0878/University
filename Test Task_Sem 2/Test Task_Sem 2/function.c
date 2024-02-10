#include<math.h>

double Euler_six(unsigned long long range_)
{
	double sum_of_squares = 0;
	double squared_sum = 0;
	double sum_of_numbers = 0;

	for (unsigned long long i = 1; i <= range_; i++)
	{
		sum_of_squares += pow(i, 2);
		sum_of_numbers += i;
	}

	squared_sum = pow(sum_of_numbers, 2);

	return squared_sum - sum_of_squares;
}
/*Пусть структура с датой и временем. Написать функции:
1)По двум данным определяеи разницу во вре-ни;
2)Определяет високосный год или нет;
3)На вход даётся дата. Считает кол-во дней до этой даты*/