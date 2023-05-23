#include <stdio.h>

int hashTable[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int hashFunc(int key);

int main()
{
    int data, hashValue;

    /*저장위치, 탐색위치*/
    int pos;

    do
    { // 해시테이블에 점수를 저장
        printf("저장할 데이터 = ");
        scanf("%d", &data);

        if (data < 0)
            break; // 종료조건

        /*해시값을 구해줌*/
        hashValue = hashFunc(data);

        pos = hashValue;
        while (hashTable[pos] != -1)
        { // 해당 해시값이 차있을 경우
            pos++;
            /*맨 마지막 요ㅅ까지 데이터를 저장할 수 없으면 첫번째부터 다시 확인*/
            if (pos >= 10)
            {
                pos = 0;
            }

            /*해시값의 배열 인덱스까지 확인했으면 가득 찬거니까 반복 종료*/
            if (pos == hashValue)
                break;
        }

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = data;
        }
        else
        {
            printf("해시테이블이 가득 찼습니다!\n");
        }
    } while (1);

    do
    { // 해시테이블 탐색
        printf("탐색할 데이터 = ");
        scanf("%d", &data);
        if (data < 0)
            break;

        hashValue = hashFunc(data);
        
        pos = hashValue;

        while(hashTable[pos] != -1 && hashTable[pos] != data)//비어있지 않고 데이터와 일치하지도 않다면
        {
            pos++;

            if(pos >= 10){
                pos = 0;
            } 

            /*데이터를 찾을 수 없었으므로 종료*/
            if(hashTable[pos] == -1 || pos == hashValue){
                break;
            }
        }

        /*탐색결과표시*/
        if(hashTable[pos] == data){
            printf("%d번째에서 발견되었습니다.\n", pos);
        } else{
            printf("데이터를 찾을 수 없습니다.\n");
        }
    } while (1);

    return 0;
}

int hashFunc(int key)
{
    return key % 10;
}