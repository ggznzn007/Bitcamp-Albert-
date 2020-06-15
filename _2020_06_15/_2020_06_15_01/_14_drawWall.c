#include "turboc.h"

void main()
{
	clrscr();
	setcursortype(NOCURSOR);

	int i = 0;
	for (i = 0; i <= 40; i++)
	{
		gotoxy(i, 24);
		puts("¢Ë");
	}

	int j = 0;
	for (j = 0; j <= 25; j++)
	{
		gotoxy(79, j);
		puts("¢Ë");
	}
}