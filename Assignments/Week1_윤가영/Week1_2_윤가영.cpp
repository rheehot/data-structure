#include <stdio.h>
#include <time.h>
#include <math.h>

bool isPrime(int);

int main(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");

    int start, stop, n;
    printf("Input n: ");
    scanf("%d", &n);

    start = clock();
    for(int i = 2; i <= n; i++) {
        if (isPrime(i)) printf("%5d", i);
    }
    putchar('\n');
    stop = clock();
    printf("start: %d\n", start);
    printf("stop: %d\n", stop);
    printf("time1: %.2f sec\n\n", (double)(stop-start)/CLOCKS_PER_SEC);
    return 0;
}

bool isPrime(int n) {
    if(n==2) return true;
    for(int i = 2; i < sqrt(n)+1; i++){ //����� ������ ���ڵ��� ��Ʈ2�� ���� �������� �翷���� ������ ������ (�������� ��� ����� ���) ��������� �Ǻ�
        if(n%i == 0) return false;
    }
    return true;
}
