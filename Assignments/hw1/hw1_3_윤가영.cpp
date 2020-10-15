#include <stdio.h>
#include <stdlib.h>

void myInfo(void);


typedef int element;
typedef struct ListNode {
    element item;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element val) { //����Ʈ�� �� �տ� �����ϴ� �Լ�
    ListNode* p = (ListNode*) malloc(sizeof(ListNode)); //��� �ϳ� malloc���� ����� ����
    p->item = val;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element val) { //����Ʈ�� ���ϴ� �κп� �����ϴ� �Լ�
    ListNode* p = (ListNode*) malloc(sizeof(ListNode)); //���������� malloc���� ��� ����
    p->item = val;
    p->link = pre->link;
    pre->link = p;
    return head;
}


ListNode* insert_sort(ListNode* head, int num) {
    ListNode* pnode = head; //��� ������ �ʱ�ȭ
    if (pnode == NULL || pnode->item > num) { //����尡 ���� ���/���� ���� ���ڰ� ���� ���
        head = insert_first(head, num); //�� �տ� ��� ����
        return head;
    }
    for(pnode = head; pnode->link!=NULL; pnode = pnode->link){ //�� ������ ��� ��!����!!! ������ ���: pnode->link == NULL
        if(pnode->link->item > num){
            head = insert(head, pnode, num);
            break;
        }
    }
    if(pnode->link == NULL) head = insert(head, pnode, num); //������ ������ �� ���Ҵٸ� ���� ū ���ڶ�� ���ϱ� �������� �����ϱ�.
    return head;
}

void printList(ListNode* head)
{
    ListNode* p;
    for(p = head; p->link != NULL; p = p->link)
        printf("%d->", p->item);
    printf("%d->NULL\n", p->item);
}

int main(void) {
    myInfo();
    printf("Input data to insert to linkedlist(0 to quit)\n");
    ListNode* head = NULL; //���� insert�Լ����� �������ִϱ� malloc �ʿ� ����

    int inputVal;

    while(1){
        scanf("%d", &inputVal);
        if(inputVal==0) break; //����ڰ� 0�� �Է��ϸ� Ż��
        head = insert_sort(head, inputVal); //Ż������ �ʾ����� insert
        printList(head); //�Ź� ����ϱ�
    }
    printf("Program finished.\n");
    return 0;
}

void myInfo(void){
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}
