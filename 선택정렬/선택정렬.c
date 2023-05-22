#include <stdio.h>
#define LENGTH 5

int main()
{
    int a[LENGTH] = {90, 34, 78, 12, 56};
    int ins, cmp, temp;

    for(ins = 0; ins < LENGTH - 1; ins++)//맨 앞에 제일 작은게 오고 그것이 반복
    {
        for(cmp = ins + 1; cmp < LENGTH ; cmp++)
        {
            if(a[ins] > a[cmp])
            {
                temp = a[cmp];
                a[cmp] = a[ins];
                a[ins] = temp;
            }
        }
    }

    for(int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}