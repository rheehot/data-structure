#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode{ //구조체 정의 입니다. 링크가 양방향으로 모두 있습니다.
    element data;
    ListNode* llink;
    ListNode* rlink;
}ListNode;

void init(ListNode* phead) { //리스트를 초기화하는 함수입니다.
    phead->llink = phead; //오른쪽 왼쪽 링크가 모두 자기 자신을 가리킵니다.
    phead->rlink = phead;
}

void print_list(ListNode* head){ //노드리스트의 원소를 출력하는 함수입니다. 매개변수는 비어있는 헤드 '노드'입니다.
    ListNode* p = NULL;
    printf("<LIST>\n");
    for(p = head->rlink; p->rlink != head; p = p->rlink) //첫번째 노드부터 data를 출력합니다. 마지막 노드는 헤드를 가리키므로 출력하지 못해요.
        printf("%3d", p->data);
    printf("%3d\n", p->data); //그래서 마지막에 한번 더 출력해줍니다.
}

ListNode* insert_first(ListNode* head, element val) { //첫번째 노드에 삽입해주는 함수입니다. 반환값은 head 노드입니다.
    ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 생성
    node->data = val; //노드에 원하는 값 집어넣기
    if(head == head->rlink){ //만약 리스트에 헤드노드만 존재하고 있을 경우
        head->rlink = head->llink = node; //헤드의 양방향이 모두 새로 생긴 노드를 가리킵니다.
        node->llink = node->rlink = head; //마찬가지로 새로 생긴 노드도 양방향 모두 헤드를 가리킵니다.
    }
    else {
        node->rlink = head->rlink; //새로운 노드의 오른쪽 링크가 원래 첫번재에 있던 노드를 가리킵니다.
        node->llink = head; //새로운 노드의 왼쪽 링크가 헤드 노드를 가리키게합니다.

        node->rlink->llink = node; //원래 첫번째였던 노드의 왼쪽 링크가 새로운 노드를 가리키게 합니다.
        head->rlink = node; //헤드의 오른쪽 링크가 새로운 노드를 가리키게 합니다.
    }
    return head;
}

ListNode* search_delete(ListNode* head, element val) { //헤드노드에는 값이 없다!
    ListNode* p = NULL;
    bool found = false;
    p = head->rlink; //첫번째 노드는 헤드노드 다음 노드이므로 rlink가 가리키는 노드입니다.
    do { //검색 시작
        if(p->data == val) { //data가 일치하는 노드 p가 존재할 때
            found = true;
            //양 옆의 노드들과 p의 연결을 끊고 옆에 있던 노드들 끼리 이어줍니다.
            p->rlink->llink = p->llink;
            p->llink->rlink = p->rlink;
            free(p); //p 제거
            break;
        }
        p = p->rlink;
    }while(p->rlink != head);

    if(found){
        printf("%d is found and deleted\n", val);
    }
    else{
        printf("%d is not in the list\n", val);
    }
    return head;
}

int main(void) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //head 노드 생성
    init(head); // 리스트 초기화!
    int n; //사용자의 입력을 저장할 변수
    while(1) {
        printf("Input an integer to add<0 to quit>: ");
        scanf("%d", &n);
        if(n == 0) break;
        head = insert_first(head, n);
    }
    print_list(head); //사용자에게 입력받은 리스트 출력
    printf("Input the number to search and delete: ");
    scanf("%d", &n);
    head = search_delete(head, n); //원소를 삭제한 뒤 결과 출력, 리스트 반환
    print_list(head); //출력
    free(head);
}
