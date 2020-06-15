#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 제어문
	반복 : for while do-while
	분기 : if(논리) switch(상수, 산술)
*/
int main(void) {
	// 1 ~25까지 연속 정수들을 출력
	// 5 * 5 출력하는 몇 가지 방법
	// 표 : 2차 구조 표현
	int v = 1;
	for (int r = 0; r < 5; ++r) {
		for (int c = 0; c < 5; ++c) {
			printf("%d\t", v);
			v++;//연속하는 정수 값
			if (v > 25) {
				// 강제 종료
				exit(1);
			}
		}
		printf("\n");
	}

	int cnt = 0;
	for (int v = 1; v < 26; ++v) {
		printf("%d", v);
		cnt++;
		// 행 하나에 5개씩 출력하면 행을 내린다
		if (cnt == 5) {
			printf("\n");
			cnt = 0;
		}
		
	}
}
int main_01(void) {
	// 1 ~ 25 까지 연속하는 정수들을 출력 범위 지정을 명확히 해야 됨
	//printf(""); 제어문으로 코드를 줄이거나 변경이 쉽게 만드는 목적
	int min = 100;// 입력
	int max = 25;// 입력
	// 사용자 순서를 반대로 입력하는 경우
	// 인지(판단) - 분기문 
	if (min > max) {
		// 두 변수의 값을 교환한다/ 변수 하나를 백업해서 따로 두고 교환함
		int temp = min;
		min = max;
		max = temp;
		// 비트연산자 XOR 연산 활용 가능 
	}

	for (int n = min ;n <= max; n = n++ )
	{
		printf("%d", n);
	}
	printf("\n");
	return 0;
}