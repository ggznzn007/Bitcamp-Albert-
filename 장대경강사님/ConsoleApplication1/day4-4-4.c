#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �������� : �Լ� �ۿ��� ����� ����
//	- �� �ҽ� ���Ͽ� ���ǵ� ��� �Լ����� ��� ����
int gValue = 10; // �����ϴ� ����� �ʹ� ������� ~ �������
extern int ext_value;// �ٸ� �ҽ����Ͽ� ���ǵ� ���������� ���
// �� ���������� ������� ����
static int internal_value;// extern �Ұ�

int f2() {
	// ���������� static 
	static int static_value = 0;// �����ض�... ����������

	int v3 = 100;
	// �� �Լ��� ��� �ִ� ���ȿ��� ��� ����
	gValue = 100;

	return 0;
}

int f1() {
	f2();
	gValue = 10;
	return 0;
}

int static_fn() {
	static int cnt = 0;// �� ���� ���� ��� ����
	cnt++;
	return cnt;
}
// �����ͺ���- �ּҸ� �˸� ������ �����ϴ�....
int updateNumber(int* param) {// param = &cnt;
	int v = *param;// v = cnt
	*param = v * 10;
	return 0;
}
int main(int argc, char** argv) {
	// �Լ� ȣ��� Ƚ�� �˰� �ʹ�....
	int cnt = 2;
	// �ڽ��� ������ �ٸ� �Լ��� �����ϵ��� 
	updateNumber(&cnt);// �ּҸ� ����
	printf("%d \n", cnt);

	return 0;
}

int main_01(int argc, char** argv) {
	// ���� ��ġ�� ���� ������ ���� : ���� ������
	// �������� : �Լ� ������ ����� ���� : �� �Լ��� ����� �� �ִ�.
	// { } �� �������� ������...
	int v1 = 10;
	int* p;
	{
		int v2 = 1000;
		v1 = 20;
		v2 = 2000;
		p = &v2;
		printf("v2 : %p \n", &v2);
	}
	printf("v2 : %d \n", *p);
	*p = 3000;
	printf("%p -> %d \n", p, *p);
// �������� �̿��� ���� ���� ��� ����
	// - ������ ��� �ִ� ��츸....
//	v2 = 3000;// ���� �� ����� ������ ���� �ۿ��� ��� �Ұ�



	return 0;
}