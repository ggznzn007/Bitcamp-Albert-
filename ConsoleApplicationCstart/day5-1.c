#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct car {
	// ��� 
	int code;
	char name[80];
	double price; // �迭�� ����ü�� ������ ������ �ڷḦ ������ ���� 
				  // �������� �������� �ڷ���� ������ ����
};
int main(int arg, char** argv) {
	struct car myCar = { 1, "�׷���", 1000.10 };// �ڷ��� �̸� 
	// ����ü ������ �����Ѵ�.
	struct car uCar = myCar;

	printf("{%d, %s, %1f}\n",
		uCar.code, uCar.name, uCar.price
	);

	return 0;
}

	int main_02(int arg, char** argv) {
		struct car myCar = { 1, "�׷���", 1000.10 };// �ڷ��� �̸� 

		printf("{%d, %s, %1f}\n",
			myCar.code, myCar.name, myCar.price
		);

		return 0;
	}

	int main_01(void) {
	// ����� ������ (������) : ����ü : �������� ����
	// 1.����ü�� ����
	// 2.����ü�� ���� ����
	// 3.����ü�� ���� �ȿ� ������� ó��
	// ��� �����ϴ� ���
	// 1. ������, �����
	// 2. �����ͺ�����(�ּ�) -> �����


	return 0;
}