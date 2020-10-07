#include <stdio.h>

void myInfo(void);
float rec(int);
float iter(int);

int main(void) {
    myInfo(); //학과학번성명 출력 함수

    int n; //사용자 입력값 저장 변수
    while(1) { //반복문
        printf("양의 정수 입력: ");
        scanf("%d", &n);
        if(n <= 0) break; //입력값이 0 이하일 경우 반복문을 종료합니다.
        printf("Result from iterative: %.2f\n", iter(n)); //반복함수를 이용해 구한 정답입니다.
        printf("Result from recursive: %.2f\n", rec(n)); //재귀함수를 이용해 구한 정답입니다.
    }

    return 0;
}

float rec(int n) { //정답을 반환하는 재귀함수
    if(n==1) return 1.0; //기저조건은 n이 1일 때 입니다. n이 1인 경우 더이상 재귀 호출을 하지 않고 값을 반환합니다.
    return (float)1/n + rec(n-1); //else: 1부터 1/n-1까지 더한 값을 호출하는 rec(n-1)에 1/n을 더하여 반환합니다.
}

float iter(int n) { //정답을 반환하는 반복함수
    float sol = 1.0; //함수가 반환할 값을 저장할 변수 sol입니다.
    for(int i = 2; i <= n; i++) sol += (float)1/i; //두번째부터 더해줍니다. sol = sol + 1/2 + ... + 1/n
    return sol; //답을 반환합니다.
}

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}
