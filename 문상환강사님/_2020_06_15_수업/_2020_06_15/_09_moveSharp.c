// ���� ������ �ٽ� ó������ �ݺ�

#include "turboc.h"

void main()
{
	setcursortype(NOCURSOR);	// No Ŀ��

	int x = 0;
	for (x = 0; x <= 80; x++)
	{
		gotoxy(x, 12);
		puts("#");
		delay(100);
		gotoxy(x, 12);
		puts(" ");
		if (x == 80)
			x = 0;
	}
}