#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct stack {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void push(StackType* s, element item) {
    s->data[++s->top] = item;
}

element pop(StackType* s) {
    return s->data[s->top--];
}

bool is_empty(StackType* s) {
    return s->top == -1;
}

bool parenth_check(char* X) {
    StackType* s = (StackType*)malloc(sizeof(StackType));
    s->top = -1;
    char open_ch, ch;
    for(int i = 0; i < strlen(X); i++) {
        ch = X[i];
        switch (ch) {
        case '(': case '[': case '{':
            push(s, ch);
            break;
        case ')': case ']': case '}':
            if (is_empty(s)) {return false;}
            else {
                open_ch = pop(s);
                if(((open_ch == '(' && ch != ')') ||
                    (open_ch == '{' && ch != '}') ||
                    (open_ch == '[' && ch != ']')))
                return false;
            }
            break;
        }
    }
    if (!is_empty(s)) return false;
    return true;
}

int main(void) {
    char str[100];
    printf("Input expression\n");
    gets(str);
    if (parenth_check(str)) printf("Correct\n");
    else printf("Incorrect\n");
    return 0;
}
