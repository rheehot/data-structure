#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dListNode {
     element data;
     struct dListNode *llink;
     struct dListNode *rlink;
}dListNode;

void init(dListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert(dListNode* pnode, element val) {
    dListNode *newNode = (dListNode*)malloc(sizeof(dListNode));

    newNode->data = val;
    newNode->rlink = pnode->rlink; //pnode->rlink 는 'head노드'를 가리킴!!
    newNode->rlink->llink = newNode;

    newNode->llink = pnode;
    pnode->rlink = newNode;
}

void ddelete(dListNode*head, dListNode* removed) { //맨 앞에 있는 노드 removed를 delete함.
    if(removed == head) return;
    removed->rlink->llink = head;
    head->rlink = removed->rlink;
    free(removed);
}

void print_dlist(dListNode* phead) {
    dListNode* p = NULL;
    for(p=phead->rlink; p != phead; p = p->rlink)
        printf("%3d ", p->data);
    printf("\n");
}

int main(void) {
    dListNode* head = (dListNode*)malloc(sizeof(dListNode));

    init(head);
    printf("첫 위치에 노드 5개 순차적 추가\n");
    for(int i = 1; i < 6; i++) {
        dinsert(head, i);
        print_dlist(head);
    }

    printf("첫 번째 노드 5개 순차적 삭제\n");
    print_dlist(head);

    for(int i = 1; i < 6; i++) {
        ddelete(head, head->rlink);
        print_dlist(head);
    }
    free(head);
    return 0;
}
