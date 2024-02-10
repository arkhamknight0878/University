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
/*����� ��������� � ����� � ��������. �������� �������:
1)�� ���� ������ ���������� ������� �� ���-��;
2)���������� ���������� ��� ��� ���;
3)�� ���� ����� ����. ������� ���-�� ���� �� ���� ����*/