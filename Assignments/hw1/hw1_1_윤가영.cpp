#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {
    int coef; //���� ���
    int exp; //���� ����
    ListNode* next;
}ListNode;

typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

ListType* create(void) { //����Ʈ�� �����Ͽ� �� ����Ʈ�� �����͸� ��ȯ�ϴ� �Լ�
    ListType* plist = (ListType*) malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
    return plist;
}

void addLast(ListType* l, int coef, int exp) { //����Ʈ�� �������� ���ο� ��� �߰�
    ListNode* pNode = (ListNode*) malloc(sizeof(ListNode));
    //���ο� ��� �ʱ�ȭ�ϱ�
    pNode->coef = coef;
    pNode->exp = exp;
    pNode->next = NULL;

    //���� ��尡 ���������(head�� NULL)
    if(l->head==NULL) l->head = l->tail = pNode;
    else { //������� ������
        l->tail->next = pNode; //���� ��尡 ���ο� ��带 ����Ű���� �Ѵ�.
        l->tail = pNode; //���ο� ��尡 ������ �ȴ�.
    }
    l->size++; //����Ʈ�� ��� ���� ����.
}

void printList(ListType* plist) { //����Ʈ ����Լ�
    printf("<Polynomial>\n");
    ListNode* p = plist->head;

    //����Ʈ�� ����� �� �� �����Ƿ� ������ �̿��ؼ� �ݺ�.
    for(int i = 0; i< plist->size-1;i++, p=p->next)
        printf("%dx^%d + ", p->coef, p->exp);
    printf("%dx^%d\n", p->coef, p->exp);
}

int calcList(ListType* plist, int val) { //���׽� ��� �Լ�
    int sol = 0; //��ȯ��

    //����Ʈ�� �� ��� ��(�� ��)�� ����ؼ� sol�� ���� ����.
    ListNode* p = plist->head;
    for(int i = 0; i < plist->size-1;i++, p=p->next) {
        sol += p->coef*pow(val, p->exp);
    }
    sol += p->coef;
    return sol;
}

void myInfo(void){
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

int main(void) {
    myInfo();

    ListType* poly = create(); //���ο� ����Ʈ: poly ����

    printf("Input coef and exponent of polynomial<��������: exponent�� 0���� �Է�>\n");

    int inCo, inEx; //����� �Է� ���, ����

    while(1) { //����ڰ� ������� �Է��� ������
        scanf("%d%d", &inCo, &inEx);
        addLast(poly, inCo, inEx); //�Է¹��� ���, ������ ����Ʈ�� �������� ���ο� ��� ����
        if(inEx == 0) break;
    }

    printList(poly);

    //x �Է¹ް� �����ϱ�.
    int x;
    printf("Input the value x: ");
    scanf("%d", &x);
    printf("Result of polynomial with x: %d", calcList(poly, x));

    free(poly);

    return 0;
}
