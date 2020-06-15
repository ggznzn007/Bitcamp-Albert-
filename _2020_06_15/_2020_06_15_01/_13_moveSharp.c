// 끝에 닿으면 다시 처음부터 반복

#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// No 커서

	int x = 0, y = 0;		// 좌표값
	int dirX = 1, dirY = 1;	// 변화값(증감)
	while (1)
	{
		gotoxy(x, y);
		puts("#");
		delay(50);
		gotoxy(x, y);
		puts(" ");
		x += dirX;
		y += dirY;
		// x의 경계선에 닿으면 x의 변화
		if (x == 80 || x == 0)
			dirX *= -1;
		// y의 경계선에 닿으면 y의 변화
		if (y == 25 || y == 0)
			dirY *= -1;
	}
}