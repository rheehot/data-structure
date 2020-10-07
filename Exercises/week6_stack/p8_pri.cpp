#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct StackType{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

void error(const char X[]) {
    fprintf(stderr, X);
}

bool is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

bool is_empty(StackType *s) {
    return (s->top == -1);
}

element pop(StackType *s) {
    if (is_empty(s)) {
        error("Stack empty");
        exit(1);
    }
    else return s->data[(s->top)--];
}

void push(StackType *s, element item) {
    if(is_full(s)) {
        error("Stack Overflow");
        return;
    }
    else s->data[++(s->top)] = item;
}

element peek(StackType *s){
    if (is_empty(s)) {
        error("stack empty");
        exit(1);
    }
    else return s->data[s->top];
}

int pri(char ch) {
    switch(ch) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char *X) {
    int op;
    char ch, top_op;
    StackType s;
    init_stack(&s);

    for(int i = 0; i < strlen(X); i++) {
        ch = X[i];
        switch(ch) {
        case '+': case '-': case '*': case '/': //연산자인 경우
            while (!is_empty(&s) && pri(peek(&s)) >= pri(ch)) {
                printf("%c", pop(&s));
            }
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while(top_op != '(') {
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c", ch); //피연산자일 경우 그냥 출력, 스택에 저장하지 않는다!
        }//end of switch
    }//end of for
    while(!is_empty(&s)) printf("%c", pop(&s)); //스택에 남아있는 모든 연산자들을 출력!
}

int main(void) {
    char X[100];
    printf("Input an infix expression\n");
    gets(X);
    printf("<result>\n");
    infix_to_postfix(X);
    printf("\n");
    return 0;
}
