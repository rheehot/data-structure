#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void error(const char* m) {
    fprintf(stderr, "%s\n", m);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

bool is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // 5 % 5 == 0 (front)
}

bool is_empty(QueueType* q) {
    return (q->front == q->rear); //front 와 rear가 같으면 empty
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("queue is full");
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE; //왜 이렇게 해야하는거지..?
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) error("queue is empty");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void print_queue(QueueType* q) {
    printf("Queue(front: %d, rear: %d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%3d |", q->data[i]);
            if (i == q->rear) break;
        } while(i != q->front);
    }
    printf("\n");
}

int main(void)
{
    QueueType q;
    init_queue(&q);
    int element;

    printf("<데이터 추가>\n");
    while (!is_full(&q)) {
        printf("정수입력: ");
        scanf("%d", &element);
        enqueue(&q, element);
        print_queue(&q);
    }
    printf("Queue is full\n");

    printf("\n선입선출~.~\n\n");
    printf("<데이터 가져오기>\n");
    while (!is_empty(&q)) {
        printf("%3d\n", dequeue(&q));
        print_queue(&q);
    }
    printf("Queue is empty.\n");
    return 0;
}
