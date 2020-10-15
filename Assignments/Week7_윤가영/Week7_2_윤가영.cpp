#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
    int size; //저는 사이즈 멤버를 추가했습니다. 마지막에 출력해야해서요..
}QueueType;

void init_queue(QueueType* q) {
    q->front = q->rear = q->size = 0;
}

bool is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // 5 % 5 == 0 (front)
}

bool is_empty(QueueType* q) {
    return (q->front == q->rear); //front 와 rear가 같으면 empty
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) { //큐가 꽉 찼을 때는 그냥 함수를 종료합니다.
        printf("queue is full\n");
        return;
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE; //rear의 인덱스를 +1 해줍니다. (원형이므로 나머지 연산)
    q->data[q->rear] = item; //큐의 데이터를 추가
    q->size++; //큐의 사이즈를 1증가
}

element dequeue(QueueType* q) {
    if (is_empty(q)) { //큐가 비었을 때 deque를 시도 하면
        printf("queue is empty\n");
        return 0; //0을 반환하게 했어요. (입력으로 0이 들어오지 않으니까)
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; //deque 후 front의 인덱스를 +1 해줍니다. (원형이므로 나머지 연산)
    q->size--; //큐의 사이즈를 1 감소
    return q->data[q->front]; //증가된 front 위치에 있는 값 반환
}

void print_queue(QueueType* q) {
    printf("Queue(front: %d, rear: %d) = ", q->front, q->rear); //현재 front와 rear 인덱스 출력

    if (!is_empty(q)) { //큐가 비어있지 않으면 큐의 데이터를 순서대로 출력합니다.
        int i = q->front; //front부터 시작
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%3d |", q->data[i]);
            if (i == q->rear) break; //rear를 출력했다면 반복문 종료
        } while(i != q->front); //front로 돌아오면 반복문 종료
    }
    printf("\n");
}

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

int main(void)
{
    myInfo();

    char in; //사용자가 원하는 작업을 입력받을 char 변수
    int n; //사용자가 enqueue를 원할 때 큐에 집어 넣을 숫자를 입력받을 변수
    QueueType q;
    init_queue(&q);

    while(1){
        printf("원하는작업(E/e:enqueue, D/d:dequeue, P/p:output, 0:quit): ");
        scanf("%c", &in);
        switch(in){

            case 'E': case 'e': //enqueue
                printf("정수 입력: ");
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
                printf("현재 원소 갯수는: %d\n", q.size);
                print_queue(&q);
                exit(0); break;
            default:
                printf("Wrong input\n");

        }
        getchar(); //버퍼?에 남은 엔터 입력받기
        printf("\n");
    }
    return 0;
}
