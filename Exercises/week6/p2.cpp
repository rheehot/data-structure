#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s)); // stack empty
    return 0;
}
