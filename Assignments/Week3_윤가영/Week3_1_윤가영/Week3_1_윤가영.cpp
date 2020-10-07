#include <stdio.h>
#include <string.h>

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

void func_recursive(char* s) //재귀함수: 매개변수 s는 char 포인터 입니다.
{
   if(*s == '\0') return; //기저조건은 널문자입니다.
   func_recursive(s+1); //재귀함수를 호출합니다. (s+1: 다음 글자의 주소값)
   printf("%c", *s); //s가 가리키는 char를 출력합니다.
}

int main(void)
{
    myInfo();

    char X[100];

    printf("Input string\n");
    gets(X);
    puts("변경전:");
    puts(X);
    puts("변경후:");
    func_recursive(X); //매개변수: 문자열 X의 첫번째 글자의 주소값
    return 0;
}



