#include <stdio.h>
#include <windows.h>


int badukdol[30][30] = { 0 };
int dol = 1;
char key;
int x = 20, y = 10;
void draw_badukpan(); //바둑판그리는함수 선언
void gotoxy(int x, int y); //커서이동함수 선언 
void draw_dol(); // 바둑돌그리는함수 선언
void erase_dol(int x, int y); // 바둑돌지우는함수 선언
void insert_key(char key, int *x, int *y); // 키입력받는 함수 선언
void put_spacebar(int badukdol[][30], int x, int y); // 바둑돌놓는함수선언
void draw_badukdol(int badukdol[][30]); // 바둑돌그리는함수 선언
int winner(int badukdol[][30]);
void play();

void main() {
	printf("\n");
	printf("\t\t\t #2인용 오목게임#\n\n");

	printf("@게임설명 : 바둑과 같이 흑백의 돌로 바둑판 선상에 세로/가로/대각선 \n\t    어느 쪽으로나 먼저 5개를 나란히 놓는 사람이 이기는 바둑놀이\n\n");

	printf("@조작방법 : →(우로한칸이동)\t←(좌로한칸이동)\n\t   ↑(위로한칸이동)\t↓(아래로한칸이동)\n\t   space bar(바둑돌놓기)\n\n");

	printf("\t\t ==========================================\n");
	printf("\t\t∥ Enter키를 입력하시면 게임이 시작됩니다 ∥\n");
	printf("\t\t ==========================================\n\n");

	printf("@만든이 : 임승훈\n@최종수정날짜 : 2016-10-09 ");
	char ch = getch(); // 엔터키 입력받는 변수

	if (ch == 13) {
		system("cls");
		play();

	}

}

void play() {

	draw_badukpan(); // 바둑판 가로20 세로 20 생성
	gotoxy(x, y);
	draw_dol();

	do {
		key = getch();
		erase_dol(x, y);
		insert_key(key, &x, &y);
		draw_badukdol(badukdol);
		if (winner(badukdol))
		{
			return;
		}
		gotoxy(x, y);
		draw_dol();
	} while (key != 27);

};

void draw_badukpan() {
	int i, j;
	printf("┌");
	for (i = 0; i < 20; i++)
	{
		printf("┬");
	}
	printf("┐\n");
	for (i = 0; i < 20; i++)
	{
		printf("├");
		for (j = 0; j < 20; j++)
		{
			printf("┼");
		}
		printf("┤\n");
	}
	printf("└");
	for (i = 0; i < 20; i++)
	{
		printf("┴");
	}
	printf("┘\n");
}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_dol() {
	if (dol == 1)
	{
		printf("○");
	}
	else {
		printf("●");
	}
};

void erase_dol(int x, int y) {

	gotoxy(x, y);
	if (x == 0 && y == 0)
	{
		printf("┌");
	}
	else if (x == 42 && y == 0)
	{
		printf("┐");
	}
	else if (x == 0 && y == 21)
	{
		printf("└");
	}
	else if (x == 42 && y == 21)
	{
		printf("┘");
	}
	else if (x == 0)
	{
		printf("├");
	}
	else if (y == 0)
	{
		printf("┬");
	}
	else if (x == 42)
	{
		printf("┤");
	}
	else if (y == 21)
	{
		printf("┴");
	}
	else
	{
		printf("┼");
	}

};

void insert_key(char key, int *x, int *y) {

	switch (key) {
	case 75: if (*x - 2 < 0) {
		break;
	}
			 else { *x -= 2; }

			 break; // 왼쪽
	case 77: if (*x + 2 > 42)
	{
		break;
	}
			 else {
				 *x += 2;
			 }

			 break; // 오른쪽
	case 72: if (*y - 1 < 0)
	{
		break;
	}
			 else {
				 *y -= 1;
			 }
			 break; // 위쪽
	case 80: if (*y + 1 > 21)
	{
		break;
	}
			 else {
				 *y += 1;
			 }
			 break; // 아래쪽
	case 32: put_spacebar(badukdol, *x, *y); // 스페이스바
		break;

	default:
		break;
	}
}

void put_spacebar(int badukdol[][30], int x, int y) {
	if (badukdol[y][x / 2] == 0)
	{
		if (dol == 1)
		{
			badukdol[y][x / 2] = 1;
			dol = 2;
		}
		else
		{
			badukdol[y][x / 2] = 2;
			dol = 1;
		}
	}



};

void draw_badukdol(int badukdol[][30])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (badukdol[j][i] == 1)
			{
				gotoxy(i * 2, j);
				printf("○");
			}
			else if (badukdol[j][i] == 2)
			{
				gotoxy(i * 2, j);
				printf("●");
			}
		}
	}
};

int winner(int badukdol[][30])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (badukdol[i][j] == 1 && badukdol[i][j + 1] == 1 && badukdol[i][j + 2] == 1 && badukdol[i][j + 3] == 1 && badukdol[i][j + 4] == 1)
			{
				gotoxy(20, 10);
				printf("흑돌 승리");
				getch();
				return 1;
			}// 흑돌 가로
			else if (badukdol[i][j] == 2 && badukdol[i][j + 1] == 2 && badukdol[i][j + 2] == 2 && badukdol[i][j + 3] == 2 && badukdol[i][j + 4] == 2)
			{
				gotoxy(20, 10);
				printf("백돌 승리");
				getch();
				return 1;
			}//백돌 가로

			else if (badukdol[j][i] == 1 && badukdol[j + 1][i] == 1 && badukdol[j + 2][i] == 1 && badukdol[j + 3][i] == 1 && badukdol[j + 4][i] == 1)
			{
				gotoxy(20, 10);
				printf("흑돌 승리");
				getch();
				return 1;
			} //흑돌 세로
			else if (badukdol[j][i] == 2 && badukdol[j + 1][i] == 2 && badukdol[j + 2][i] == 2 && badukdol[j + 3][i] == 2 && badukdol[j + 4][i] == 2)
			{
				gotoxy(20, 10);
				printf("백돌 승리");
				getch();
				return 1;
			}//백돌 세로

			else if (badukdol[i][j] == 1 && badukdol[i + 1][j + 1] == 1 && badukdol[i + 2][j + 2] == 1 && badukdol[i + 3][j + 3] == 1 && badukdol[i + 4][j + 4] == 1)
			{
				gotoxy(20, 10);
				printf("흑돌 승리");
				getch();
				return 1;
			}// 흑돌 왼쪽위대각선

			else if (badukdol[i][j] == 2 && badukdol[i + 1][j + 1] == 2 && badukdol[i + 2][j + 2] == 2 && badukdol[i + 3][j + 3] == 2 && badukdol[i + 4][j + 4] == 2)
			{
				gotoxy(20, 10);
				printf("백돌 승리");
				getch();
				return 1;
			}// 백돌 왼쪽위각선

			else if (badukdol[19 - j][i] == 1 && badukdol[18 - j][i + 1] == 1 && badukdol[17 - j][i + 2] == 1 && badukdol[16 - j][i + 3] == 1 && badukdol[15 - j][i + 4] == 1)
			{
				gotoxy(20, 10);
				printf("흑돌 승리");
				getch();
				return 1;
			} //흑돌 아래쪽대각선

			else if (badukdol[19 - j][i] == 2 && badukdol[18 - j][i + 1] == 2 && badukdol[17 - j][i + 2] == 2 && badukdol[16 - j][i + 3] == 2 && badukdol[15 - j][i + 4] == 2)
			{
				gotoxy(20, 10);
				printf("백돌 승리");
				getch();
				return 1;
			} //백돌 아래쪽대각선

		}
	}

	return 0;
};