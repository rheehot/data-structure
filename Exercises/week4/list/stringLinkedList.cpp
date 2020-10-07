#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
}element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element val)
{
    ListNode*p = (ListNode*) malloc(sizeof(ListNode));
    p->data = val; //val은 구조체 변수다..! 대입연산 가능!!
    p->link = head;
    head = p;
    return head;
}

void print(ListNode* head){
    ListNode* p = NULL;
    for(p = head; p != NULL; p = p->link)
        printf(" %s ->", p->data.name);
    printf(" NULL\n");
}

int main(void){
    ListNode* head = NULL;
    element newData;
    strcpy(newData.name, "Apple");
    head = insert_first(head, newData);
    print(head);
    strcpy(newData.name, "Banana");
    head = insert_first(head, newData);
    print(head);
    return 0;
}
