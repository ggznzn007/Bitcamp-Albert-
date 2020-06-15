// 끝에 닿으면 다시 처음부터 반복

#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// No 커서

	int x = 0;
	int dir = 1;	// 우:1, 좌:-1
	while (1)
	{
		gotoxy(x, 12);
		puts("#");
		delay(10);
		gotoxy(x, 12);
		puts(" ");
		x = x + dir;	// x+= dir;
		if (x == 80)
			dir = -1;
		else if (x == 0)
			dir = 1;
	}
}