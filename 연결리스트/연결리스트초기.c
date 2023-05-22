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

int main()
{
    initStationList();
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