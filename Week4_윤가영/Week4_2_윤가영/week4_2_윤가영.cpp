#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode{ //����ü ���� �Դϴ�. ��ũ�� ��������� ��� �ֽ��ϴ�.
    element data;
    ListNode* llink;
    ListNode* rlink;
}ListNode;

void init(ListNode* phead) { //����Ʈ�� �ʱ�ȭ�ϴ� �Լ��Դϴ�.
    phead->llink = phead; //������ ���� ��ũ�� ��� �ڱ� �ڽ��� ����ŵ�ϴ�.
    phead->rlink = phead;
}

void print_list(ListNode* head){ //��帮��Ʈ�� ���Ҹ� ����ϴ� �Լ��Դϴ�. �Ű������� ����ִ� ��� '���'�Դϴ�.
    ListNode* p = NULL;
    printf("<LIST>\n");
    for(p = head->rlink; p->rlink != head; p = p->rlink) //ù��° ������ data�� ����մϴ�. ������ ���� ��带 ����Ű�Ƿ� ������� ���ؿ�.
        printf("%3d", p->data);
    printf("%3d\n", p->data); //�׷��� �������� �ѹ� �� ������ݴϴ�.
}

ListNode* insert_first(ListNode* head, element val) { //ù��° ��忡 �������ִ� �Լ��Դϴ�. ��ȯ���� head ����Դϴ�.
    ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //���ο� ��� ����
    node->data = val; //��忡 ���ϴ� �� ����ֱ�
    if(head == head->rlink){ //���� ����Ʈ�� ����常 �����ϰ� ���� ���
        head->rlink = head->llink = node; //����� ������� ��� ���� ���� ��带 ����ŵ�ϴ�.
        node->llink = node->rlink = head; //���������� ���� ���� ��嵵 ����� ��� ��带 ����ŵ�ϴ�.
    }
    else {
        node->rlink = head->rlink; //���ο� ����� ������ ��ũ�� ���� ù���翡 �ִ� ��带 ����ŵ�ϴ�.
        node->llink = head; //���ο� ����� ���� ��ũ�� ��� ��带 ����Ű���մϴ�.

        node->rlink->llink = node; //���� ù��°���� ����� ���� ��ũ�� ���ο� ��带 ����Ű�� �մϴ�.
        head->rlink = node; //����� ������ ��ũ�� ���ο� ��带 ����Ű�� �մϴ�.
    }
    return head;
}

ListNode* search_delete(ListNode* head, element val) { //����忡�� ���� ����!
    ListNode* p = NULL;
    bool found = false;
    p = head->rlink; //ù��° ���� ����� ���� ����̹Ƿ� rlink�� ����Ű�� ����Դϴ�.
    do { //�˻� ����
        if(p->data == val) { //data�� ��ġ�ϴ� ��� p�� ������ ��
            found = true;
            //�� ���� ����� p�� ������ ���� ���� �ִ� ���� ���� �̾��ݴϴ�.
            p->rlink->llink = p->llink;
            p->llink->rlink = p->rlink;
            free(p); //p ����
            break;
        }
        p = p->rlink;
    }while(p->rlink != head);

    if(found){
        printf("%d is found and deleted\n", val);
    }
    else{
        printf("%d is not in the list\n", val);
    }
    return head;
}

int main(void) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //head ��� ����
    init(head); // ����Ʈ �ʱ�ȭ!
    int n; //������� �Է��� ������ ����
    while(1) {
        printf("Input an integer to add<0 to quit>: ");
        scanf("%d", &n);
        if(n == 0) break;
        head = insert_first(head, n);
    }
    print_list(head); //����ڿ��� �Է¹��� ����Ʈ ���
    printf("Input the number to search and delete: ");
    scanf("%d", &n);
    head = search_delete(head, n); //���Ҹ� ������ �� ��� ���, ����Ʈ ��ȯ
    print_list(head); //���
    free(head);
}
