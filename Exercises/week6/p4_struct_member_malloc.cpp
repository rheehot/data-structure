#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackType {
    element *data; // ������ �������� �Ҵ��ϰ� �̸� data�� ����Ű���� ��
    int capacity; // ���� �����Ҵ� ���� �迭�� ũ��
    int top;
}StackType;

void init_stack(StackType* s) {
    s->capacity = 1;
    s->top = -1;
    s->data = (element*)malloc(s->capacity*sizeof(element)); //1�� ��� ������� �켱 �����Ҵ�
}

void error(const char X[]) {
    fprintf(stderr, X);
}

bool is_full(StackType* s) {
    return (s->top == (s->capacity - 1));
}

bool is_empty(StackType* s) {
    return (s->top == -1);
}

element pop(StackType* s) {
    if(is_empty(s)) {
        error("Stack Empty");
        exit(1);
    }
    else return s->data[(s->top)--];
}

void push(StackType* s, element item) {
    if(is_full(s)) {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

int main(void) {
    StackType s; // ����ü ���� s ����
    init_stack(&s); // call by reference
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s)); //stack empty ��Ȳ
    free(s.data);
    return 0;
}
