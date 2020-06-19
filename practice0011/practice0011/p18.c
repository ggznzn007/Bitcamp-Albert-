#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	clrscr();
	for (i = 0; i <= 4; i++)
	{
		for (j = 4; j >= i; j--)
		{
			printf("%c ", i + 65);
		}
		printf("\n");
	}
	getchar();
}