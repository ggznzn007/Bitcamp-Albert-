
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ü�� ũ�⸦ �� ũ��� �����...
//#pragma pack(1)
typedef struct _rgb_color {
	unsigned char blue : 2;
	unsigned char green : 4;
	unsigned char red : 2; // ���� 8��Ʈ 1����Ʈ
}RGB;
// ��Ʈ �ʵ� ����ü

int main(void) {
	printf(" %d \n", sizeof(RGB));

	return 0;
}

/*
typedef struct car {
	 member
	int code;
	char name[80];
	double price;
}CAR, UCAR, ICAR ;
#define Car struct car
 �ڷ������� ���� ���
typedef struct car Car;
typedef unsinged int _uint;

int main_03(int argc, char** argv) {
	struct car ic;
	 ����ü�� �̸��� ª�� �ٸ��� ����ϰ� �ʹ�....
	Car mycar;
	printf(" %d \n", sizeof(Car));
	printf(" %d \n", sizeof(mycar));
	 �⺻ ũ�� ���� : ������� ���� ���� ũ��

	return 0;
}

int main_03(int argc, char** argv) {
	struct car myCar = { 1, "Grandure", 1000.10 };
	// ����ü ������ �����Ѵ�...
	// ��¥ �����Ѵ�. ( ���� ���� )
	struct car uCar = myCar;

	printf("%p vs %p \n", myCar.name, uCar.name);

	printf("{%d, %s, %lf}\n",
		uCar.code, uCar.name, uCar.price
	);

	return 0;
}

int main_02(int argc, char** argv) {
	struct car myCar = { 1, "Grandure", 1000.10};

	printf("{%d, %s, %lf}\n",
		myCar.code, myCar.name, myCar.price
		);

	return 0;
}
int main_01(void) {
	// ����� ���� �� ( ������ ) : ����ü : �������� ����
	// 1. ����ü�� ����
	// 2. ����ü�� ���� ����
	// 3. ����ü�� ���� �ȿ� ������� ó��
	//	��� �����ϴ� ���
	//	1. ������.�����
	//	2. �����ͺ�����(�ּ�)->�����

	return 0;
}
*/