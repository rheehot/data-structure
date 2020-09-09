#include <stdio.h>

void myInfo(void);
void rec(int);
void iter(int);
int main(void) {
    myInfo(); //학과학번성명 출력 함수

    int n; //사용자 입력값 저장 변수
    printf("양의 정수 입력:");
    scanf("%d", &n);

    printf("반복함수호출:"); iter(n); //저는 함수 안에서 출력하도록 만들었기 때문에 답을 출력하기 위해 호출만 했습니다.
    printf("\n");
    printf("재귀함수호출:"); rec(n); //재귀도 마찬가지입니다.

    return 0;
}


void rec(int n) { //recursive 방법을 이용한 함수입니다. 파라미터는 양수라는 문제 조건이 있습니다.
    printf("%d ", n);
    if(n>0) rec(n-1); //n이 양수이면 재귀 호출을 합니다. 그래서 0이 되면 함수는 종료됩니다.
}

void iter(int n) { //iterative를 이용한 함수입니다.
    for (int i = n; i >= 0; i--) printf("%d ", i); //역순으로 파라미터 자기자신을 출력합니다.
}
void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}
