#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode { //ť�� ��� ����
    element data; //������ �ִ� ������
    QueueNode* link; //���� ��� ��ũ
} QueueNode;

typedef struct QueueType { //ť ����
    QueueNode* front, * rear; //front�� rear ��ũ
    int size; //ť�� ����� ����
} QueueType;

void initQueue(QueueType* q) { //ť �ʱ�ȭ �Լ�
    q->front = q->rear = NULL; //front�� rear �� null
    q->size = 0; //size�� 0
}

bool isEmpty(QueueType* q) {
    return (q->size == 0); //ť�� ����� 0�̸� �� ť
}

void enqueue(QueueType* q, element val) { //enqueue �Լ�
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)); //���ο� ť ��� ����
    newNode->data = val; //�� ����
    newNode->link = NULL; //��ũ�� ����

    if(isEmpty(q)) { //�� ť���ٸ�
        q->front = q->rear = newNode; //front�� rear�� ��� ���ο� ��带 ����Ų��
    }
    else { //�� ť�� �ƴ϶��
        q->rear->link = newNode; //���� rear��尡 ���ο� ��带 ����Ų��.
        q->rear = newNode; //rear�� ���� ���ο� ��带 ����Ŵ
    }
    q->size++; //������ ����
}

element dequeue(QueueType* q) { //dequeue
    if(isEmpty(q)){ //�� ť���
        printf("queue is empty\n");
        exit(1); //����
    }
    QueueNode* temp = q->front; //front ����� �ּҸ� �ӽ� ����

    q->front = q->front->link; //front�� ���� ��带 ����

    if(q->front == NULL) { //���� ��尡 �ϳ��ۿ� �����ٸ�
        q->rear = NULL; //rear�� NULL
    }
    q->size--; //������ ����

    int data = temp->data; //��ȯ�� �ӽ÷� �����ϴ� ���� data
    free(temp); //�޸� ��ȯ
    return data;
}

int sizeOfQueue(QueueType* q) { //ť�� ������
    return q->size;
}

void printQueue(QueueType* q) { //ť ����Լ�
    QueueNode* p = q->front; //front ��带 ����Ű�� p
    for(int i = 0; i < q->size-1; p=p->link, i++) //ť�� ������ -1 ��ŭ ���
        printf("%3d |", p->data);
    printf("%3d |\n", p->data); //���������� �ٹٲޱ��� ���
}

void myInfo(void){
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}


int main(void) {
    myInfo();

    int n;
    printf("Input number of cards: ");
    scanf("%d", &n);

    if(n == 0){ //����ڰ� 0�� �Է��ϸ�
        printf("queue empty\n");
        return 0; //main ����
    }

    QueueType q; //ť ����
    initQueue(&q); //ť �ʱ�ȭ

    for(int i = 1; i <= n; i++) {
        enqueue(&q, i); //����ڰ� �Է��� ����ŭ ī�� ����ֱ�
    }

    element card;

    while(sizeOfQueue(&q) != 1) {
        printQueue(&q);
        dequeue(&q); //������ ī�带 ������.
        printQueue(&q);
        card = dequeue(&q); //front�� ������
        enqueue(&q, card); //�ٽ� ����ִ´�.
    }
    printf("Final element is %d\n", dequeue(&q)); //ť�� ���� ������ ���� ���� ����ϱ�.

    return 0;
}
