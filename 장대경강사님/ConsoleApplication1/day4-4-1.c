#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 전역변수 : 함수 밖에서 선언된 변수
//	- 이 소스 파일에 정의된 모든 함수들이 사용 가능
int gValue = 10; // 전달하는 방법이 너무 어려워요 ~ 권장안함

int f2() {
	int v3 = 100;
	// 이 함수가 살아 있는 동안에만 사용 가능
	gValue = 100;

	return 0;
}

int f1() {
	f2();
	gValue = 10;
	return 0;
}

int main(int argc, char** argv) {
	f1();
	gValue = 1;
	return 0;
}

int main_01(int argc, char** argv) {
	// 선언 위치에 따른 변수의 구분 : 변수 지역성
	// 지역변수 : 함수 내에서 선언된 변수 : 이 함수만 사용할 수 있다.
	// { } 도 지역성을 가진다...
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
// 포인터을 이용한 간접 참조 방식 가능
	// - 변수가 살아 있는 경우만....
//	v2 = 3000;// 지역 내 선언된 변수는 지역 밖에서 사용 불가



	return 0;
}