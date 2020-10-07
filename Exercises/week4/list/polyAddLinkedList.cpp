#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
}ListNode;

typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

void error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create(void) {
    ListType* plist = (ListType*)malloc(sizeof(ListType));

    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon){
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    if(temp == NULL) error("memory allocation error\n");

    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL) plist->head = plist->tail = temp;
    else{
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_print(ListType* plist){
    ListNode* node = plist->head;
    for(int i = 0; i < plist->size -1; i++, node = node->link)
        printf(" %d*x^%d +", node->coef, node->expon);
    printf(" %d*x^%d\n", node->coef, node->expon);
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3){
    ListNode *p1, *p2;
    p1 = plist1->head;
    p2 = plist2->head;
    int sum;

    while(p1 && p2){
        if(p1->expon > p2->expon) {
            insert_last(plist3, p1->coef, p1->expon);
            p1 = p1->link;
        }
        else if(p1->expon < p2->expon) {
            insert_last(plist3, p2->coef, p2->expon);
            p2 = p2->link;
        }
        else {
            sum = p1->coef + p2->coef;
            if (sum != 0) insert_last(plist3, sum, p1->expon);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while(p1){
        insert_last(plist3, p1->coef, p1->expon);
        p1 = p1->link;
    }
    while(p2){
        insert_last(plist3, p2->coef, p2->expon);
        p2 = p2->link;
    }
}

int main(void)
{
    ListType*list1, *list2, *list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);


    printf("<Poly1>\n");
    poly_print(list1);
    printf("<Poly2>\n");
    poly_print(list2);

    poly_add(list1, list2, list3);
    printf("\n<Poly1 + Poly2>\n");
    poly_print(list3);

    free(list1);
    free(list2);
    free(list3);
    return 0;
}
