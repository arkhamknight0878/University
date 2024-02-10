#include"Functions.h"

Date time_difference(Date* date_1, Date* date_2, Date* res_)
{
	printf("Days: %u", date_1->year - date_2->year);
	printf("Mounths: %u", 12 - date_2->mounth + date_1->mounth);
	printf("Days: %u", 365 - date_2->day + date_1->day);
	printf("Hours: %u", 8760 - date_2->hour + date_1->hour);
	printf("Minuets: %u", 525600 - date_2->minuet + date_1->minuet);
	printf("Seconds: %u", 86400 - )

}

bool is_leap_year(Date* date_)
{
	if ((date_->year % 400 == 0) || (date_->year % 4 == 0 && date_->year % 100 != 0))
		return true;

	return false;
}