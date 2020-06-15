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
		x += dir;
		// 양끝에 닿으면 부호를 바꾸어라
		// 부호를 변경 = 증가<->감소
		if (x == 80 || x == 0)
			dir = dir * -1; // dir *= -1;
	}
}