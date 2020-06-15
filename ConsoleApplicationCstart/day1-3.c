#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	// 자료형 변수의 선언과 사용
	int num;
	num = 10;
	printf("%d\n", num);// 형식 문자열 사용
	int score;
	score = 20;
	printf("%c %d %lf %s \n", 'A',12, 32.45, "string");// 형식 문자열 사용

	return 0;
}