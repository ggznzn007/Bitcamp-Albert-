#include <stdio.h>//표준 입출력 처리
#include <stdlib.h>//라이브러리 처리
#include <string.h>//문자열 처리
#include <conio.h>//기능키 처리가능하게 하는 헤더 파일

int drawLine(int x);

int main(int argc, char* argv[]) {
	drawLine(1);
	drawLine(2);
	drawLine(3);
	return 0;
}


int drawLine(int x) {
	int y;
//	int x = 5;
	y = (1 * x) + 5;
	for (int r = 0; r < 10; ++r) {
		printf("[%2d]", r);
		for (int c = 0; c < 10; ++c) {
			// 각 위치(r,c)
			if (r == y && c == x) {// x y 값에 따라서 달라진다
				printf("★★");
			}
			else {
				printf(" ");
			}			
		}
		printf("\n");
	}
	return 0;
}