#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

void myInfo(void);

const char* solByArr(char s[]) { //결과에 따라 "대칭" 또는 "비대칭"을 반환.
    bool isSymmetric = true;

    //글자수가 하나면 대칭으로 했습니다.
    if(strlen(s) == 1) return "대칭";

    //
    for(int i = 0; i < strlen(s)/2-1; i++){ //첫 번째 글자부터 중간 글자까지 반복
        if(s[i] != s[strlen(s)-1-i]) { //대칭되는 글자와 같지 않으면
            isSymmetric = false; break; //비대칭이므로 반복문 탈출
        }
    }
    if(isSymmetric) return "대칭";
    return "비대칭";
}

typedef char element;
typedef struct StackType{ //스택정보 구조체
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void initStack(StackType* s) { //스택 초기화 함수
    s->top = -1;
}

void push(StackType* s, element item) { //push 함수
    s->data[++s->top] = item;
}

element pop(StackType* s) { // pop 함수
    return s->data[s->top--]; //return top element and
}

bool isStackEmpty(StackType* s) { //스택이 비었는지 반환
    return (s->top == -1);
}


const char* solByStack(char s[]) { //스택으로 문제 풀기
    bool isSymmetric = true;
    int i, cent;

    StackType* st = (StackType*)malloc(sizeof(StackType)); //스택타입 구조체 동적할당!
    initStack(st); //스택 초기화

    for(i = 0; i < strlen(s)/2; i++) push(st, s[i]); //매개변수로 들어온 문자열의 반만 스택에 집어 넣는다. (짝수면 반, 홀수면 가운데 글자 전까지만)

    if (strlen(s)%2==0) cent = strlen(s)/2; //만약 문자열의 길이가 짝수이면 대칭 판별을 인덱스 strlen(s)/2부터 한다.
    else cent = strlen(s)/2 + 1; //만약 홀수이면 대칭 판별을 인덱스 strlen(s)/2+1부터 한다(가운데 글자 까지)

    for(i = cent; i < strlen(s); i++) { //대칭 검사: 스택의 top element와 현재 char를 비교함.
        if(pop(st) != s[i]){ //같지 않으면 대칭이 아님.
            isSymmetric = false;
            break;
        }
    }
    if(isSymmetric) return "대칭";
    return "비대칭";
}

int main(void) {
    myInfo();

    char X[100] = {0};

    while(1) { //사용자가 0을 입력할 때까지 반복
        printf("알파벳으로 구성된 문자열 입력\n");

        scanf("%s", X);
        if(strcmp(X, "0") == 0) break;

        //solByArr(X)와 solByStack(X)는 "대칭" 또는 "비대칭"을 반환한다.
        printf("%s(배열)\n", solByArr(X));
        printf("%s(스택)\n\n", solByStack(X));
    }
    return 0;
}

void myInfo(void){
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}
