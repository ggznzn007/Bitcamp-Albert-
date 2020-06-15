// 로컬 헤더 파일을 아래처럼 포함
#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// No 커서
	clrscr();					// 화면 청소
	gotoxy(20, 12);
	printf("감사합니다\n");
}