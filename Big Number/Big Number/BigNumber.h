#pragma once

typedef unsigned char digit;

typedef struct BigNumber
{
	unsigned size;
	digit* big_number;
} BN;

/* ~ Алгебраические операции
   ~ Ввод
   ~ Вывод
   ~ Удаление */