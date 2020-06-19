#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 30;
	int i, j, k;
	clrscr();
	for (i = n; i >= 1; i--)//
	{
		for (j = n - 1; j >= i; j--)// 
		{
			printf(" ");// 공백을 출력하고

		}
		for (k = 1; k <= i; k++)//
		{
			printf("*");
		}
		printf("\n");// 개행하라
	}
	getchar();
}