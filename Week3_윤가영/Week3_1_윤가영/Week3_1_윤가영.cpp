#include <stdio.h>
#include <string.h>

void myInfo(void) {
    printf("====================\n");
    printf("�а�: ���̹���������\n");
    printf("�й�: 1971079\n");
    printf("����: ������\n");
    printf("====================\n");
}

void func_recursive(char* s) //����Լ�: �Ű����� s�� char ������ �Դϴ�.
{
   if(*s == '\0') return; //���������� �ι����Դϴ�.
   func_recursive(s+1); //����Լ��� ȣ���մϴ�. (s+1: ���� ������ �ּҰ�)
   printf("%c", *s); //s�� ����Ű�� char�� ����մϴ�.
}

int main(void)
{
    myInfo();

    char X[100];

    printf("Input string\n");
    gets(X);
    puts("������:");
    puts(X);
    puts("������:");
    func_recursive(X); //�Ű�����: ���ڿ� X�� ù��° ������ �ּҰ�
    return 0;
}



