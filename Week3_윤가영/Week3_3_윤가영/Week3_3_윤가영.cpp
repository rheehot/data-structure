#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

void elementGeneration(int arrPtr[], int arrSize) //����ڰ� ���ϴ� ũ���� �迭�� �Է¹޽��ϴ�.
{
    for(int i = 0; i < arrSize; i++) scanf("%d", arrPtr+i);
    elementPrint(arrPtr, arrSize); //�Է¹��� �迭�� ����մϴ�.
}

void elementInsertion(int arrPtr[], int* arrSize) //�迭�� ���Ҹ� �����մϴ�.
{
    int insLoc, insValue; //insLoc: ���� ��ġ, insValue: ������ ��
    printf("Input location and value to insert\n");
    scanf("%d%d", &insLoc, &insValue);
    if(insLoc < 1 || insLoc > *arrSize){ //����ڰ� �Է��� ���� ��ġ ���� ������ ��� ��� �Լ��� �����մϴ�.
        printf("Choose between 1 and %d\n\n", *arrSize);
        return;
    }
    int insIdx = insLoc - 1; //����ڰ� �Է��� ��ġ�� �迭 �ε��� ������ 1 �� �����ϱ��..
    for(int i = *arrSize - 1; i >= insIdx; i--) arrPtr[i+1] = arrPtr[i]; //��ĭ�� �ڷ� ���� �������ݴϴ�.
    arrPtr[insIdx] = insValue; //���� for������ ������ġ+1 ��° ���ұ��� ���� �ٲ��־����Ƿ�, ���������� ������ġ�� ����� �Է°��� �����մϴ�.
    *arrSize = *arrSize + 1; //�迭�� (�������� ��) ���̰� 1�� �� �þ���Ƿ� 1 ���������ݴϴ�.
    elementPrint(arrPtr, *arrSize);
}

void elementDeletion(int arrPtr[], int* arrSize) //�迭�� ���Ҹ� �����ϴ� �Լ��Դϴ�.
{
    int delLoc; //������ ������ ��ġ(����� �Է�)�� ������ ����
    printf("Input location to delete\n");
    scanf("%d", &delLoc);

    if(delLoc < 1 || delLoc > *arrSize){ //������ ��� ��� �Լ��� �����մϴ�.
        printf("No element in location %d\n\n", delLoc);
        return;
    }
    int delIdx = delLoc - 1; //�ε��� = �Է°� - 1
    for(int i = delIdx; i < *arrSize; i++) arrPtr[i] = arrPtr[i+1]; //���ҵ��� ��ĭ�� ������ ����ݴϴ�.
    arrPtr[*arrSize] = 0; //����������, ���� ������ �ε����� ���� 0���� �����ݴϴ�.

    *arrSize = *arrSize - 1; //�迭�� ����� �ٿ��ݴϴ�.
    elementPrint(arrPtr, *arrSize); //����� ����մϴ�.
}

void elementPrint(int arrPtr[], int arrSize)
{
    printf("Array:");
    for(int i = 0; i < arrSize; i++) printf("%3d", arrPtr[i]); //���Ҹ� ����մϴ�.
    printf("\n\n");
}

int main(void) {
    myInfo();

    int numCount, i, v;
    int arr[MAX_SIZE];

    printf("How many numbers? ");
    scanf("%d", &numCount);
    printf("Input %d numbers\n", numCount);

    elementGeneration(&arr, numCount);

    while(1) //�ݺ���
    {
        printf("Choose operation:\n1. insertion 2. deletion 3.output 0:program end\n");

        scanf("%d", &v);
        switch(v) {
            case 0: exit(0); break; //���α׷� ����
            case 1:
                elementInsertion(arr, &numCount); //���� ����
                break;
            case 2:
                elementDeletion(arr, &numCount); //���� ����
                break;
            case 3:
                elementPrint(arr, numCount); //�迭 ���
                break;
            default: break;
        }
    }
}
