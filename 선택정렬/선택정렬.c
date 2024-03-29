#include <stdio.h>
#define LENGTH 5

int main()
{
    int a[LENGTH] = {9, 5, 7, 1, 3};
    int ins, cmp, temp, min;

    for (ins = 0; ins < LENGTH - 1; ins++) // 원소가 들어갈 자리의 순서
    {
        /* ins번째 인덱스에 들어갈 원소를 찾는 과정 */
        min = ins;
        for (cmp = ins + 1; cmp < LENGTH; cmp++)
        {
            
            if (a[min] > a[cmp])//최솟값의 위치만 저장
            {
                min = cmp;
            }
        }
        /* SWAP함수를 사용해도 된다 */
        temp = a[min];
        a[min] = a[ins];
        a[ins] = temp;
    }

    for (int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}