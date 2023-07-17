#include <stdio.h>
#define LENGTH 5

int main()
{
    int a[LENGTH] = {10, 2, 3, 7, 9};
    int ins, cmp, temp, min;

    for (ins = 0; ins < LENGTH - 1; ins++) // 원소가 들어갈 자리의 순서
    {
        min = ins;
        for (cmp = ins + 1; cmp < LENGTH; cmp++)
        {
            /* ins번째 인덱스에 들어갈 원소를 찾는 과정 */
            if (a[ins] > a[cmp])
            {
                min = cmp;
                temp = a[min];
                a[min] = a[ins];
                a[ins] = temp;
            }
        }
        /* SWAP함수를 사용해도 된다 */
    }

    for (int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}