#include "turboc.h"

// #2. 상수를 만드는	방법
//#define WIDTH 80
//#define HEIGHT 25

// #3. 상수를 만드는	방법
enum {
	WIDTH = 80, HEIGHT = 25
};

/// <summary>
/// icon을 직선으로 그리는 함수
/// </summary>
/// <param name="start">그림이 시작되는 위치</param>
/// <param name="end">그림이 끝나는 위치</param>
/// <param name="any">0이면 x축 변화, 1이면 y축 변화</param>
/// <param name="pt">x축이 변하면 y축기준, y축이 변하면 x축기준</param>
/// <param name="icon">그릴 icon모양</param>
void drawWall(int start, int end, int any, int pt, char* icon)
{
	int i = 0;
	for (i = start; i <= end; i++)
	{
		if (any == 0)
			gotoxy(i, pt);
		else if (any == 1)
			gotoxy(pt, i);

		puts(icon);
	}
}

/// <summary>
/// 좌상단점을 기준으로 너비, 높이에 해당하는 상자 그리기
/// </summary>
/// <param name="left">좌단 x</param>
/// <param name="top">상단 y</param>
/// <param name="width">너비</param>
/// <param name="height">높이</param>
void drawBox(int left, int top, int width, int height)
{
	drawWall(left, left + width, 0, top, "+");
	drawWall(left, left + width, 0, top + height, "+");
	drawWall(top, top + height, 1, left, "+");
	drawWall(top, top + height, 1, left + width, "+");
}

void main()
{
	// #1. 상수를 만드는	방법
	//const int WIDTH = 80;		// 상수
	//const int HEIGHT = 25;	// 상수
	clrscr();
	setcursortype(NOCURSOR);

	// 벽 그리기
	drawWall(0, WIDTH / 2, 0, HEIGHT + 2, "▦");	// x축
	drawWall(0, HEIGHT, 1, WIDTH + 4, "▦");		// y축

	// moveShape 코드 삽입
	int x = 0, y = 0;		// 좌표값
	int dirX = 1, dirY = 1;	// 변화값(증감)
	while (1)
	{
		drawBox(0, 0, 10, 5);
		drawBox(0, 25-5, 10, 5);
		drawBox(80 - 10, 0, 10, 5);
		drawBox(80 - 10, 25 - 5, 10, 5);
		// 가운데 상자 그리기
		int left = 0 + WIDTH/2/2;
		int top = 0 + HEIGHT/2/2;
		int width = WIDTH/2;
		int height = HEIGHT/2;
		drawBox(left, top, width, height);
		gotoxy(x, y);
		puts("◎");
		delay(50);
		gotoxy(x, y);
		puts("  ");
		x += dirX;
		y += dirY;
		// x의 경계선에 닿으면 x의 변화
		if (x == WIDTH || x == 0)
			dirX *= -1;
		// y의 경계선에 닿으면 y의 변화
		if (y == HEIGHT || y == 0)
			dirY *= -1;
	}

}