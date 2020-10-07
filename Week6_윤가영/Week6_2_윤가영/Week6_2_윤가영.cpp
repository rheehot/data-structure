#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element; //���ÿ� ���� �ڷ���: char

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

element peek(StackType *s){ //������ ������ element ��ȯ. top�� �״��.
    if (is_empty(s)) {
        error("stack empty");
        exit(1);
    }
    else return s->data[s->top];
}

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

void sol(char X[]) {
    StackType s; //���� Ǯ �� �� ���� ����ü
    init_stack(&s); //���� �ʱ�ȭ

    int alphaCnt = 0; //���ĺ� ���� ����
    char alpha = 0; //���ĺ� ���� ����

    for(int i = 0; i < strlen(X); i++) {
        if(is_empty(&s)) push(&s, X[i]); //��������� �׳� push
        else{
            if(peek(&s) != X[i]){ // ������ top ���ĺ�(peek)�� �ٸ���
                while(!is_empty(&s)){ //empty �� ������ pop
                    alpha = pop(&s);
                    alphaCnt++;
                }
                printf("%d%c", alphaCnt, alpha); //pop�� ���ĺ��� �� ���� ���!
                alphaCnt = 0; //���� ���� ���� �ʱ�ȭ
            }
            push(&s, X[i]); //������ ���� ���ĺ��̸� �׳� ���ÿ� �ֱ�
        }
    }
    while(!is_empty(&s)){ //������ ���ĺ��� (�ٸ� ���ĺ��� ������ �ʾ�����) �������� �ʾƼ� ���ĺ��� �������� ���̴�.
        alpha = pop(&s);
        alphaCnt++;
    }
    printf("%d%c\n\n", alphaCnt, alpha); //������ ���ĺ��� ������ �Բ� ���!
}

int main(void) {
    myInfo();
    char str[100] = {0}; //�Է°� ������ ���ڿ� �ʱ�ȭ
    while(1) {
        printf("�ݺ��Ǵ� ���ĺ����� ������ ���ڿ� �Է�(����� \"0\"�Է�)\n");
        scanf("%s", str);
        if(strcmp(str, "0") == 0) break; //"0" �Է� �� Ż��
        sol(str);
    }
}
