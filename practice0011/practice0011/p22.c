#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	clrscr();
	for (i = 4; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%c ", i + 65);
		}
		printf("\n");
	}
	getchar();
}