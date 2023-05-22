#include <stdio.h>
#define LENGTH 10

int main()
{
    int a[10] = {39, 41, 53, 55, 68, 72, 84, 88, 92, 97};

    int x, pos, left, right, mid;
    pos = -1;
    left = 0; right = LENGTH - 1;


    scanf("%d", &x);
    

    while(pos == -1 && left <= right)//종료조건 2
    {
        mid = (left + right)/2;
        if(x == a[mid])//종료조건 1
        {
            pos = mid;
        }
        else if(x > a[mid])
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    if(pos == -1)
        printf("검색 결과 x값은 존재하지 않음");

    else{
        printf("pos = %d번째 인덱스",pos);
    }

    return 0;
}