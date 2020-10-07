#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element; //숫자를 저장하는 스택이 필요하므로 element의 자료형은 int.
typedef struct StackType{ //스택 구조체: 안에 배열과 top element의 index를 저장하는 변수가 있다.
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) { //스택 초기화 함수
    s->top = -1;
}

void error(const char X[]) { //에러 함수
    fprintf(stderr, X);
}

bool is_full(StackType *s) { //스택이 다 찼는지 boolean 반환
    return (s->top == (MAX_STACK_SIZE - 1));
}

bool is_empty(StackType *s) { //스택이 비었는지 boolean 반환
    return (s->top == -1);
}

element pop(StackType *s) { // 스택의 마지막 element 반환 후 top 조정
    if (is_empty(s)) {
        error("Stack empty");
        exit(1);
    }
    else return s->data[(s->top)--];
}

void push(StackType *s, element item) { // 스택에 새로운 element 넣기
    if(is_full(s)) {
        error("Stack Overflow");
        return;
    }
    else s->data[++(s->top)] = item;
}

void decimalToBinary(StackType* s, int decimal) {
    init_stack(s);
    while(decimal>0) {
        push(s, decimal%2);
        decimal /= 2;
    }
    printf("이진수 표현: ");
    while(!is_empty(s)) {
        printf("%d", pop(s));
    }
    printf("\n");
}

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

int main(void) {
    myInfo();
    int n;
    StackType s;
    while(1) {
        printf("십진수 입력(종료: 0 이하 입력)\n");
        scanf("%d", &n);
        if(n<=0) break;
        decimalToBinary(&s, n);
    }
}
