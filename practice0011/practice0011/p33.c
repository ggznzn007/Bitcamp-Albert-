#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 5;// 전체 사이즈
	int i, j, k;
	clrscr();
	for (i = n - 1; i >= 0; i--)// 아이가 엔부터 1일 될때 까지 1씩 감소하는 동안
	{
		for (j = n - 1; j > i; j--)// 제이가 엔부터 아이보다 클때까지 1씩 감소하는 동안
		{
			printf(" ");// 공백을 출력하라
		}
		for (k = 0; k <= i; k++);//케이가 1부터 아이보다작거나 같을때 까지 1씩증가하는 동안
		{
			printf("%c", i + 65);// 인트값을 문자로 해서 케이의 값에 아스키63을 증가시켜 출력하라
		}
		printf("\n");// 엔터를 때리라
	}
	getchar();
}