#include <stdio.h>
#define LENGTH 10

void swap(int* a, int* b);

int main()
{
    int a[10] = {10, 4, 9, 5, 1, 8, 3, 7, 2, 6}, gap, i, j, idx;

    gap = LENGTH / 2;

    while(gap > 0)
    {
        if(gap % 2 == 0) gap++;

        /* 기준값의 인덱스(기준값의 인덱스는 gap-1이 최대) */
        for(idx = 0; idx < gap ; idx++)
        {
            /* 키 값의 인덱스 */
            for(i = idx + gap ; i < LENGTH; i++)
            {
                int key = a[i];

                /* key값 앞에 있는 검사할 값들 */
                for(j = i - gap; j >= idx && a[j] > key; j-=gap)
                {
                    /* gap만큼 뒤로 이동 */
                    a[j+gap] = a[j];
                }           
                /* key값의 위치 */
                a[j+gap] = key;
            }
        }
        gap /= 2;
    }

    for(int i = 0; i < LENGTH; i++)
    {
        printf("a[%d]: %d\n", i,a[i]);
    }

    return 0;
}

void swap(int*a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}