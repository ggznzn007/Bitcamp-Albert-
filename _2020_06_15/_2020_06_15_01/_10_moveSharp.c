// 끝에 닿으면 다시 처음부터 반복

#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// No 커서

	int x = 0;
	//for(;;)
	while(1)
	{
		for (x = 0; x <= 80; x++)
		{
			gotoxy(x, 12);
			puts("#");
			delay(10);
			gotoxy(x, 12);
			puts(" ");
		}
		for (x = 80; x >= 0; x--)
		{
			gotoxy(x, 12);
			puts("#");
			delay(10);
			gotoxy(x, 12);
			puts(" ");
		}
	}
}