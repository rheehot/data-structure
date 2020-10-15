#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
    int size; //���� ������ ����� �߰��߽��ϴ�. �������� ����ؾ��ؼ���..
}QueueType;

void init_queue(QueueType* q) {
    q->front = q->rear = q->size = 0;
}

bool is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // 5 % 5 == 0 (front)
}

bool is_empty(QueueType* q) {
    return (q->front == q->rear); //front �� rear�� ������ empty
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) { //ť�� �� á�� ���� �׳� �Լ��� �����մϴ�.
        printf("queue is full\n");
        return;
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE; //rear�� �ε����� +1 ���ݴϴ�. (�����̹Ƿ� ������ ����)
    q->data[q->rear] = item; //ť�� �����͸� �߰�
    q->size++; //ť�� ����� 1����
}

element dequeue(QueueType* q) {
    if (is_empty(q)) { //ť�� ����� �� deque�� �õ� �ϸ�
        printf("queue is empty\n");
        return 0; //0�� ��ȯ�ϰ� �߾��. (�Է����� 0�� ������ �����ϱ�)
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; //deque �� front�� �ε����� +1 ���ݴϴ�. (�����̹Ƿ� ������ ����)
    q->size--; //ť�� ����� 1 ����
    return q->data[q->front]; //������ front ��ġ�� �ִ� �� ��ȯ
}

void print_queue(QueueType* q) {
    printf("Queue(front: %d, rear: %d) = ", q->front, q->rear); //���� front�� rear �ε��� ���

    if (!is_empty(q)) { //ť�� ������� ������ ť�� �����͸� ������� ����մϴ�.
        int i = q->front; //front���� ����
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%3d |", q->data[i]);
            if (i == q->rear) break; //rear�� ����ߴٸ� �ݺ��� ����
        } while(i != q->front); //front�� ���ƿ��� �ݺ��� ����
    }
    printf("\n");
}

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

int main(void)
{
    myInfo();

    char in; //����ڰ� ���ϴ� �۾��� �Է¹��� char ����
    int n; //����ڰ� enqueue�� ���� �� ť�� ���� ���� ���ڸ� �Է¹��� ����
    QueueType q;
    init_queue(&q);

    while(1){
        printf("���ϴ��۾�(E/e:enqueue, D/d:dequeue, P/p:output, 0:quit): ");
        scanf("%c", &in);
        switch(in){

            case 'E': case 'e': //enqueue
                printf("���� �Է�: ");
                scanf("%d", &n);
                enqueue(&q, n);
                break;

            case 'D': case 'd': //dequeue
                n = dequeue(&q);
                if(n == 0) break;
                else printf("%3d\n", n);
                break;

            case 'P': case 'p': //print queue
                print_queue(&q);
                break;
            case '0': //end program
                printf("���� ���� ������: %d\n", q.size);
                print_queue(&q);
                exit(0); break;
            default:
                printf("Wrong input\n");

        }
        getchar(); //����?�� ���� ���� �Է¹ޱ�
        printf("\n");
    }
    return 0;
}
