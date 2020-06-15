
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체의 크기를 실 크기로 맞춘다...
//#pragma pack(1)
typedef struct _rgb_color {
	unsigned char blue : 2;
	unsigned char green : 4;
	unsigned char red : 2;
}RGB;
typedef struct _bits {
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
}BITS;
// 비트 필드 구조체

// 자료구조 ??? 자기 참조 구조체
struct _node {
	int data;
	struct _node* prev;
	struct _node* next;
};

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
 자료형명을 새로 등록
typedef struct car Car;
typedef unsinged int _uint;

int main_03(int argc, char** argv) {
	struct car ic;
	 구조체형 이름을 짧게 다르게 사용하고 싶다....
	Car mycar;
	printf(" %d \n", sizeof(Car));
	printf(" %d \n", sizeof(mycar));
	 기본 크기 계산법 : 멤버들의 총합 보다 크다

	return 0;
}

int main_03(int argc, char** argv) {
	struct car myCar = { 1, "Grandure", 1000.10 };
	// 구조체 변수를 복사한다...
	// 진짜 복사한다. ( 깊은 복사 )
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
	// 사용자 정의 형 ( 복합형 ) : 구조체 : 변수들의 모음
	// 1. 구조체형 정의
	// 2. 구조체형 변수 선언
	// 3. 구조체형 변수 안에 멤버들을 처리
	//	멤버 접근하는 방법
	//	1. 변수명.멤버명
	//	2. 포인터변수명(주소)->멤버명

	return 0;
}
*/