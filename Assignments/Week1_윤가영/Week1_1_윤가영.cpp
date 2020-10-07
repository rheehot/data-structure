#include <stdio.h>

int main(void){
    printf("====================\n");
    printf("학과: 사이버보안전공\n");
    printf("학번: 1971079\n");
    printf("성명: 윤가영\n");
    printf("====================\n");

    int a = 1;
    while(1) {
        printf("Input an integer\n");
        scanf("%d", &a);
        if(a<=0) break;
        int sum = 0;
        for(int i = 1; i < a+1; i++) { //1부터 a까지 
            if(i%2!=0 && i%5!=0) sum += i; //홀수 이면서 5의배수가 아니면 sum에 더한다
        }
        printf("Sum of odd numbers which is not the multiples of 5 between 1 and 10 is %d\n", sum);
    }
    printf("program finished\n");
    return 0;
}
