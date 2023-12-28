#include"functions.h"
#include<stdlib.h>
#include<errno.h>

int fget_info(const char* filename_, MOVIE* movie_)
{
	FILE* file;
	fopen_s(&file, filename_, "r");
	if (file != NULL)
	{
		for (int i = 0; fscanf_s(file, "%[^|],%[^|],%u,%u,%u,%u,%u,%u,%u", movie_[i].name, (unsigned)_countof(movie_[i].name), movie_[i].genre, (unsigned)_countof(movie_[i].genre),
			&movie_[i].date.year, &movie_[i].date.mounth, &movie_[i].date.day, &movie_[i].date.hours, &movie_[i].date.minutes, &movie_[i].duaration_min,
			&movie_[i].budget_mill) > 0; i++)
		{
			if (movie_[i].date.hours > 18 && movie_[i].duaration_min > 100)
			{
				printf_s("-------%s-------\n", movie_[i].name);
				printf_s("Date: %u/%u/%u, Time: %u:%u\n", movie_[i].date.year, movie_[i].date.mounth, movie_[i].date.day, movie_[i].date.hours, movie_[i].date.minutes);
				printf_s("Duaration: %u\n", movie_[i].duaration_min);
				printf_s("Genre: %s\n", movie_[i].genre);
				printf_s("Budget: %u\n\n", movie_[i].budget_mill);
			}
		}
	}
	else
	{
		printf("Errno: %d", errno);
		perror(filename_);
		return 1;
	}

	fclose(file); 

	return 0;
}