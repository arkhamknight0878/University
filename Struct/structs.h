#pragma once

typedef struct date_info
{
	unsigned year;
	unsigned mounth;
	unsigned day;
	unsigned hours;
	unsigned minutes;
} DATE;

typedef struct movie_info
{
	char name[100];
	char genre[100];
	DATE date;
	unsigned duaration_min;
	unsigned budget_mill;
} MOVIE;