#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element val){ //head�� ���� ������ element�� ����Ų��!!!!! ����!!
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = val;
    if(head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = val; //�����͸� �ȳ����� ���..��������������������������������
    if(head == NULL) {
        head = node;
        node->link = head;
    }
    else { //�����... �������� head�� ������ ���Ҹ� ����Ų��.... ������...
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

void print_clist(ListNode*head) {
    ListNode* p = NULL;
    if(head == NULL) return;
    p = head->link; //p�� ù��° element�� ����Ų��.
    do {
        printf("%3d -> ", p->data);
        p = p->link;
    }while(p != head->link); //���ذ� �ȵȴ�.. �� ���������� �� ��µǴ� �ɱ�
    printf("%3d \n", p->data);
}

int main(void) {
    ListNode* head = NULL;
    for (int i = 5; i > 0; i--) {
        head = insert_first(head, i);
    }
    print_clist(head);

    head = insert_last(head, 10);
    print_clist(head);
    head = insert_last(head, 20);
    print_clist(head);

    return 0;
}



