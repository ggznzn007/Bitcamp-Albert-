

#include <stdio.h>

int main(void) {

	char ch;
	char prev;
	int digit = 0;// 숫자
	int alpha = 0;// 영문자 
	int words = 0;// 띄어쓰기
	int numbers = 0;// 정수들의 총합
	int n = 0;// 총 입력 수
	while ( (ch = getchar() ) != EOF ) {
		// 입력받은 문자에


		if (n > 0 && prev == ch) {
		}
		n++;
		prev = ch;
	}
	printf("\n");

	return 0;
}