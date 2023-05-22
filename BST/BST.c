#include <stdio.h>

struct BST
{
    int data;
    int left, right;
};
struct BST tree[10];//실체 트리
int rootIdx = 0;//루트요소의 물리적 위치
int newIdx = 0;//다음에 저장할 요소의 물리적 위치

void addBST(int);//요소 추가 함수
void printPhysicalBST();//트리 전체 프린트 함수

int main()
{
    addBST(4);
    addBST(6);
    addBST(5);
    addBST(2);
    addBST(3);
    addBST(7);
    addBST(1);

    printPhysicalBST();

    return 0;
}

void addBST(int data)
{
    int currentIdx;//현재 요소의 물리적 위치
    int addFlag;//요소 추가 완료 확인

    /*물리적 위치에 요솟값과 연결 정보 추가*/
    /*맨 처음 루트노드라면 추가되고 종료되는 것임*/
    tree[newIdx].data = data;
    tree[newIdx].left = -1;
    tree[newIdx].right = -1;

    
    if(newIdx != rootIdx)//루트 노드가 아니라면
    {
        currentIdx = rootIdx;
        addFlag = 0;

        while(addFlag == 0)//맨 처음에는 루트노드부터 시작
        {   
            if(data < tree[currentIdx].data)//더 작은 경우니까 왼쪽으로 내려가야함
            {
                if(tree[currentIdx].left == -1)//맨끝이니까 더이상 x
                {
                    tree[currentIdx].left = newIdx;//그럼 그 끝을 새로운 인덱스와 이어줌
                    addFlag = 1;//반복문 마무리
                }

                else//더 내려가야함
                {
                   currentIdx = tree[currentIdx].left;
                }

                
            }

            else//더 큰 경우니까 오른쪽으로 내려가야 함
            {
                 if(tree[currentIdx].right == -1)//맨 끝인 경우
                    {
                        tree[currentIdx].right = newIdx;
                        addFlag = 1;
                    }

                else//더 내려가야함
                {
                    currentIdx = tree[currentIdx].right;
                }
            }
        }//while문의 끝

    }
    /*다음에 추가될 요소를 위해 물리적 위치의 인덱스를 1 늘려줌*/
    newIdx++;

}

void printPhysicalBST()
{
    int i;
    for(i = 0; i < newIdx; i++)
    {
        printf("tree[%d] : data =  %d, left = %d, right = %d \n", i, tree[i].data, tree[i].left, tree[i].right);
    }
}