#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


int main(void){
	int W = 19;
	int H = 19;
	int omokpan[19 * 19] = { 1,0,1,1,0 };
	// 요소의 값이 0 이면 ┼

	for (int r = 0; r < H; ++r) {
		for (int c = 0; c < W; ++c) {
			// 값에 따른 분기 처리할 수 있다
			int v = omokpan[r * W + c];
			if (v == 0) {
				printf("┼ ");
			}
			else if (v == 1) {
				printf("○");
			}
			//printf("\n");
		}
		return 0;
	}
	
 }


int main_01(void) {
	int shape[40] = { 1 };
	int cur = 0;
	while (1) {
		system("cls"); // 윈도우 명령 : 화면 지우기
		for (int i = 0; i < 40; ++i) {
			//요소의 값에 따라 출력할 문자열이 다르다
			printf("%s", (shape[i])?"♥  ":"   ");// 조건연산자 - 어느 위치에도 삽입가능
			
		}
		printf("\n");
		// 1을 한칸씩 오른쪽으로 옮긴다
		cur++;
		shape[cur-1] = 1;
		shape[cur] = 1;
		cur %= 40;// 0 ~ 39 범위 조정
	}
	return 0;
}