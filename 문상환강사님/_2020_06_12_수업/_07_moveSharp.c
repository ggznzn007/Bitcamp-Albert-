#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// No 커서
	
	int x = 0;
	for(x=0;x<=80;x++)
	{ 
		clrscr();					// 화면 전체 지우기
		gotoxy(x, 12);
		puts("#");
		delay(100);
	}
}