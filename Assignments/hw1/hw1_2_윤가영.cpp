#include <stdio.h>
#include <stdlib.h>

void myInfo(void);
typedef int element;

typedef struct Node {
    element item; //노드값
    Node* llink;
    Node* rlink; //이중 연결
}Node;

typedef struct ListType { //이중원형연결리스트
    Node* head;
}ListType;

void init(ListType* plist) { //새로운 연결 리스트 초기화
    plist->head = NULL;
}

bool isEmpty(ListType* plist){ //리스트가 비었는지 알려주는 함수
    return (plist->head == NULL);
}

void insertLast(ListType* plist, element val) { //리스트의 마지막에 노드를 추가하는 함수
    Node* newNode = (Node*) malloc(sizeof(Node)); //새로운 노드 생성
    newNode->item = val; //새로운 노드에 값 넣기

    if(newNode == NULL){
        printf("memory allocation error\n");
        exit(1);
    }
    if(isEmpty(plist)) { //만약 리스트에 노드가 없으면
        plist->head = newNode; //새로운 노드가 헤드노드가 된다.
        newNode->rlink = newNode->llink = newNode; //양쪽 링크가 모두 자기자신을 가리킴.
    }
    else{
        newNode->llink = plist->head->llink; //원래의 마지막 노드를 새로운 노드가 가리킨다.
        newNode->rlink = plist->head; //새로운 노드가 헤드노드를 가리킨다.
        newNode->llink->rlink = newNode; //원래의 마지막 노드가 이제 헤드노드가 아닌 새로운 노드를 가리킨다.
        plist->head->llink = newNode; //헤드노드가 새로운 노드를 가리킨다.
    }
}

void printList(ListType* plist) { //순서대로 리스트 요소를 출력하는 함수
    Node* pnode = plist->head; //노드 포인터

    //pnode가 헤드노드부터 오른쪽으로 옮겨가면서 해당 노드의 item을 출력한다.
    for(pnode=plist->head; pnode->rlink!=plist->head; pnode = pnode->rlink) {
        printf("%2d <->", pnode->item);
    }
    //마지막에는 화살표를 출력하면 안되니까 따로.
    printf("%2d\n", pnode->item);
}

void printReverse(ListType* plist) {
    Node* pnode;

    //pnode가 마지막노드부터 옮겨가면서 해당 노드의 item을 출력한다.
    for(pnode=plist->head->llink; pnode!=plist->head; pnode = pnode->llink) {
        printf("%2d <->", pnode->item);
    }
    //마지막에는 화살표를 출력하면 안되니까 따로 출력.
    printf("%2d\n", pnode->item);
}
int main(void) {
    myInfo();

    //리스트 구조체 선언
    ListType list;
    //리스트 초기화
    init(&list);

    printf("Input data in dual linkedlist (0 to quit)\n");
    int inputVal;
    while(1){
        scanf("%d", &inputVal);
        if(inputVal == 0) break;
        insertLast(&list, inputVal);
    }
    printList(&list);
    printf("Print the list in reverse order\n");
    printReverse(&list);
    return 0;
}

void myInfo(void){
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}
