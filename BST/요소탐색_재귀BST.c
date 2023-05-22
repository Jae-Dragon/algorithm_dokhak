#include <stdio.h>

struct BST
{
    int data;
    int left, right;
};
struct BST tree[10]; // 실체 트리
int rootIdx = 0;     // 루트요소의 물리적 위치
int newIdx = 0;      // 다음에 저장할 요소의 물리적 위치

void addBST(int);          // 요소 추가 함수
void printPhysicalBST();   // 트리 전체 프린트 함수
void printLogicalBST(int); // 깊이우선탐색
int searchBST(int);
int searchRecBST(int x, int currentIdx);

int main()
{
    addBST(4);
    addBST(6);
    addBST(5);
    addBST(2);
    addBST(3);
    addBST(7);
    addBST(1);

    //printPhysicalBST();
    //printLogicalBST(rootIdx); // 인수를 써주는 것은 재귀호출을 위함

    printf("data가 5일 때 물리적 위치는 tree[%d]\n", searchRecBST(5, rootIdx));// 2 반환
    printf("data가 8일 때 물리적 위치는 tree[%d]\n", searchRecBST(8, rootIdx));//존재 x인 값이므로 -1반환

    return 0;
}

void addBST(int data)
{
    int currentIdx; // 현재 요소의 물리적 위치
    int addFlag;    // 요소 추가 완료 확인

    /*물리적 위치에 요솟값과 연결 정보 추가*/
    /*맨 처음 루트노드라면 추가되고 종료되는 것임*/
    tree[newIdx].data = data;
    tree[newIdx].left = -1;
    tree[newIdx].right = -1;

    if (newIdx != rootIdx) // 루트 노드가 아니라면
    {
        currentIdx = rootIdx;
        addFlag = 0;

        while (addFlag == 0) // 맨 처음에는 루트노드부터 시작
        {
            if (data < tree[currentIdx].data) // 더 작은 경우니까 왼쪽으로 내려가야함
            {
                if (tree[currentIdx].left == -1) // 맨끝이니까 더이상 x
                {
                    tree[currentIdx].left = newIdx; // 그럼 그 끝을 새로운 인덱스와 이어줌
                    addFlag = 1;                    // 반복문 마무리
                }

                else // 더 내려가야함
                {
                    currentIdx = tree[currentIdx].left;
                }
            }

            else // 더 큰 경우니까 오른쪽으로 내려가야 함
            {
                if (tree[currentIdx].right == -1) // 맨 끝인 경우
                {
                    tree[currentIdx].right = newIdx;
                    addFlag = 1;
                }

                else // 더 내려가야함
                {
                    currentIdx = tree[currentIdx].right;
                }
            }
        } // while문의 끝
    }
    /*다음에 추가될 요소를 위해 물리적 위치의 인덱스를 1 늘려줌*/
    newIdx++;
}
void printPhysicalBST()

{
    int i;
    for (i = 0; i < newIdx; i++)
    {
        printf("tree[%d] : data =  %d, left = %d, right = %d \n", i, tree[i].data, tree[i].left, tree[i].right);
    }
}

void printLogicalBST(int currentIdx)
{
    if (currentIdx != -1) // 비어있는 인덱스가 아니라면
    {
        printf("tree[%d]: data = %d, left = %d, right = %d\n", currentIdx, tree[currentIdx].data, tree[currentIdx].left, tree[currentIdx].right);

        // 재귀호출
        printLogicalBST(tree[currentIdx].left); // 우선 왼쪽 다보고 그 후에 오른쪽 다 봄
        printLogicalBST(tree[currentIdx].right);
    }
}

int searchBST(int n)
{
    int idx = -1, currentIdx;//찾을 요소, 현재 요소
    currentIdx = rootIdx;

    while(currentIdx != -1)
    {
        if(tree[currentIdx].data == n)//일치하면
        {
            idx = currentIdx;//현재 요소가 찾을 요소이다
            break;//종료
        }
        else if(tree[currentIdx].data > n)//원하는 데이터가 현재 위치 인덱스의 값보다 작은경우
        {
            currentIdx = tree[currentIdx].left;//왼쪽으로 이동
        }
        else
        {
            currentIdx = tree[currentIdx].right;//오른쪽으로 이동
        }

    }
    return idx;//찾은 값 반환
}

int searchRecBST(int x, int currentIdx)
{
    if(currentIdx == -1)
        return -1;
    else{
        if(tree[currentIdx].data == x)
        {
            return currentIdx;
        } else if(tree[currentIdx].data > x) {
            return searchRecBST(x, tree[currentIdx].left);
        } else{
            return searchRecBST(x, tree[currentIdx].right);
        }
        
    }
}
