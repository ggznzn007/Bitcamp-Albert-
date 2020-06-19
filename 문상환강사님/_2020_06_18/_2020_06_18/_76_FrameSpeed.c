#include "turboc.h"

// #2. 상수를 만드는	방법
//#define WIDTH 80
//#define HEIGHT 25

// #3. 상수를 만드는	방법
enum {
	WIDTH = 80, HEIGHT = 25
};

#define TRUE	1
#define FALSE	0

/// <summary>
/// icon을 직선으로 그리는 함수
/// </summary>
/// <param name="start">그림이 시작되는 위치</param>
/// <param name="end">그림이 끝나는 위치</param>
/// <param name="any">0이면 x축 변화, 1이면 y축 변화</param>
/// <param name="pt">x축이 변하면 y축기준, y축이 변하면 x축기준</param>
/// <param name="icon">그릴 icon모양</param>
void drawWall(int start, int end, int any, int pt, const char* icon)
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
	drawWall(left, left + width, 0, top, "+");			// 상단 x축 Edge
	drawWall(left, left + width, 0, top + height, "+");	// 하단 x축 Edge
	drawWall(top, top + height, 1, left, "+");			// 좌단 y축 Edge
	drawWall(top, top + height, 1, left + width, "+");	// 우단 y축 Edge
}

void drawXLine(int sX, int eX, int yPos, const char* icon)
{
	int x = 0;
	for (x = sX; x <= eX; x++)
	{
		gotoxy(x, yPos);
		puts(icon);
	}
}
void drawYLine(int sY, int eY, int xPos, const char* icon)
{
	int y = 0;
	for (y = sY; y <= eY; y++)
	{
		gotoxy(xPos, y);
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
void drawBox1(int left, int top, int width, int height)
{
	drawXLine(left, left + width, top, "─");
	drawXLine(left, left + width, top + height, "─");
	drawYLine(top, top + height, left, "│");
	drawYLine(top, top + height, left + width, "│");
}

void drawBar(int x, int y, char* bar)
{
	gotoxy(x, y);
	puts(bar);
}

void main()
{
	int bar_speed = 1;	// 바의 속도
	int ball_speed = 10;	// 볼의 속도
	int frame_cnt = 0;	// while문 반복 프레임 수
	int isDrawBall = 1;	// 1이면 볼 그리기, 0이면 볼 지우기

	char* bar = "▣▣▣▣";
	int preX, preY;
	int newX, newY;
	preX = newX = WIDTH / 2 - strlen(bar) / 2;
	preY = newY = HEIGHT / 5 * 4;

	// #1. 상수를 만드는	방법
	//const int WIDTH = 80;		// 상수
	//const int HEIGHT = 25;	// 상수
	clrscr();
	setcursortype(NOCURSOR);

	// 벽 그리기
	drawXLine(0, WIDTH, HEIGHT + 2, "▦");		// x축
	drawYLine(0, HEIGHT, WIDTH + 2, "▦");		// y축
	drawBar(newX, newY, bar);	// 바 그리기

	// moveShape 코드 삽입
	int x = 0, y = 0;		// 좌표값
	int dirX = 1, dirY = 1;	// 변화값(증감)
	while (1)
	{
		// 바의 영역
		if (frame_cnt % bar_speed == 0)
		{
			preX = newX;
			preY = newY;

			if (GetAsyncKeyState(VK_UP) & 0x8000)
				newY--;
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
				newY++;
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
				newX--;
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
				newX++;

			if (newX <= 0 || newX + strlen(bar) >= WIDTH)
				newX = preX;
			if (newY <= 0 || newY >= HEIGHT)
				newY = preY;

			// 좌표의 변화가 있을 때만 다시 그리자
			if (newX != preX || newY != preY)
			{
				drawBar(preX, preY, "        ");
				drawBar(newX, newY, bar);
			}
		}

		// 볼의 영역
		if (isDrawBall == 1)// && frame_cnt % ball_speed == 0)
		{
			isDrawBall = 0;
			// 이곳에 변수를 선언하면 while문이
			// 반복될 때 계속 재선언된다.
			// 그래서 x, y값이 0으로 초기화된다.
			//int x = 0, y = 0;		// 좌표값
			//int dirX = 1, dirY = 1;	// 변화값(증감)

			drawBox1(0, 0, 10, 5);
			drawBox1(0, 25 - 5, 10, 5);
			drawBox1(80 - 10, 0, 10, 5);
			drawBox1(80 - 10, 25 - 5, 10, 5);
			// 가운데 상자 그리기
			int left = 0 + WIDTH / 2 / 2;
			int top = 0 + HEIGHT / 2 / 2;
			int width = WIDTH / 2;
			int height = HEIGHT / 2;
			drawBox1(left, top, width, height);
			gotoxy(x, y);
			puts("◎");
		}
		//delay(100);
		else if (isDrawBall == 0 && frame_cnt % ball_speed == 0)
		{
			isDrawBall = 1;
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

		delay(10);
		frame_cnt++;
	}
}