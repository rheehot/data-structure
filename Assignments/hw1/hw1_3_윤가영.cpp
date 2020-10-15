#include <stdio.h>
#include <stdlib.h>

void myInfo(void);


typedef int element;
typedef struct ListNode {
    element item;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element val) { //리스트의 맨 앞에 삽입하는 함수
    ListNode* p = (ListNode*) malloc(sizeof(ListNode)); //노드 하나 malloc으로 만들어 연결
    p->item = val;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element val) { //리스트의 원하는 부분에 삽입하는 함수
    ListNode* p = (ListNode*) malloc(sizeof(ListNode)); //마찬가지로 malloc으로 노드 생성
    p->item = val;
    p->link = pre->link;
    pre->link = p;
    return head;
}


ListNode* insert_sort(ListNode* head, int num) {
    ListNode* pnode = head; //노드 포인터 초기화
    if (pnode == NULL || pnode->item > num) { //헤드노드가 없는 경우/가장 작은 숫자가 들어온 경우
        head = insert_first(head, num); //맨 앞에 노드 삽입
        return head;
    }
    for(pnode = head; pnode->link!=NULL; pnode = pnode->link){ //맨 마지막 노드 전!까지!!! 마지막 노드: pnode->link == NULL
        if(pnode->link->item > num){
            head = insert(head, pnode, num);
            break;
        }
    }
    if(pnode->link == NULL) head = insert(head, pnode, num); //마지막 노드까지 다 돌았다면 가장 큰 숫자라는 얘기니까 마지막에 삽입하기.
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
    ListNode* head = NULL; //노드는 insert함수들이 생성해주니까 malloc 필요 없음

    int inputVal;

    while(1){
        scanf("%d", &inputVal);
        if(inputVal==0) break; //사용자가 0을 입력하면 탈출
        head = insert_sort(head, inputVal); //탈출하지 않았으면 insert
        printList(head); //매번 출력하기
    }
    printf("Program finished.\n");
    return 0;
}

void myInfo(void){
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}
