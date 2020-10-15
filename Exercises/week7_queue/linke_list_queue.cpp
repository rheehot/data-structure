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

void init_queue(LinkedQueueType* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool is_full(LinkedQueueType* q) { //사실 이 함수는 필요 없습니다.
    return 0;
}

bool is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

void enqueue(LinkedQueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = item;
    temp->link = NULL;
    if(is_empty(q)) {
        q->front = q->rear = temp;
    }
    else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueueType* q) {
    if (is_empty(q)) {
        error("queue is empty");
        return -1;
    }
    element data;
    QueueNode* temp = q->front;
    data = temp->data;
    q->front = q->front->link;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

void print_queue(LinkedQueueType* q) {
    for(QueueNode* p = q->front; p != NULL; p = p ->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main(void)
{
    int item = 0;
    LinkedQueueType q;
    init_queue(&q);

    printf("<데이터 추가>\n");
    enqueue(&q, 1); print_queue(&q);
    enqueue(&q, 2); print_queue(&q);
    enqueue(&q, 3); print_queue(&q);

    printf("<데이터 가져오기>\n");
    dequeue(&q); print_queue(&q);
    dequeue(&q); print_queue(&q);
    dequeue(&q); print_queue(&q);
    dequeue(&q); print_queue(&q); //error
    return 0;
}
