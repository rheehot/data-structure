#include <stdio.h>

int main(void){
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");

    int a = 1;
    while(1) {
        printf("Input an integer\n");
        scanf("%d", &a);
        if(a<=0) break;
        int sum = 0;
        for(int i = 1; i < a+1; i++) { //1���� a���� 
            if(i%2!=0 && i%5!=0) sum += i; //Ȧ�� �̸鼭 5�ǹ���� �ƴϸ� sum�� ���Ѵ�
        }
        printf("Sum of odd numbers which is not the multiples of 5 between 1 and 10 is %d\n", sum);
    }
    printf("program finished\n");
    return 0;
}
