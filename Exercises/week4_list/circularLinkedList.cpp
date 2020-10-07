#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element val){ //head는 이제 마지막 element를 가리킨다!!!!! 주의!!
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
    node->data = val; //데이터를 안넣으면 어떡해..ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
    if(head == NULL) {
        head = node;
        node->link = head;
    }
    else { //기억해... 원형에서 head는 마지막 원소를 가리킨다.... 주의해...
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

void print_clist(ListNode*head) {
    ListNode* p = NULL;
    if(head == NULL) return;
    p = head->link; //p는 첫번째 element를 가리킨다.
    do {
        printf("%3d -> ", p->data);
        p = p->link;
    }while(p != head->link); //이해가 안된다.. 왜 마지막까지 잘 출력되는 걸까
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



