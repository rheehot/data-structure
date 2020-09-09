#include <stdio.h>

void myInfo(void);
float rec(int);
float iter(int);

int main(void) {
    myInfo(); //�а��й����� ��� �Լ�

    int n; //����� �Է°� ���� ����
    while(1) { //�ݺ���
        printf("���� ���� �Է�: ");
        scanf("%d", &n);
        if(n <= 0) break; //�Է°��� 0 ������ ��� �ݺ����� �����մϴ�.
        printf("Result from iterative: %.2f\n", iter(n)); //�ݺ��Լ��� �̿��� ���� �����Դϴ�.
        printf("Result from recursive: %.2f\n", rec(n)); //����Լ��� �̿��� ���� �����Դϴ�.
    }

    return 0;
}

float rec(int n) { //������ ��ȯ�ϴ� ����Լ�
    if(n==1) return 1.0; //���������� n�� 1�� �� �Դϴ�. n�� 1�� ��� ���̻� ��� ȣ���� ���� �ʰ� ���� ��ȯ�մϴ�.
    return (float)1/n + rec(n-1); //else: 1���� 1/n-1���� ���� ���� ȣ���ϴ� rec(n-1)�� 1/n�� ���Ͽ� ��ȯ�մϴ�.
}

float iter(int n) { //������ ��ȯ�ϴ� �ݺ��Լ�
    float sol = 1.0; //�Լ��� ��ȯ�� ���� ������ ���� sol�Դϴ�.
    for(int i = 2; i <= n; i++) sol += (float)1/i; //�ι�°���� �����ݴϴ�. sol = sol + 1/2 + ... + 1/n
    return sol; //���� ��ȯ�մϴ�.
}

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}
