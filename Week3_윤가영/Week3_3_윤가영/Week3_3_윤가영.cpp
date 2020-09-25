#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

void elementGeneration(int arrPtr[], int arrSize) //사용자가 원하는 크기의 배열을 입력받습니다.
{
    for(int i = 0; i < arrSize; i++) scanf("%d", arrPtr+i);
    elementPrint(arrPtr, arrSize); //입력받은 배열을 출력합니다.
}

void elementInsertion(int arrPtr[], int* arrSize) //배열에 원소를 삽입합니다.
{
    int insLoc, insValue; //insLoc: 삽입 위치, insValue: 삽입할 값
    printf("Input location and value to insert\n");
    scanf("%d%d", &insLoc, &insValue);
    if(insLoc < 1 || insLoc > *arrSize){ //사용자가 입력한 삽입 위치 값이 범위를 벗어날 경우 함수를 종료합니다.
        printf("Choose between 1 and %d\n\n", *arrSize);
        return;
    }
    int insIdx = insLoc - 1; //사용자가 입력한 위치는 배열 인덱스 상으로 1 더 적으니까요..
    for(int i = *arrSize - 1; i >= insIdx; i--) arrPtr[i+1] = arrPtr[i]; //한칸씩 뒤로 값을 대입해줍니다.
    arrPtr[insIdx] = insValue; //위의 for문에서 삽입위치+1 번째 원소까지 값을 바꿔주었으므로, 마지막으로 삽입위치에 사용자 입력값을 대입합니다.
    *arrSize = *arrSize + 1; //배열의 (실질적인 값) 길이가 1개 더 늘어났으므로 1 증가시켜줍니다.
    elementPrint(arrPtr, *arrSize);
}

void elementDeletion(int arrPtr[], int* arrSize) //배열의 원소를 삭제하는 함수입니다.
{
    int delLoc; //삭제할 원소의 위치(사용자 입력)를 저장할 변수
    printf("Input location to delete\n");
    scanf("%d", &delLoc);

    if(delLoc < 1 || delLoc > *arrSize){ //범위를 벗어날 경우 함수를 종료합니다.
        printf("No element in location %d\n\n", delLoc);
        return;
    }
    int delIdx = delLoc - 1; //인덱스 = 입력값 - 1
    for(int i = delIdx; i < *arrSize; i++) arrPtr[i] = arrPtr[i+1]; //원소들을 한칸씩 앞으로 당겨줍니다.
    arrPtr[*arrSize] = 0; //마지막으로, 원래 마지막 인덱스의 값을 0으로 없애줍니다.

    *arrSize = *arrSize - 1; //배열의 사이즈도 줄여줍니다.
    elementPrint(arrPtr, *arrSize); //결과를 출력합니다.
}

void elementPrint(int arrPtr[], int arrSize)
{
    printf("Array:");
    for(int i = 0; i < arrSize; i++) printf("%3d", arrPtr[i]); //원소를 출력합니다.
    printf("\n\n");
}

int main(void) {
    myInfo();

    int numCount, i, v;
    int arr[MAX_SIZE];

    printf("How many numbers? ");
    scanf("%d", &numCount);
    printf("Input %d numbers\n", numCount);

    elementGeneration(&arr, numCount);

    while(1) //반복문
    {
        printf("Choose operation:\n1. insertion 2. deletion 3.output 0:program end\n");

        scanf("%d", &v);
        switch(v) {
            case 0: exit(0); break; //프로그램 종료
            case 1:
                elementInsertion(arr, &numCount); //원소 삽입
                break;
            case 2:
                elementDeletion(arr, &numCount); //원소 삭제
                break;
            case 3:
                elementPrint(arr, numCount); //배열 출력
                break;
            default: break;
        }
    }
}
