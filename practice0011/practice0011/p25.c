#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 5;// size
	int i, j, k;
	clrscr();
	for (i = 1; i <= n; i++)
	{
		for (j = n - 1; j >= i; j--)
		{
			printf(" ");
		}
		for (k = 1; k <= i; k++)
		{
			printf("%d", i);
		}
		printf("\n");

	}
	getchar();
}