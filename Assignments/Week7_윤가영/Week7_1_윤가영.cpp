#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueNode { //queue node 정의
    element data;
    struct QueueNode* link;
}QueueNode;

typedef struct {
    QueueNode* front, * rear; //front, rear 멤버
}LinkedQueueType;

void error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(LinkedQueueType* q) { //큐 초기화 함수
    q->front = NULL;
    q->rear = NULL;
}

bool is_full(LinkedQueueType* q) { //사실 이 함수는 필요 없습니다.
    return 0;
}

bool is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

void enqueue(LinkedQueueType* q, element item) { //enqueue 함수
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode)); //새로운 노드 temp 생성
    temp->data = item;
    temp->link = NULL;
    if(is_empty(q)) {
        q->front = q->rear = temp; //큐가 비어있었다면 front와 rear가 모두 temp를 가리키게 함
    }
    else {
        q->rear->link = temp; //원래 rear노드가 temp를 가리키게 함
        q->rear = temp; //rear 가 새로운 노드를 가리키게 함
    }
}

element dequeue(LinkedQueueType* q) { //dequeue 함수
    if (is_empty(q)) { //큐가 비어있다면 에러
        error("queue is empty");
        return -1;
    }
    element data; //반환할 데이터 값.
    QueueNode* temp = q->front; //front를 삭제해야하므로 temp가 front노드를 가리키게 한다.
    data = temp->data; //데이터는 temp가 가리키는 노드의 데이터.(삭제할 노드)
    q->front = q->front->link; //이제 front는 원래 첫번재 노드가 가리키던 노드가 됨.
    if (q->front == NULL) q->rear = NULL; //노드가 하나밖에 없었다면 front가 NULL일 것이고 그럼 rear도 바꿔준다.
    free(temp); //free(원래첫번째노드)
    return data;
}
element peek_rear(LinkedQueueType* q) { //rear 값을 반환하는 함수
    return q->rear->data;
}

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

int main(void) {
    myInfo();

    int n; //사용자 입력 저장 변수

    printf("Input a fibonacci location: ");
    scanf("%d", &n);

    LinkedQueueType q;
    init_queue(&q);
    enqueue(&q, 0); //f0 = 0
    enqueue(&q, 1); //f1 = 1

    int front, rear; //큐에서 deque/peek할 값을 저장할 변수

    for(int i = 0; i < n; i++) { //f0부터 f_n-1까지 출력
        rear = peek_rear(&q); //위치가 바뀌기 전에 rear부터 보고나서
        front = dequeue(&q); //원래의 front data를 deque 시킨다.
        enqueue(&q, front+rear); //두개를 더해서 큐에 집어 넣는다.
        printf("%5d", front); //front 출력
    }
    printf("%5d\n", q.front->data); //rear에 있던 노드가 front가 되었으므로 마지막에는 front의 data를 출력한다.
    return 0;
}
