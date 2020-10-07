#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element; //���ڸ� �����ϴ� ������ �ʿ��ϹǷ� element�� �ڷ����� int.
typedef struct StackType{ //���� ����ü: �ȿ� �迭�� top element�� index�� �����ϴ� ������ �ִ�.
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) { //���� �ʱ�ȭ �Լ�
    s->top = -1;
}

void error(const char X[]) { //���� �Լ�
    fprintf(stderr, X);
}

bool is_full(StackType *s) { //������ �� á���� boolean ��ȯ
    return (s->top == (MAX_STACK_SIZE - 1));
}

bool is_empty(StackType *s) { //������ ������� boolean ��ȯ
    return (s->top == -1);
}

element pop(StackType *s) { // ������ ������ element ��ȯ �� top ����
    if (is_empty(s)) {
        error("Stack empty");
        exit(1);
    }
    else return s->data[(s->top)--];
}

void push(StackType *s, element item) { // ���ÿ� ���ο� element �ֱ�
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
    printf("������ ǥ��: ");
    while(!is_empty(s)) {
        printf("%d", pop(s));
    }
    printf("\n");
}

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

int main(void) {
    myInfo();
    int n;
    StackType s;
    while(1) {
        printf("������ �Է�(����: 0 ���� �Է�)\n");
        scanf("%d", &n);
        if(n<=0) break;
        decimalToBinary(&s, n);
    }
}
