#include <stdio.h>
#define LENGTH 7

void printArray(int a[], int len);
void sortArray(int a[], int start, int end);
int divideArray(int a[], int head, int tail);

int main()
{
    /* 쉽게 요약하자면 divArray함수를 통해 그 함수 안의 left와 right가 교차하는 지점을 반환
    그것이 피벗이 된다(기준점) 따라서 재귀 호출로 그 기준점을 제외하고 남은 범위들을 다시 호출한다고
    생각하면 됨
     ex)아래 예시를 기준으로 (3)이 중앙이므로 3이 피벗이 되고 0~2와 4~6이 다시 재귀호출됨*/
    int a[LENGTH] = {4, 7, 1, 6, 2, 5, 3};
    
    printArray(a, LENGTH);

    sortArray(a,0,LENGTH-1);

    printArray(a, LENGTH);

    return 0;
}
void printArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("[%d] ", a[i]);
    } 
    printf("\n");
}

void sortArray(int a[], int start, int end)
{
    int pivot; // 배열을 그룹으로 나누는 기준값의 위치

    if (start < end)
    {
        pivot = divideArray(a, start, end);
        sortArray(a, start, pivot - 1);
        sortArray(a, pivot + 1, end);
    }
}

int divideArray(int a[], int head, int tail)
{
    int left, right, temp;
    left = head + 1;
    right = tail;

    while (1)
    {
        /*배열을 선두로 +1부터 뒤쪽으로 훑어 && 기준값보다 큰 요소를 찾아낸다*/
        if (left < tail && a[head] > a[left])
        { // 기준값이 더 크면 다음으로 넘어감(범위끝을 넘는게 아닌)
            left++;
        }

        /*끝에서 앞으로 가면서 기준값보다 작은 요소를 찾아낸다*/
        if (a[head] < a[right])
        { // 기준값이 더 크면 이전것으로 넘어감
            right--;
        }

        /*확인할 요소가 더이상 없어지는 케이스*/
        if (left >= right)
            break;

        /*확인할 요소가 없으면 위에서 루프문이 끝나므로 무조건 교환해도 된다*/
        //기준값보다 큰 left와 기준값보다 작은 right를 교환
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        //다음 요소로 이동
        left++;
        right--;
    }
    //기준값 a[head]와 a[right]를 교환
    temp = a[head];
    a[head] = a[right];
    a[right] = temp;

    // 기준 값의 위치를 반환
    return right;
}
