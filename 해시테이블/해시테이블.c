#include <stdio.h>

int hashTable[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int hashFunc(int key);

int main()
{
    int data, hashValue;

do{//해시테이블에 점수를 저장
    printf("저장할 데이터 = ");
    scanf("%d", &data);
    if(data < 0) break;

    hashValue = hashFunc(data);
    hashTable[hashValue] = data;
}while(1);

do{//해시테이블 탐색
    printf("탐색할 데이터 = ");
    scanf("%d", &data);
    if(data < 0) break;

    hashValue = hashFunc(data);

    if(hashTable[hashValue] == data){
        printf("%d번째에서 발견되었습니다.\n", hashValue);
    } else{
        printf("데이터를 찾을 수 없습니다.\n");
    }
}while(1);


    return 0;
}

int hashFunc(int key)
{
    return key % 10;
}