#include <stdio.h>

int main(void)
{
	int num = 100;
	char ch = 'A';
	double fnum = 3.14;
	char str[] = "Korean";

	printf("정수 %d\n", num);
	printf("문자 %c, %d\n", ch, ch);
	printf("실수 %lf\n", fnum);
	printf("문자열 %s\n", str);

	return 0;
}

// Ctrl + K, C  : 주석처리
// Ctrl + K, U  : 주석해제
//void main()
//{
//
//}