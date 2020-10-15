#include <stdio.h>
#include <stdlib.h>

void myInfo(void);
typedef int element;

typedef struct Node {
    element item; //��尪
    Node* llink;
    Node* rlink; //���� ����
}Node;

typedef struct ListType { //���߿������Ḯ��Ʈ
    Node* head;
}ListType;

void init(ListType* plist) { //���ο� ���� ����Ʈ �ʱ�ȭ
    plist->head = NULL;
}

bool isEmpty(ListType* plist){ //����Ʈ�� ������� �˷��ִ� �Լ�
    return (plist->head == NULL);
}

void insertLast(ListType* plist, element val) { //����Ʈ�� �������� ��带 �߰��ϴ� �Լ�
    Node* newNode = (Node*) malloc(sizeof(Node)); //���ο� ��� ����
    newNode->item = val; //���ο� ��忡 �� �ֱ�

    if(newNode == NULL){
        printf("memory allocation error\n");
        exit(1);
    }
    if(isEmpty(plist)) { //���� ����Ʈ�� ��尡 ������
        plist->head = newNode; //���ο� ��尡 ����尡 �ȴ�.
        newNode->rlink = newNode->llink = newNode; //���� ��ũ�� ��� �ڱ��ڽ��� ����Ŵ.
    }
    else{
        newNode->llink = plist->head->llink; //������ ������ ��带 ���ο� ��尡 ����Ų��.
        newNode->rlink = plist->head; //���ο� ��尡 ����带 ����Ų��.
        newNode->llink->rlink = newNode; //������ ������ ��尡 ���� ����尡 �ƴ� ���ο� ��带 ����Ų��.
        plist->head->llink = newNode; //����尡 ���ο� ��带 ����Ų��.
    }
}

void printList(ListType* plist) { //������� ����Ʈ ��Ҹ� ����ϴ� �Լ�
    Node* pnode = plist->head; //��� ������

    //pnode�� �������� ���������� �Űܰ��鼭 �ش� ����� item�� ����Ѵ�.
    for(pnode=plist->head; pnode->rlink!=plist->head; pnode = pnode->rlink) {
        printf("%2d <->", pnode->item);
    }
    //���������� ȭ��ǥ�� ����ϸ� �ȵǴϱ� ����.
    printf("%2d\n", pnode->item);
}

void printReverse(ListType* plist) {
    Node* pnode;

    //pnode�� ������������ �Űܰ��鼭 �ش� ����� item�� ����Ѵ�.
    for(pnode=plist->head->llink; pnode!=plist->head; pnode = pnode->llink) {
        printf("%2d <->", pnode->item);
    }
    //���������� ȭ��ǥ�� ����ϸ� �ȵǴϱ� ���� ���.
    printf("%2d\n", pnode->item);
}
int main(void) {
    myInfo();

    //����Ʈ ����ü ����
    ListType list;
    //����Ʈ �ʱ�ȭ
    init(&list);

    printf("Input data in dual linkedlist (0 to quit)\n");
    int inputVal;
    while(1){
        scanf("%d", &inputVal);
        if(inputVal == 0) break;
        insertLast(&list, inputVal);
    }
    printList(&list);
    printf("Print the list in reverse order\n");
    printReverse(&list);
    return 0;
}

void myInfo(void){
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}
