#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = -1;
}

bool is_full(QueueType* q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

bool is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void enqueue(QueueType* q, element item) {
    if(is_full(q)) {
        error("queue is full");
        return;
    }
    else q->data[++q->rear] = item; //rear를 증가시키고 값 대입
}

element dequeue(QueueType* q) {
    if(is_empty(q)){
        error("queue is empty");
        return -1;
    }
    else return q->data[++(q->front)];
}

void print_queue(QueueType* q) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (i <= q->front || i > q->rear) printf("    |");
        else printf("%3d |", q->data[i]);
    }
    printf("\n\n");
}

int main(void)
{
    int item = 0;
    QueueType q;
    init_queue(&q);
    enqueue(&q, 10); print_queue(&q);
    enqueue(&q, 20); print_queue(&q);
    enqueue(&q, 30); print_queue(&q);

    item = dequeue(&q); print_queue(&q);
    item = dequeue(&q); print_queue(&q);
    item = dequeue(&q); print_queue(&q);
    item = dequeue(&q); print_queue(&q);
    return 0;
}
