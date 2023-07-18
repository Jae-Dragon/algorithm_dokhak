#include <stdio.h>
#pragma warning(disable:4996)
#include<string.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 10

int inPlacePartition(int* L, int l, int r, int k);
void inPlaceQuickSort(int* L, int l, int r);
int findPivot(int min, int max);
void swap(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
    int a[LENGTH] = {9, 2, 7, 3, 6, 1, 5, 10, 4, 8};

    inPlaceQuickSort(a, 0, LENGTH-1);

    for(int j = 0; j < LENGTH; j++)
    {
        printf("a[%d] = %d\n", j, a[j]);
    }

    return 0;
}

int findPivot(int min, int max)
{
	srand(time(NULL));
	int k = 0;
	k = rand() % (max - min) + min;

	return k;
}
int inPlacePartition(int* L, int l, int r, int k)
{
	int temp;

	int p, i, j;
	p = L[k];//피벗값 넣어줌

	//맨 오른쪽 값과 피벗의 값을 바꿔줌
	swap(&L[r], &L[k]);


	i = l;//맨 왼쪽 값
	j = r - 1;//맨 오른쪽 값(피벗 제외) --> 피벗을 맨 오른쪽으로 보냈기 때문에 


	while (i <= j) {//두개가 크로스 하기 전까지 실행
		while (i <= j && L[i] <= p)//왼쪽 값들이 피벗 값 이하라면 오른쪽으로 이동
			i++;
		while (j >= i && L[j] >= p)//오른쪽 값들이 피벗 값 이상이라면 왼쪽 이동
			j--;
		if (i < j) {//위에서 각각 걸리는 값들을 교환
			swap(&L[i], &L[j]);
		}

	}
    
    /* 크로스 되어 교환이 멈추면 피벗값과 i번째 원소를 교환(원상복귀) */
	swap(&L[i], &L[r]);


	return i;

}
void inPlaceQuickSort(int* L, int l, int r)
{
	if (l >= r) return;//배열의 원소가 0, 1개인 경우

	int k = findPivot(l, r);//기준값의 위치를 정해줌

	int a;

	a = inPlacePartition(L, l, r, k);//고정될 위치

    /* 고정될 위치를 제외하고 실행 */
	inPlaceQuickSort(L, l, a - 1);
	inPlaceQuickSort(L, a + 1, r);
}