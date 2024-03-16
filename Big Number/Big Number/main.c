#include"BigNumber.h"
#include"Functions.h"

int main()
{
    char str1[] = "090";
    char str2[] = "099";

    BN* bn1 = BN_Create(str1);
    if (bn1 == NULL)
        printf("bn == NULL!\n");

    BN* bn2 = BN_Create(str2);
    if (bn2 == NULL)
        printf("bn == NULL!\n");

    BN_Print(bn1);
    BN_Print(bn2);

    BN* res;
    res = BN_Adition(bn1, bn2);

    BN_Print(res);

    return 0;
}