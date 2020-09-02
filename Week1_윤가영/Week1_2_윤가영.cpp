#include <stdio.h>
#include <time.h>
#include <math.h>

bool isPrime(int);

int main(void) {
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
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
    for(int i = 2; i < sqrt(n)+1; i++){ //약수를 가지는 숫자들은 루트2한 값을 기준으로 양옆으로 가지기 때문에 (제곱수일 경우 가운데도 약수) 가운데까지만 판별
        if(n%i == 0) return false;
    }
    return true;
}
