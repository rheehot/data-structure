#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    ListNode* link;
}ListNode;

void print_list(ListNode* head) { //연결리스트 출력함수입니다.
    ListNode* p = NULL;
    for(p = head; p != NULL; p = p->link) //반복문을 사용하여 data들을 출력합니다.
        printf("%d ", p->data);
    putchar('\n'); //마지막 원소 뒤에 엔터 출력
}



ListNode* insert_last(ListNode* head, element val) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 p 생성

    p->data = val; //p의 데이터는 val
    p->link = NULL; //p는 마지막 노드가 되어야하므로 p의 링크는 NULL이다.

    if(head == NULL){ //만약 리스트가 비어있다면 p는 첫번째 노드로 들어갑니다.
        head = p; //따라서 head는 p를 가리키게 됩니다.
        return head;
    }

    ListNode* temp = head; //헤드 포인터를 temp에 저장한다.
    while(temp->link != NULL) temp = temp->link; //temp가 원래의 마지막 노드를 가리키게 한다.
    temp->link = p; //원래의 마지막 노드의 링크가 이제 p를 가리킨다.
    return head; //헤드를 반환한다.
}

element max_element(ListNode* head) { //가장 큰 값을 구하는 함수입니다.
    ListNode* p = head;
    int max = p->data; //첫번째 원소로 max값을 초기화합니다.
    for(p = head->link; p != NULL; p = p->link){
        if(p->data > max) max = p->data;
    }
    return max;
}

element min_element(ListNode* head) { //가장 작은 값을 구하는 함수입니다.
    ListNode* p = head;
    int min = p->data; //첫번째 원소로 min값을 초기화 합니다.
    for(p = head->link; p != NULL; p = p->link){
        if(p->data < min) min = p->data;
    }
    return min;
}

void freeNodes(ListNode* head) { //연결리스트의 메모리를 해제하는 함수입니다.
    ListNode* p = NULL;
    while(head != NULL) { //헤드포인트가 다음 노드를 가리키도록 계속 옮기면서 반복, 마지막엔 헤드가 NULL입니다.
        p = head;
        head = head->link;
        free(p);
    }
}

int main(void) {
    int n;
    ListNode* head = NULL; //연결리스트의 첫번째 노드를 가리킬 head 포인터입니다.
    while(1){
        printf("Input an integer to add <0 to quit>: ");
        scanf("%d", &n);
        if(n == 0) break; //사용자가 0을 입력하면 반복문을 탈출합니다.
        head = insert_last(head, n); //사용자가 입력한 수를 연결리스트에 삽입합니다.
    }

    printf("\n<List>\n");
    print_list(head); //리스트를 출력합니다.
    printf("Max: %d Min: %d\n", max_element(head), min_element(head));

    freeNodes(head); //연결리스트에 쓰인 메모리를 해제합니다.

    return 0;
}
