#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element val){ //head澗 戚薦 原走厳 element研 亜軒轍陥!!!!! 爽税!!
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
    node->data = val; //汽戚斗研 照隔生檎 嬢怯背..せせせせせせせせせせせせせせせせ
    if(head == NULL) {
        head = node;
        node->link = head;
    }
    else { //奄常背... 据莫拭辞 head澗 原走厳 据社研 亜軒轍陥.... 爽税背...
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

void print_clist(ListNode*head) {
    ListNode* p = NULL;
    if(head == NULL) return;
    p = head->link; //p澗 湛腰属 element研 亜軒轍陥.
    do {
        printf("%3d -> ", p->data);
        p = p->link;
    }while(p != head->link); //戚背亜 照吉陥.. 訊 原走厳猿走 設 窒径鞠澗 杏猿
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



