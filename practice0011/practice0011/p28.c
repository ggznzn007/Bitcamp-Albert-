#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 5;
	int i, j, k;
	clrscr();
	for (i = 0; i < n; i++)// i가 n까지 1씩 증가하는동안
	{
		for (j = n - 1; j > i; j--)// j가 n-1일때 i보다 커질때까지 1씩 감소하는동안
		{
			printf(" ");// 공백을 출력하고

		}
		for (k = 0; k <= i; k++)// k가 i와 같아질때까지 1씩증가하는 동안
		{
			printf("%c", k + 65);//ASCII CODE// k+65값을 문자열로 출력하고
		}
		printf("\n");// 개행하라
	}
	getchar();
}