#include <stdio.h>
#include <string.h>
#define LENGTH 10

struct StationList
{
    char name[20];
    int next;
};
struct StationList list[LENGTH];
int head;

void initStationList();
void printStationList();
void insertStationList(int, char[], int);
void deleteStationList(int, int);

int main()
{
    initStationList();
    insertStationList(5, "광명", 2);
    //새로 삽입할 노드의 인덱스, 이름, 삽입할 요소의 앞 요소 인덱스
    printStationList();
    
    deleteStationList(5, 2);
    //삭제할 리스트의 인덱스, 그 이전 리스트의 인덱스
    printStationList();

    return 0;
}

void initStationList()
{
    strcpy(list[0].name, "부산");
    list[0].next = -1;
    strcpy(list[1].name, "대전");
    list[1].next = 3;
    strcpy(list[2].name, "서울");
    list[2].next = 4;
    strcpy(list[3].name, "동대구");
    list[3].next = 0;
    strcpy(list[4].name, "천안아산");
    list[4].next = 1;

    head = 2;
}
void printStationList()
{
    int idx = head;
    while(idx != -1)
    {
        printf("[%s] -> ", list[idx].name);
        idx = list[idx].next;
    }
    printf("\n");
}

void insertStationList(int insIdx, char insName[], int prevIdx)
{
    strcpy(list[insIdx].name, insName);
    list[insIdx].next = list[prevIdx].next;//이전 노드의 다음 노드를 삽입할 노드의 다음 노드 연결부위에 연결
    list[prevIdx].next = insIdx;//이전 노드의 연결부위를 삽입노드에 연결
}
void deleteStationList(int delIdx, int prevIdx)
{
    list[prevIdx].next = list[delIdx].next;
}
