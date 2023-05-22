#include <stdio.h> 
#define LENGTH 5

int main()
{
    int a[LENGTH] = {90, 34, 78, 12, 56};
    int ins, cmp, temp;


    //오름차순으로 정렬(삽입)
    for(ins = 1; ins < LENGTH; ins++)
    {
        temp = a[ins];//기준을 잡고
        //기준보다 앞에있는 인덱스들과 비교하여 들어갈 자리를 찾아준다고 생각하면 된다. 
        for(cmp = ins - 1; cmp >=0; cmp--)//역방향이어야하므로 
        {
           if(a[cmp] > temp)
           {
                a[cmp + 1] = a[cmp];//덮어씌운다는 마인드
           } else{//temp에 들어있는 수가 들어갈 자리를 찾은 경우라고 생각함
            break;//cmp+1이 temp가 들어갈 자리
           }    
        } 
        a[cmp+1] = temp;
    }
    for(int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}