#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char number;

/**
 * @brief : Big Number Struct Type
 */
typedef struct BigNumber BigNumber;

/**
 * @brief : Creates Custom Big Number
 * @param number_ : Number
 * @return : Big Number
 */
BigNumber* BN_Create(number* number_);

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
 * @brief : Cheks If Two Big Numbers Are Equal
 * @param bn1_ : First Big Number
 * @param bn2_ : Second Big Number
 * @return : True If Numbers Are Equal, False in Other Case
 */
bool Is_Equal(BigNumber* bn1_, BigNumber* bn2_);

/**
 * @brief : Shifts Big Number's Array Elements To the Left if There Is Some Zeroes
 * @param bn_ : Big Number
 */
void Shift_left(BigNumber* bn_);

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

/**
 * @brief : Calculates Multiplacation of Two Big Numbers
 * @param bn1_ : First Big Number
 * @param bn2_ : Second Big Number
 * @return : Multiplacation of Two Big Numbers
 */
BigNumber* BN_Mult(BigNumber* bn1_, BigNumber* bn2_);

/**
 * @brief : Checks If One Big Number Greater Than Other
 * @param bn1_ : First Big Number
 * @param bn2_ : Second Big Number
 * @return : True If bn2_ Greater Than bn1_, False in Other Case
 */
bool Is_Min_BN(BigNumber* bn1_, BigNumber* bn2_);

/**
 * @brief : Calculates Division of Two Big Numbers
 * @param bn1_ : First Big Number
 * @param bn2_ : Second Big Number
 * @return : Division of Two Big Numbers
 */
BigNumber* BN_Div(BigNumber* bn1_, BigNumber* bn2_);