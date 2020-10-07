#include <stdio.h>

void myInfo(void);

int main(void) {
    myInfo(); //학과학번성명 출력

    int n; //사용자 입력값 저장 변수
    printf("양의정수 입력: ");
    scanf("%d", &n);

    int binNum[100] = { 0 }; //2로 나눈 몫들을 계산하는 순서대로 저장할 배열 초기화.

    int i; //i는 반복문 안에서 index로도 쓰이고 나눈 횟수(변환한 이진수의 자릿수)를 저장하는 용도로도 쓰인다.
    for(i = 0; n > 0; i++){
        binNum[i] = n % 2; //2로 나눈 나머지를 저장합니다.
        n /= 2; //n에 2로 나눈 몫을 저장합니다.
    }

    printf("십진수 %d의 이진표현: ", n);
    for(int j = i-1; j>=0; j--) printf("%d", binNum[j]); //binNum에 i자리 이진수가 거꾸로 저장되어 있으므로 출력할 때 i-1 부터 0번째까지 거꾸로 출력합니다.

    return 0;
}


void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}
