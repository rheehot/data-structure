#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode{
    element data;
    struct StackNode* link;
}StackNode;

typedef struct {
    StackNode* top;
}LinkedStackType;

void init(LinkedStackType *s) {
    s->top = NULL;
}

void error(const char X[]) {
    fprintf(stderr, X);
}

bool is_full(LinkedStackType *s) { //full인 상황이 없음. 근데 왜 쓰셨어요 교수님..?
    return 0;
}

bool is_empty(LinkedStackType *s) {
    return (s->top == NULL);
}

element pop(LinkedStackType *s) {
    if(is_empty(s)) {
        error("stack empty");
        exit(1);
    } else {
        StackNode* temp = s->top;
        element data = temp->data;
        s->top = temp->link;
        free(temp);
        return data;
    }
}

void push(LinkedStackType *s, element item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top=temp;
}

void print_stack(LinkedStackType* s) {
    for (StackNode* p = s->top; p!=NULL; p=p->link) {
        printf("%d ->", p->data);
    }
    printf("NULL\n");
}

int main(void) {
    LinkedStackType s;
    init(&s);
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s); //stack empty 상황
    return 0;
}
