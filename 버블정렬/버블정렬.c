#include <stdio.h>
#define LENGTH 5

int main()
{
    int a[LENGTH] = {90, 34, 78, 12, 56};
    int ins, cmp, temp;

    for(ins = 0; ins < LENGTH - 1; ins++)
    {
        for(cmp = 0; cmp < LENGTH - ins - 1 ; cmp++)
        {
            if(a[cmp] > a[cmp + 1])
            {
                temp = a[cmp];
                a[cmp] = a[cmp + 1];
                a[cmp + 1] = temp;
            }
        }
    }

    for(int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}