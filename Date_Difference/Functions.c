#include "Functions.h"

void date_create(Date* date_)
{
	printf("\nPlease, enter day, mounth, year, hour, minuet through Space Bar:\n\n");
	scanf_s("%u", &date_->day);
	scanf_s("%u", &date_->mounth);
	scanf_s("%u", &date_->year);
	scanf_s("%u", &date_->hour);
	scanf_s("%u", &date_ ->minuet);
}

void date_output(Date* date_)
{
	printf("%u/%u/%u %u:%u\n", date_->day, date_->mounth, date_->year, date_->hour, date_->minuet);
}

void date_difference(Date* past_date_, Date* last_date_, Date* res_)
{
	res_->year = last_date_->year - past_date_->year;
	res_->mounth = (12 - past_date_->mounth) + ((res_->year - 1) * 12) + last_date_->mounth;
	res_->day = (31 - past_date_->day) + ((res_->mounth - 1) * 31) + last_date_->day;
	res_->hour = (24 - past_date_->hour) + ((res_->day - 1) * 24) + last_date_->hour;
	res_->minuet = (60 - past_date_->minuet) + ((res_->hour - 1) * 60) + last_date_->minuet;
}

bool is_leap(Date* date_)
{
	if ((date_->year % 400 == 0) || ((date_->year % 4 == 0) && (date_->year % 100 != 0)))
		return true;

	return false;
}