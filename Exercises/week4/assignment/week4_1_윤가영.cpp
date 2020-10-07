#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    ListNode* link;
}ListNode;

void print_list(ListNode* head) { //���Ḯ��Ʈ ����Լ��Դϴ�.
    ListNode* p = NULL;
    for(p = head; p != NULL; p = p->link) //�ݺ����� ����Ͽ� data���� ����մϴ�.
        printf("%d ", p->data);
    putchar('\n'); //������ ���� �ڿ� ���� ���
}



ListNode* insert_last(ListNode* head, element val) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //���ο� ��� p ����

    p->data = val; //p�� �����ʹ� val
    p->link = NULL; //p�� ������ ��尡 �Ǿ���ϹǷ� p�� ��ũ�� NULL�̴�.

    if(head == NULL){ //���� ����Ʈ�� ����ִٸ� p�� ù��° ���� ���ϴ�.
        head = p; //���� head�� p�� ����Ű�� �˴ϴ�.
        return head;
    }

    ListNode* temp = head; //��� �����͸� temp�� �����Ѵ�.
    while(temp->link != NULL) temp = temp->link; //temp�� ������ ������ ��带 ����Ű�� �Ѵ�.
    temp->link = p; //������ ������ ����� ��ũ�� ���� p�� ����Ų��.
    return head; //��带 ��ȯ�Ѵ�.
}

element max_element(ListNode* head) { //���� ū ���� ���ϴ� �Լ��Դϴ�.
    ListNode* p = head;
    int max = p->data; //ù��° ���ҷ� max���� �ʱ�ȭ�մϴ�.
    for(p = head->link; p != NULL; p = p->link){
        if(p->data > max) max = p->data;
    }
    return max;
}

element min_element(ListNode* head) { //���� ���� ���� ���ϴ� �Լ��Դϴ�.
    ListNode* p = head;
    int min = p->data; //ù��° ���ҷ� min���� �ʱ�ȭ �մϴ�.
    for(p = head->link; p != NULL; p = p->link){
        if(p->data < min) min = p->data;
    }
    return min;
}

void freeNodes(ListNode* head) { //���Ḯ��Ʈ�� �޸𸮸� �����ϴ� �Լ��Դϴ�.
    ListNode* p = NULL;
    while(head != NULL) { //�������Ʈ�� ���� ��带 ����Ű���� ��� �ű�鼭 �ݺ�, �������� ��尡 NULL�Դϴ�.
        p = head;
        head = head->link;
        free(p);
    }
}

int main(void) {
    int n;
    ListNode* head = NULL; //���Ḯ��Ʈ�� ù��° ��带 ����ų head �������Դϴ�.
    while(1){
        printf("Input an integer to add <0 to quit>: ");
        scanf("%d", &n);
        if(n == 0) break; //����ڰ� 0�� �Է��ϸ� �ݺ����� Ż���մϴ�.
        head = insert_last(head, n); //����ڰ� �Է��� ���� ���Ḯ��Ʈ�� �����մϴ�.
    }

    printf("\n<List>\n");
    print_list(head); //����Ʈ�� ����մϴ�.
    printf("Max: %d Min: %d\n", max_element(head), min_element(head));

    freeNodes(head); //���Ḯ��Ʈ�� ���� �޸𸮸� �����մϴ�.

    return 0;
}
