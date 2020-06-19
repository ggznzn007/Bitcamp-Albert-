#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 20;
	int i, j;
	clrscr();
	for (i = n; i >= 1; i--)
	{
		for (j = n; j >= 1; j--)
		{
			if (i >= j)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	getchar();
}