#include <stdio.h>
#include <malloc.h>
#define MAX_LENGTH 100

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element val) {
    ListNode* p = (ListNode*) malloc(sizeof(ListNode));
    p->data = val;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element val) {
    ListNode* p = (ListNode*) malloc(sizeof(ListNode));
    p->data = val;
    p->link = pre->link;
    pre->link = p;
    return head; //head°¡ ¹¹Áö?
}

ListNode* delete_first(ListNode* head)
{
    if(head == NULL) return NULL;
    ListNode* removed = NULL;
    removed = head;
    head = head->link;
    free(removed);
}

ListNode* del(ListNode* head, ListNode* pre)
{
    ListNode* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

ListNode* search_list(ListNode* head, element val)
{
    ListNode* p = NULL;
    bool found = false;
    for(p = head; p->link != NULL; p = p->link)
    {
        if(p->data == val)
        {
            found = !found;
            break;
        }
    }
    if(found) printf("%d is in the list\n", val);
    else printf("%d is not in the list\n", val);
    return head;
}

ListNode* concat_list(ListNode* headA, ListNode* headB)
{

    if(headA == NULL) {
        if(headB == NULL) return NULL;
        else return headB;
    }
    if(headB == NULL) {
        if(headA == NULL) return NULL;
        else return headA;
    }
    ListNode* p = NULL;
    p = headA;
    while(p->link != NULL) p = p->link;
    p->link = headB;
    return headA;
}

ListNode* reverse_list(ListNode* head)
{
    ListNode *p, *q, *r;
    p = head;
    q = r = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

void print_list(ListNode* head)
{
    for(ListNode* p = head; p->link != NULL; p = p->link)
        printf("%d->", p->data);
    printf("%d", p->data);
}

int main(void)
{
    ListNode* head = NULL;
    int num;
    for(int i = 0; i < 5; i++){
        head = insert_first(head, i);
        print_list(head);
    }
    search_list(head, 2);
    search_list(head, 7);

    ListNode* headB = NULL;
    for(int i = 6; i < 10; i++){
        headB = insert_first(headB, i);
        print_list(headB);
    }

    head = concat_list(head, headB);
    print_list(head);
    head = reverse(head);
    print_list(head);
    return 0;
}
