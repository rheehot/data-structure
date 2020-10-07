#include <stdio.h>
#define ROWS 4
#define COLS 3

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

void matrixInput(int M[][COLS]) //��� �Է� �Լ��Դϴ�. �Ű������� �迭 �������Դϴ�.
{
    for(int i = 0; i < ROWS; i++){ //�� �ึ�� �ݺ�
        for(int j = 0; j < COLS; j++) scanf("%d", &M[i][j]); //������ �ݺ��ؼ� �Է¹޽��ϴ�.
        getchar();
    }
}

void matrixPrint(int M[][COLS])
{
    for(int i = 0; i < ROWS; i++){ //�� �ึ�� �ݺ�
        for(int j = 0; j < COLS; j++) printf("%3d", M[i][j]); //�� ������ �ݺ��ؼ� �Է� �޽��ϴ�.
        putchar('\n');
    }
}

void matrixAdd(int M[][COLS], int N[][COLS], int P[][COLS])
{
    for(int i =0; i < ROWS; i++){ //�� ��ٴ� �ݺ�
        for(int j = 0; j < COLS; j++) P[i][j] = M[i][j] + N[i][j]; //�� ������ �ݺ��ؼ� ���, �����մϴ�.
    }
}

int main(void)
{
    myInfo();

    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
    printf("Input values for %dX%d matrix A\n", ROWS, COLS); //��� A �Է¹ޱ�
    matrixInput(A);
    printf("Input values for %dX%d matrix B\n", ROWS, COLS); //��� B �Է¹ޱ�
    matrixInput(B);
    puts("<A>");
    matrixPrint(A); //A ���
    puts("<B>");
    matrixPrint(B); //B ���
    puts("<A+B>");
    matrixAdd(A, B, C); // C=A+B
    matrixPrint(C); //C ���

    return 0;
}
