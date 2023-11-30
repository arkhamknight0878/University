
unsigned long long MinMult(unsigned long long range_)
{
	unsigned long long Answer = 1;
	for (unsigned long long i = 1; i <= range_; i++)
	{
		if (Answer % i != 0)
		{
			Answer++;
			i = 1;
		}
	}

	return Answer;
}