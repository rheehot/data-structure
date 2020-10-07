#include <stdio.h>
#define ROWS 4
#define COLS 3

void myInfo(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");
}

void matrixInput(int M[][COLS]) //행렬 입력 함수입니다. 매개변수는 배열 포인터입니다.
{
    for(int i = 0; i < ROWS; i++){ //각 행마다 반복
        for(int j = 0; j < COLS; j++) scanf("%d", &M[i][j]); //열마다 반복해서 입력받습니다.
        getchar();
    }
}

void matrixPrint(int M[][COLS])
{
    for(int i = 0; i < ROWS; i++){ //각 행마다 반복
        for(int j = 0; j < COLS; j++) printf("%3d", M[i][j]); //각 열마다 반복해서 입력 받습니다.
        putchar('\n');
    }
}

void matrixAdd(int M[][COLS], int N[][COLS], int P[][COLS])
{
    for(int i =0; i < ROWS; i++){ //각 행바다 반복
        for(int j = 0; j < COLS; j++) P[i][j] = M[i][j] + N[i][j]; //각 열마다 반복해서 계산, 대입합니다.
    }
}

int main(void)
{
    myInfo();

    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
    printf("Input values for %dX%d matrix A\n", ROWS, COLS); //행렬 A 입력받기
    matrixInput(A);
    printf("Input values for %dX%d matrix B\n", ROWS, COLS); //행렬 B 입력받기
    matrixInput(B);
    puts("<A>");
    matrixPrint(A); //A 출력
    puts("<B>");
    matrixPrint(B); //B 출력
    puts("<A+B>");
    matrixAdd(A, B, C); // C=A+B
    matrixPrint(C); //C 출력

    return 0;
}
