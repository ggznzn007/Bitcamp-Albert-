
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/*	����~ ������~ ��~~~
	
*/
int main(void) {
	int n[10] = { 0 };
	int (*p)[10] = &n;// 2���迭
	printf("n : %d \n", n);
	// �ּҿ� �ִ� ���� ũ��
	printf("n : %d \n", sizeof(*n) );

	// �迭�� �ּ� : &�迭��
	printf("n : %d \n", &n);
	// �ּҿ� �ִ� ���� ũ��
	printf("n : %d \n", sizeof(*(&n)));

	int* p1;
	p1 = n;	// n == &n[0];
	int (*p2)[10] = &n;// �迭 ������


	return 0;
}

int main_01(void) {
	char ch = 'A';
	printf("size : %d \n", sizeof(ch));
	printf("address : %d \n", &(ch));// ������ �ּ�
	printf("size : %d \n", sizeof(&ch));// �ּ��� ũ��

	char* p;
	printf("size : %d \n", sizeof(p));
	printf("address : %d \n", &(p));// ������ �ּ�
	printf("size : %d \n", sizeof(&p));// �ּ��� ũ��

	p = &ch;	// ch ������ �ּҸ� �����Ѵ�...
	printf("%d \n", p);	// �ּ�
	printf("%d \n", *p);	// �̸� ch �� ��
	*p = 'B';
	printf("%c \n", ch);	// �̸� ch �� ��

	p = 'C';


	return 0;
}

/*
int main_01(void) {
	// ������ ������ ���� : �ڷ��� * ������;
	//	������ ������ ����� �ּҿ� � ���� �ֳ�

	char ch;	// ���� 1�� �����ϴ� ����
	char* p1;	// char ������ ����Ű�� ������ ����
		// char ���� ���� ���� �ٷ� �� �ִ�.... ( �迭 ó�� )
	char** p2;
		// char ������ ����Ű�� �����ͺ����� ����Ű�� �����ͺ���
		//	���� ���ϸ� ���

	char* ap1[3];// �����ͺ������� ��ҷ��ϴ� 1�� �迭
	char	(*ap2)[3];// �迭�� ����Ű�� �迭 �����ͺ���
	char* (*ap3)[3];// �迭�� ����Ű�� �迭 �����ͺ���

	char (*fp)(void);	// �Լ��� ����Ű�� �Լ� �����ͺ���
	char (*evt[5])(void);	// �Լ� ������ �迭

	return 0;
}
*/






