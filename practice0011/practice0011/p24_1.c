#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 30;//ũ�� ����
	int i, j;

	clrscr();
	for (i = 1; i <= n; i++)
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