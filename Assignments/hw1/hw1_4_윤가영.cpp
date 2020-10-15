#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

void myInfo(void);

const char* solByArr(char s[]) { //����� ���� "��Ī" �Ǵ� "���Ī"�� ��ȯ.
    bool isSymmetric = true;

    //���ڼ��� �ϳ��� ��Ī���� �߽��ϴ�.
    if(strlen(s) == 1) return "��Ī";

    //
    for(int i = 0; i < strlen(s)/2-1; i++){ //ù ��° ���ں��� �߰� ���ڱ��� �ݺ�
        if(s[i] != s[strlen(s)-1-i]) { //��Ī�Ǵ� ���ڿ� ���� ������
            isSymmetric = false; break; //���Ī�̹Ƿ� �ݺ��� Ż��
        }
    }
    if(isSymmetric) return "��Ī";
    return "���Ī";
}

typedef char element;
typedef struct StackType{ //�������� ����ü
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void initStack(StackType* s) { //���� �ʱ�ȭ �Լ�
    s->top = -1;
}

void push(StackType* s, element item) { //push �Լ�
    s->data[++s->top] = item;
}

element pop(StackType* s) { // pop �Լ�
    return s->data[s->top--]; //return top element and
}

bool isStackEmpty(StackType* s) { //������ ������� ��ȯ
    return (s->top == -1);
}


const char* solByStack(char s[]) { //�������� ���� Ǯ��
    bool isSymmetric = true;
    int i, cent;

    StackType* st = (StackType*)malloc(sizeof(StackType)); //����Ÿ�� ����ü �����Ҵ�!
    initStack(st); //���� �ʱ�ȭ

    for(i = 0; i < strlen(s)/2; i++) push(st, s[i]); //�Ű������� ���� ���ڿ��� �ݸ� ���ÿ� ���� �ִ´�. (¦���� ��, Ȧ���� ��� ���� ��������)

    if (strlen(s)%2==0) cent = strlen(s)/2; //���� ���ڿ��� ���̰� ¦���̸� ��Ī �Ǻ��� �ε��� strlen(s)/2���� �Ѵ�.
    else cent = strlen(s)/2 + 1; //���� Ȧ���̸� ��Ī �Ǻ��� �ε��� strlen(s)/2+1���� �Ѵ�(��� ���� ����)

    for(i = cent; i < strlen(s); i++) { //��Ī �˻�: ������ top element�� ���� char�� ����.
        if(pop(st) != s[i]){ //���� ������ ��Ī�� �ƴ�.
            isSymmetric = false;
            break;
        }
    }
    if(isSymmetric) return "��Ī";
    return "���Ī";
}

int main(void) {
    myInfo();

    char X[100] = {0};

    while(1) { //����ڰ� 0�� �Է��� ������ �ݺ�
        printf("���ĺ����� ������ ���ڿ� �Է�\n");

        scanf("%s", X);
        if(strcmp(X, "0") == 0) break;

        //solByArr(X)�� solByStack(X)�� "��Ī" �Ǵ� "���Ī"�� ��ȯ�Ѵ�.
        printf("%s(�迭)\n", solByArr(X));
        printf("%s(����)\n\n", solByStack(X));
    }
    return 0;
}

void myInfo(void){
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}
