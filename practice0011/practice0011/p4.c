#include <stdio.h>
#include <conio.h>

void main()
{
	char i, j;
	clrscr();
	for (i = 'A'; i <= 'E'; i++)
	{
		for (j = 'A'; j <= 'E'; j++)
		{
			printf("%c", i);
		}
		printf("\n");
	}
	getchar();
}