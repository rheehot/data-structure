#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {
    int coef; //항의 계수
    int exp; //항의 차수
    ListNode* next;
}ListNode;

typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

ListType* create(void) { //리스트를 생성하여 그 리스트의 포인터를 반환하는 함수
    ListType* plist = (ListType*) malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
    return plist;
}

void addLast(ListType* l, int coef, int exp) { //리스트의 마지막에 새로운 노드 추가
    ListNode* pNode = (ListNode*) malloc(sizeof(ListNode));
    //새로운 노드 초기화하기
    pNode->coef = coef;
    pNode->exp = exp;
    pNode->next = NULL;

    //만약 노드가 비어있으면(head가 NULL)
    if(l->head==NULL) l->head = l->tail = pNode;
    else { //비어있지 않으면
        l->tail->next = pNode; //꼬리 노드가 새로운 노드를 가리키도록 한다.
        l->tail = pNode; //새로운 노드가 꼬리가 된다.
    }
    l->size++; //리스트의 요소 개수 증가.
}

void printList(ListType* plist) { //리스트 출력함수
    printf("<Polynomial>\n");
    ListNode* p = plist->head;

    //리스트의 사이즈를 알 수 있으므로 사이즈 이용해서 반복.
    for(int i = 0; i< plist->size-1;i++, p=p->next)
        printf("%dx^%d + ", p->coef, p->exp);
    printf("%dx^%d\n", p->coef, p->exp);
}

int calcList(ListType* plist, int val) { //다항식 계산 함수
    int sol = 0; //반환값

    //리스트의 각 노드 별(항 별)로 계산해서 sol에 더할 것임.
    ListNode* p = plist->head;
    for(int i = 0; i < plist->size-1;i++, p=p->next) {
        sol += p->coef*pow(val, p->exp);
    }
    sol += p->coef;
    return sol;
}

void myInfo(void){
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

int main(void) {
    myInfo();

    ListType* poly = create(); //새로운 리스트: poly 생성

    printf("Input coef and exponent of polynomial<마지막항: exponent를 0으로 입력>\n");

    int inCo, inEx; //사용자 입력 계수, 차수

    while(1) { //사용자가 상수항을 입력할 때까지
        scanf("%d%d", &inCo, &inEx);
        addLast(poly, inCo, inEx); //입력받은 계수, 차수로 리스트의 마지막에 새로운 노드 생성
        if(inEx == 0) break;
    }

    printList(poly);

    //x 입력받고 대입하기.
    int x;
    printf("Input the value x: ");
    scanf("%d", &x);
    printf("Result of polynomial with x: %d", calcList(poly, x));

    free(poly);

    return 0;
}
