#include"BigNumber.h"

#include<stdio.h>

#include"MyStr.h"

BN* BN_Create(digit* bn_);

void BN_Print(BN* bn_);

void BN_Delete(BN** bn_);

BN* BN_Adition(BN* frst_term_, BN* scnd_term_);