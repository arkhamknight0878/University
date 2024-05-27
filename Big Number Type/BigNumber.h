#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char digits;

/**
 * @brief : Big Number Struct Type
 */
typedef struct BigNumber BigNumber;

/**
 * @brief : Creates Custom Big Number
 * @param number_ : Number
 * @return : Big Number
 */
BigNumber* BN_Create(digits* number_);

/**
 * @brief : Deletes Big Namber
 * @param big_number_ : Big Number
 */
void BN_Delete(BigNumber** big_number_);

/**
 * @brief : Prints Big Number
 * @param big_number_ : Big Number
 */
void BN_Print(BigNumber* big_number_);

/**
 * @brief : Calculates Difference of Two Big Numbers
 * @param bn1_ : First Big Number
 * @param bn2_ : Second Big Number
 * @return : Difference of Two Big Numbers
 */
BigNumber* BN_Dif(BigNumber* bn1_, BigNumber* bn2_);

/**
 * @brief : Calculates Sum of Two Big Numbers
 * @param bn1_ : First Big Number
 * @param bn2_ : Second Big Number
 * @return : Sum of Two Big Numbers
 */
BigNumber* BN_Sum(BigNumber* bn1_, BigNumber* bn2_);
