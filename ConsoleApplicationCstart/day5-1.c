#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct car {
	// 멤버 
	int code;
	char name[80];
	double price; // 배열과 구조체의 공통점 여러개 자료를 가지고 있음 
				  // 차이점은 여러가지 자료들을 가지고 있음
};
int main(int arg, char** argv) {
	struct car myCar = { 1, "그랜져", 1000.10 };// 자료형 이름 
	// 구조체 변수를 복사한다.
	struct car uCar = myCar;

	printf("{%d, %s, %1f}\n",
		uCar.code, uCar.name, uCar.price
	);

	return 0;
}

	int main_02(int arg, char** argv) {
		struct car myCar = { 1, "그랜져", 1000.10 };// 자료형 이름 

		printf("{%d, %s, %1f}\n",
			myCar.code, myCar.name, myCar.price
		);

		return 0;
	}

	int main_01(void) {
	// 사용자 정의형 (복합형) : 구조체 : 변수들의 모음
	// 1.구조체형 정의
	// 2.구조체형 변수 선언
	// 3.구조체형 변수 안에 멤버들을 처리
	// 멤버 접근하는 방법
	// 1. 변수명, 멤버명
	// 2. 포인터변수명(주소) -> 멤버명


	return 0;
}