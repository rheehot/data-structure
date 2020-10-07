#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

void error(const char X[]) {
    fprintf(stderr, X);
}

bool is_full(void) {
    return (top == MAX_STACK_SIZE - 1);
}

bool is_empty(void) {
    return (top == -1);
}

element pop(void){
    if (is_empty()) {
        error("Stack empty");
        exit(1);
    }
    else return stack[top--];
}

element peek(void) {
    if (is_empty()) {
        error("Stack empty");
        exit(1);
    }
    else return stack[top];
}

void push(element item) {
    if (is_full()) {
        error("Stack Overflow");
        return;
    }
    else stack[++top] = item;
}

int main(void) {
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop()); //stack empty
    return 0;
}
