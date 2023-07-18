#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

void merge(int *ARR, int low, int mid, int high);
void mergeSort(int *ARR, int low, int high);

int main()
{
 
    int a[10] = {9, 2, 7, 3, 6, 1, 5, 10, 4, 8};

    mergeSort(a, 0, LENGTH-1);

    /*결과값 출력*/

    for(int i = 0; i < LENGTH; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}

void merge(int *ARR, int low, int mid, int high)
{
    int *arr = NULL, size = high - low + 1;
    arr = (int*)malloc(sizeof(int)*size);//분리된 리스트를 정렬하며 합치기 위한 임시 공간

    int i = low, j = mid + 1, k = 0;//각각 왼쪽 리스트와 오른쪽 리스트의 시작 지점, k는 임시공간의 시작 지점

    /* 이미 분할되어 있던 리스트들을 합치면서 그 과정에서 크기에 따라 정렬한다고 생각하면 이해하기 편함 */
    while(i <= mid && j <= high)
    {
        /* 더 작은 값부터 임시 공간에 넣어줌 */
        if(ARR[i] <= ARR[j]){
            arr[k++] = ARR[i++];
        }
        else{
            arr[k++] = ARR[j++];
        }
    }

    /* 위의 조건이 종료되었다만 남은 값들을 넣어준다 */
    while(i <= mid)
        arr[k++] = ARR[i++];
    while(j <= high)
        arr[k++] = ARR[j++];

    k--;//맨 마지막에 한번 더 더해줬기 때문에 감소시켜줘야함
    
    /* 임시 공간에 순서대로 넣었던 데이터들을 원본 배열에 넘겨줌*/
    while(k >= 0)
    {
        ARR[low+k] = arr[k];
        k--;
    }
    free(arr);
}

void mergeSort(int *ARR, int low, int high)
{
    int mid;
    if(low < high)
    {
        /* 분할 기준점 생성 */
        mid = (low+high) / 2;

        /* mergeSort는 정복(Conquer)의 과정 */
        mergeSort(ARR, low, mid); //앞쪽 부분 정렬
        mergeSort(ARR, mid+1, high); //뒤쪽 부분 정렬

        /* 정렬된 2개의 배열을 최종적으로 합병해준다고 생각하면 편함 */
        merge(ARR, low, mid, high); //결합
    }
}