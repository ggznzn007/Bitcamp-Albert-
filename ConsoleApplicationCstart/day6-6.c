#include <stdio.h>
#include <ctype.h>
// 입력받는 문자열 중에 숫자의 개수 세기
	// 입력받는 문자열 중에 영문자의 개수 세기
	// 입력받는 문자열 중에 단어의 개수 세기
	// = if??? count??? 숫자인지 문자인지 판별
	// 문자의 띄어쓰기에 따라 단어 판별


int main(void) {//개수 세기???

	char ch;
	int digit = 0;// 숫자 
	int alpha = 0;// 영문자
	int words = 0;// 띄어쓰기
	int numbers = 0;// 정수
	
	
	while ((ch = getchar()) != EOF) {
		if (ch >= '0' && ch <= '9') digit++;
		if (ch >= 'A' && ch <= 'z') alpha++;
		if (ch ==  ' ') words++;
	}
	printf("digit : %d\n", digit);
	printf("alpha : %d\n", alpha);
	printf("words : %d\n", words);
	
	// word 단어 끝의 알파벳을 기준으로 카운팅 해보자 
	
	return 0;

}