#include "Functions.h"

void date_create(Date* date_)
{
	printf("\nPlease, enter day, mounth, year, hours, minuets, seconds through Space Bar:\n");
	scanf_s("%u", &date_->day);
	scanf_s("%u", &date_->mounth);
	scanf_s("%u", &date_->year);
	scanf_s("%u", &date_->hour);
	scanf_s("%u", &date_->minuet);
	scanf_s("%u", &date_->second);
}

void date_output(Date* date_)
{
	printf("%u/%u/%u %u:%u:%u\n", date_->day, date_->mounth, date_->year, date_->hour, date_->minuet, date_->second);
}

unsigned date_leap_days(Date* earlier_date_, Date* later_date_)
{
	unsigned leap = 0;

	while (earlier_date_->year != later_date_->year)
	{
		if (is_leap(earlier_date_))
			++leap;

		earlier_date_->year++;
	}

	return leap;
}

void date_difference(Date* earlier_date_, Date* later_date_, Date* res_)
{
	res_->year = later_date_->year - earlier_date_->year;
	res_->mounth = (12 - earlier_date_->mounth) + ((res_->year - 1) * 12) + later_date_->mounth;
	res_->day = (365 - earlier_date_->day) + ((res_->year - 1) * 365) + later_date_->day + date_leap_days(earlier_date_, later_date_);
	res_->hour = (24 - earlier_date_->hour) + ((res_->day - 1) * 24) + later_date_->hour;
	res_->minuet = (60 - earlier_date_->minuet) + ((res_->hour - 1) * 60) + later_date_->minuet;
	res_->second = (60 - earlier_date_->second) + ((res_->minuet - 1) * 60) + later_date_->second;
}

bool is_leap(Date* date_)
{
	if ((date_->year % 400 == 0) || ((date_->year % 4 == 0) && (date_->year % 100 != 0)))
		return true;

	return false;
}