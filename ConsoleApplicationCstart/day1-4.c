
#include <stdio.h>

/*
	�ڷ���, ���� ���
	������
	- ���������
	- ���迬����(�񱳿�����)
	- ��������
	- ��Ʈ����(2������)
*/
int main(void) {
	//�� ������ : ���ǽ� ���� �� ����
	// ���ǽĵ��� ����, ���踦 �ľ�
	printf("%d \n", (1 < 0) && ('a' == 97));
	printf("%d \n", (1 < 0) || ('a' == 97));
	printf("%d \n", !1);// �� ���� not
	printf("%d \n", NULL);
	Printf("%d \n", EOF);
	return 0;
}
int main_02(void) {
	// 0�� ����, 0�� �ƴϸ� ��
	printf("%d \n", 10 < 2);
	printf("%d \n", 10 > 2);
	// ���� 0 �Ǵ� 1�̴� -> �������� ���Ѵ�..
	printf("%d \n", 10 <= 2);
	printf("%d \n", 10 >= 2);
	printf("%d \n", 10 == 2);
	printf("%d \n", 10 != 2);

	// ������� : ��(����, �Ǽ�)
	int n = 10;
	double lf = 12.34;
	char ch = 'a'; // 97
	printf("%d \n", n * 20);
	printf("%lf \n", lf * 20);
	printf("%d \n", ch * 20);
	printf("%c \n", 97 * 20);
	// char �� �����δ� �����̴�...
	//printf("%d \n", 97 / 0);
	printf("%lf \n", (double)97 / 20);
	printf("%lf \n", (double)(97 / 20));
	// ���� �Ǽ��� ��ȯ �Ŀ� ������ �� ��...
	printf("%d \n", n % 5);
	//����ȯ �� ����
	int a = 256;
	double b = a;// ���� -> �Ǽ�
	int c = b;
	printf("%d %lf %d \n", a, b, c);
	return 0;
}


