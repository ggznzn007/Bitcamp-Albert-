#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	clrscr();
	for (i = 1; i <= 25; i++)
	{
		for (j = 1; j <= 100; j++) {
			printf("*");
		}
		printf("\n");
	}
	getchar();
}