
#include <stdio.h>

/*
	자료형, 변수 사용
	연산자
	- 산술연산자
	- 관계연산자(비교연산자)
	- 논리연산자
	- 비트연산(2진연산)
*/
int main(void) {
	//논리 연산자 : 조건식 여러 개 조합
	// 조건식들의 순서, 관계를 파악
	printf("%d \n", (1 < 0) && ('a' == 97));
	printf("%d \n", (1 < 0) || ('a' == 97));
	printf("%d \n", !1);// 논리 반전 not
	printf("%d \n", NULL);
	Printf("%d \n", EOF);
	return 0;
}
int main_02(void) {
	// 0은 거짓, 0이 아니면 참
	printf("%d \n", 10 < 2);
	printf("%d \n", 10 > 2);
	// 정수 0 또는 1이다 -> 논리적으로 말한다..
	printf("%d \n", 10 <= 2);
	printf("%d \n", 10 >= 2);
	printf("%d \n", 10 == 2);
	printf("%d \n", 10 != 2);

	// 산술연산 : 값(정수, 실수)
	int n = 10;
	double lf = 12.34;
	char ch = 'a'; // 97
	printf("%d \n", n * 20);
	printf("%lf \n", lf * 20);
	printf("%d \n", ch * 20);
	printf("%c \n", 97 * 20);
	// char 도 실제로는 정수이다...
	//printf("%d \n", 97 / 0);
	printf("%lf \n", (double)97 / 20);
	printf("%lf \n", (double)(97 / 20));
	// 먼저 실수로 변환 후에 나누기 할 것...
	printf("%d \n", n % 5);
	//형변환 시 주의
	int a = 256;
	double b = a;// 정수 -> 실수
	int c = b;
	printf("%d %lf %d \n", a, b, c);
	return 0;
}


