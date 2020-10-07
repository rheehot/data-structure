#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef int element;

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
    return (s->top == (MAX_STACK_SIZE -1));
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


int eval(char* X) {
    int op1, op2;
    char ch;
    StackType s;
    init_stack(&s);

    for(int i = 0; i < strlen(X); i++) {
        ch = X[i];
        if(ch != '+' && ch != '-' && ch != '/')
            push(&s, ch-'0');
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+': push(&s, op1+op2); break;
            case '-': push(&s, op1-op2); break;
            case '*': push(&s, op1*op2); break;
            case '/': push(&s, op1/op2); break;
            default:
                error("expression error\n");
            }
        }
    }
    return pop(&s);
}

int main(void)
{
    char X[100];
    printf("후위표기식 입력(정수와 사칙연산으로만 구성)\n");
    gets(X);
    printf("result: %d\n", eval(X));
    return 0;
}

