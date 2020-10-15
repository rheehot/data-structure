#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueNode { //queue node ����
    element data;
    struct QueueNode* link;
}QueueNode;

typedef struct {
    QueueNode* front, * rear; //front, rear ���
}LinkedQueueType;

void error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(LinkedQueueType* q) { //ť �ʱ�ȭ �Լ�
    q->front = NULL;
    q->rear = NULL;
}

bool is_full(LinkedQueueType* q) { //��� �� �Լ��� �ʿ� �����ϴ�.
    return 0;
}

bool is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

void enqueue(LinkedQueueType* q, element item) { //enqueue �Լ�
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode)); //���ο� ��� temp ����
    temp->data = item;
    temp->link = NULL;
    if(is_empty(q)) {
        q->front = q->rear = temp; //ť�� ����־��ٸ� front�� rear�� ��� temp�� ����Ű�� ��
    }
    else {
        q->rear->link = temp; //���� rear��尡 temp�� ����Ű�� ��
        q->rear = temp; //rear �� ���ο� ��带 ����Ű�� ��
    }
}

element dequeue(LinkedQueueType* q) { //dequeue �Լ�
    if (is_empty(q)) { //ť�� ����ִٸ� ����
        error("queue is empty");
        return -1;
    }
    element data; //��ȯ�� ������ ��.
    QueueNode* temp = q->front; //front�� �����ؾ��ϹǷ� temp�� front��带 ����Ű�� �Ѵ�.
    data = temp->data; //�����ʹ� temp�� ����Ű�� ����� ������.(������ ���)
    q->front = q->front->link; //���� front�� ���� ù���� ��尡 ����Ű�� ��尡 ��.
    if (q->front == NULL) q->rear = NULL; //��尡 �ϳ��ۿ� �����ٸ� front�� NULL�� ���̰� �׷� rear�� �ٲ��ش�.
    free(temp); //free(����ù��°���)
    return data;
}
element peek_rear(LinkedQueueType* q) { //rear ���� ��ȯ�ϴ� �Լ�
    return q->rear->data;
}

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

int main(void) {
    myInfo();

    int n; //����� �Է� ���� ����

    printf("Input a fibonacci location: ");
    scanf("%d", &n);

    LinkedQueueType q;
    init_queue(&q);
    enqueue(&q, 0); //f0 = 0
    enqueue(&q, 1); //f1 = 1

    int front, rear; //ť���� deque/peek�� ���� ������ ����

    for(int i = 0; i < n; i++) { //f0���� f_n-1���� ���
        rear = peek_rear(&q); //��ġ�� �ٲ�� ���� rear���� ������
        front = dequeue(&q); //������ front data�� deque ��Ų��.
        enqueue(&q, front+rear); //�ΰ��� ���ؼ� ť�� ���� �ִ´�.
        printf("%5d", front); //front ���
    }
    printf("%5d\n", q.front->data); //rear�� �ִ� ��尡 front�� �Ǿ����Ƿ� ���������� front�� data�� ����Ѵ�.
    return 0;
}
