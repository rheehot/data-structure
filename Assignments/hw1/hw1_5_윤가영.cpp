#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode { //큐의 노드 정의
    element data; //가지고 있는 데이터
    QueueNode* link; //다음 노드 링크
} QueueNode;

typedef struct QueueType { //큐 정의
    QueueNode* front, * rear; //front와 rear 링크
    int size; //큐의 사이즈를 저장
} QueueType;

void initQueue(QueueType* q) { //큐 초기화 함수
    q->front = q->rear = NULL; //front와 rear 는 null
    q->size = 0; //size는 0
}

bool isEmpty(QueueType* q) {
    return (q->size == 0); //큐의 사이즈가 0이면 빈 큐
}

void enqueue(QueueType* q, element val) { //enqueue 함수
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)); //새로운 큐 노드 생성
    newNode->data = val; //값 대입
    newNode->link = NULL; //링크는 없음

    if(isEmpty(q)) { //빈 큐였다면
        q->front = q->rear = newNode; //front와 rear가 모두 새로운 노드를 가리킨다
    }
    else { //빈 큐가 아니라면
        q->rear->link = newNode; //원래 rear노드가 새로운 노드를 가리킨다.
        q->rear = newNode; //rear는 이제 새로운 노드를 가리킴
    }
    q->size++; //사이즈 증가
}

element dequeue(QueueType* q) { //dequeue
    if(isEmpty(q)){ //빈 큐라면
        printf("queue is empty\n");
        exit(1); //종료
    }
    QueueNode* temp = q->front; //front 노드의 주소를 임시 저장

    q->front = q->front->link; //front에 다음 노드를 대입

    if(q->front == NULL) { //원래 노드가 하나밖에 없었다면
        q->rear = NULL; //rear도 NULL
    }
    q->size--; //사이즈 감소

    int data = temp->data; //반환값 임시로 저장하는 변수 data
    free(temp); //메모리 반환
    return data;
}

int sizeOfQueue(QueueType* q) { //큐의 사이즈
    return q->size;
}

void printQueue(QueueType* q) { //큐 출력함수
    QueueNode* p = q->front; //front 노드를 가리키는 p
    for(int i = 0; i < q->size-1; p=p->link, i++) //큐의 사이즈 -1 만큼 출력
        printf("%3d |", p->data);
    printf("%3d |\n", p->data); //마지막에는 줄바꿈까지 출력
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

    int n;
    printf("Input number of cards: ");
    scanf("%d", &n);

    if(n == 0){ //사용자가 0을 입력하면
        printf("queue empty\n");
        return 0; //main 종료
    }

    QueueType q; //큐 선언
    initQueue(&q); //큐 초기화

    for(int i = 1; i <= n; i++) {
        enqueue(&q, i); //사용자가 입력한 수만큼 카드 집어넣기
    }

    element card;

    while(sizeOfQueue(&q) != 1) {
        printQueue(&q);
        dequeue(&q); //맨위의 카드를 버린다.
        printQueue(&q);
        card = dequeue(&q); //front를 빼내서
        enqueue(&q, card); //다시 집어넣는다.
    }
    printf("Final element is %d\n", dequeue(&q)); //큐에 남은 마지막 원소 빼서 출력하기.

    return 0;
}
