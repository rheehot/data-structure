#include <stdio.h>

void myInfo(void);
void rec(int);
void iter(int);
int main(void) {
    myInfo(); //�а��й����� ��� �Լ�

    int n; //����� �Է°� ���� ����
    printf("���� ���� �Է�:");
    scanf("%d", &n);

    printf("�ݺ��Լ�ȣ��:"); iter(n); //���� �Լ� �ȿ��� ����ϵ��� ������� ������ ���� ����ϱ� ���� ȣ�⸸ �߽��ϴ�.
    printf("\n");
    printf("����Լ�ȣ��:"); rec(n); //��͵� ���������Դϴ�.

    return 0;
}


void rec(int n) { //recursive ����� �̿��� �Լ��Դϴ�. �Ķ���ʹ� ������ ���� ������ �ֽ��ϴ�.
    printf("%d ", n);
    if(n>0) rec(n-1); //n�� ����̸� ��� ȣ���� �մϴ�. �׷��� 0�� �Ǹ� �Լ��� ����˴ϴ�.
}

void iter(int n) { //iterative�� �̿��� �Լ��Դϴ�.
    for (int i = n; i >= 0; i--) printf("%d ", i); //�������� �Ķ���� �ڱ��ڽ��� ����մϴ�.
}
void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}
