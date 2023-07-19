#include<stdio.h>
#include <stdlib.h>
#define L 6

/* 힙의 크기 */
int LENGTH = L;

/* 힙의 크기 저장 */
int size = L;

int H[6] = {24, 17, 33, 50, 60, 70};//힙
int n = 0;//힙의 크기

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void buildHeap();
void downHeap(int cur);
void HeapSort();

int main()
{
    /* 최초 힙 구축 */
    buildHeap();

    /* 생성된 힙을 정렬 */
    HeapSort();
    
    /* 출력 */
    for(int i = 0; i < size; i++)
    {
        printf("H[%d] = %d\n", i, H[i]);
    }

    return 0;
}

void buildHeap()
{
    for(int i = LENGTH / 2; i >= 0; i--)
    {
        downHeap(i);
    }
}

void downHeap(int cur)
{
    /* 자식 노드가 없다면 */
    if(cur * 2 + 1 > LENGTH) return;

    int big = cur * 2 + 1;

    /* 우측 자식 노드가 존재할 때 */
    if(cur * 2 + 2 <= LENGTH)
    {
        /* 둘의 값 중 더 큰 것을 추출 */
        big = H[cur*2+1] > H[cur*2+2] ? cur*2+1 : cur*2+2;
    }

    /* 현재 노드보다 자식의 값이 더 클 경우 */
    if(H[cur] < H[big])
    {
        swap(&H[cur], &H[big]);
        downHeap(big);
    }
    else{
        return;
    }

}

void HeapSort()
{
    LENGTH--;

    for(int i = size - 1; i >= 1; i--){
        /* 여기서 가장 큰 값은 맨 뒤로 가고 그 자리는 이제 분류 범위에서 제외 */
        /* 최댓값은 어차피 맨 끝에 있기 때문, 다만 이 과정 수행시 힙이 무너짐 */
        swap(&H[0], &H[i]);
        
        /* 최댓값 부분은 제외하고 나머지 부분들로만 힙 구축을 위해 범위를 줄여줌 */
        LENGTH--;

        /* 무너진 힙을 다시 재건 */
        downHeap(0);
    }
}