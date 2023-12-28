#include<stdio.h>
#include<errno.h>
#include"functions.h"
#include"structs.h"

int main()
{
	MOVIE movie[10];

	fget_info("movies_info.txt", movie);

	return 0;
}