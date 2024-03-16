#pragma once

#include<stdbool.h>

typedef unsigned char digit;

typedef struct BigNumber
{
	unsigned size;
	digit* big_number;
	bool is_negative;
} BN;

/* ~ Алгебраические операции
   ~ Ввод
   ~ Вывод
   ~ Удаление */