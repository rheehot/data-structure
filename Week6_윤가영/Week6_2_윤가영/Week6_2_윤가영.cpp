#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element; //스택에 쌓을 자료형: char

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

element peek(StackType *s){ //스택의 마지막 element 반환. top은 그대로.
    if (is_empty(s)) {
        error("stack empty");
        exit(1);
    }
    else return s->data[s->top];
}

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

void sol(char X[]) {
    StackType s; //문제 풀 때 쓸 스택 구조체
    init_stack(&s); //스택 초기화

    int alphaCnt = 0; //알파벳 개수 세기
    char alpha = 0; //알파벳 저장 변수

    for(int i = 0; i < strlen(X); i++) {
        if(is_empty(&s)) push(&s, X[i]); //비어있으면 그냥 push
        else{
            if(peek(&s) != X[i]){ // 스택의 top 알파벳(peek)과 다르면
                while(!is_empty(&s)){ //empty 될 때까지 pop
                    alpha = pop(&s);
                    alphaCnt++;
                }
                printf("%d%c", alphaCnt, alpha); //pop한 알파벳과 그 개수 출력!
                alphaCnt = 0; //개수 세는 변수 초기화
            }
            push(&s, X[i]); //이전과 같은 알파벳이면 그냥 스택에 넣기
        }
    }
    while(!is_empty(&s)){ //마지막 알파벳은 (다른 알파벳이 나오지 않았으니) 지워지지 않아서 알파벳이 남아있을 것이다.
        alpha = pop(&s);
        alphaCnt++;
    }
    printf("%d%c\n\n", alphaCnt, alpha); //마지막 알파벳을 개수와 함께 출력!
}

int main(void) {
    myInfo();
    char str[100] = {0}; //입력값 저장할 문자열 초기화
    while(1) {
        printf("반복되는 알파벳으로 구성된 문자열 입력(종료시 \"0\"입력)\n");
        scanf("%s", str);
        if(strcmp(str, "0") == 0) break; //"0" 입력 시 탈출
        sol(str);
    }
}
