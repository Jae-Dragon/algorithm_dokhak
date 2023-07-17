#include <stdio.h>
#define LENGTH 5

int main()
{
    int a[LENGTH] = {5, 4, 3, 2, 1};
    int ins, cmp, temp;

    /* 여기서 ins는 제외할 원소의 개수를 의미한다 */
    for(ins = 0; ins < LENGTH - 1; ins++)
    {
        /* cmp는 직접적으로 비교할 위치 인덱스 역할을 수행한다 */
        for(cmp = 0; cmp < LENGTH - ins - 1 ; cmp++)
        {
            if(a[cmp] > a[cmp + 1])//왼쪽 원소가 오른쪽 원소보다 크기 때문에 오른쪽으로 이동 시켜줌
            {
                /* swap함수로 대체 가능 */
                temp = a[cmp];
                a[cmp] = a[cmp + 1];
                a[cmp + 1] = temp;
            }
        }
    }

    /* 출력 */
    for(int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}