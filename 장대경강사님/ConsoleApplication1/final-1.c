// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // ���Ű ó�� ����
#include <Windows.h>	// �ܼ� Ŀ�� �̵�

// global variables ///////////////////////////////////////
struct position {
	int x;
	int y;
	int u;
	int d;
	int l;
	int r;
};
struct _coord {
	int length;// arr �迭�� ����(���� ����)
//	struct position arr[30*15];// �����迭
	struct position *arr;// �����迭
};
typedef struct _coord Coord;
typedef struct position Position;

#define W	30
#define H	15
int map[H][W];// ��� �Լ� ���� ����, 0 �ʱ�ȭ

// section function body //////////////////////////////////
int showMap(void) {
	// Ű����� �̵��� ��Ű�� �̵���θ� ������ �����...
	// �� ���� �Է� �� ȭ�� �׸��� ����ϰ� ����� ����
	// <enter> ����
	system("cls");
	for (int r = 0; r < H; ++r) { // �� : H
		for (int c = 0; c < W; ++c) { // �� : W
			printf("%s",	(map[r][c] == 2 )?"��":
							(map[r][c] == 1) ? "��":"��");
		}
		putchar('\n');
	}
	return 0;
}
// �ܼ� ȭ�� �� ��ġ : gotoxy(); Win32 API ( C ), MFC C++
int drawMapWinAPI(void) {
	// Ű����� �̵��� ��Ű�� �̵���θ� ������ �����...
	// �� ���� �Է� �� ȭ�� �׸��� ����ϰ� ����� ����
	// <enter> ����
	COORD cursor = { 0 };
	map[cursor.Y][cursor.X] = 1;
	showMap();
	while (1) {// ���ѹݺ�
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		printf("��");
		// Ű���尡 ������ ��
		if (_kbhit()) { // ���ͷ�Ʈ... �̺�Ʈ....
			// �Էµ� ���� Ȯ�� ?
			char ch = _getch();// echo ����(ȭ�� �������ʴ´�)
			// ����Ű�� ���Ű�̴�... ���� ��ƴ�...
			// ���Ű �Է� �� 2byte ����, 
			if (ch == -32) {// 224 char �ִ� 127
				ch = _getch();
			}
			// �� ��° byte ���� Ű ��
			if (ch == '\r') {// <enter>
				break;// stop while
				// �Ʒ� return �ٷ� ��
			}
			//			ch = tolower(ch); toupper(ch); <ctype.h>
						// ����Ű �̵� = 1;
			if (ch == 'w' || ch == 'W' || ch == 72) {// UP
				cursor.Y--;
				if(cursor.Y<0)cursor.Y++;
			}
			if (ch == 's' || ch == 'S' || ch == 80) {// DOWN
				cursor.Y++;
				if (cursor.Y >= H)cursor.Y--;
			}
			if (ch == 'a' || ch == 'A' || ch == 75) {// LEFT
				// cursor �� �̵��� 1���� �����ε� 
				// ȭ�� ��� �� ���ڴ� 2���� ���̷� ���
				cursor.X-=2;// 2���� ũ��� �̵��ؾ� ��.
				if (cursor.X < 0)cursor.X+=2;
			}
			if (ch == 'd' || ch == 'D' || ch == 77) {// RIGHT
				cursor.X+=2;
				if (cursor.X >= W*2)cursor.X-=2;
			}
			// ���� ��ġ ǥ��
			map[cursor.Y][cursor.X/2] = 1;
		}
	}// end while
	map[cursor.Y][cursor.X / 2] = 2;
	printf("end drawMap()\n\n");
	return 0;
}

int drawMap(void) {
	// Ű����� �̵��� ��Ű�� �̵���θ� ������ �����...
	// �� ���� �Է� �� ȭ�� �׸��� ����ϰ� ����� ����
	// <enter> ����
	int iy, ix;
	iy = ix = 0;
	while (1) {// ���ѹݺ�
		system("cls");// �ܼ� �󿡼� ������ �� �ִ� ���α׷�
		for (int r = 0; r < H; ++r) { // �� : H
			for (int c = 0; c < W; ++c) { // �� : W
				if (r==iy && c==ix) {
					printf("��");// �����ڸ� ������ Ÿ���� ���ڿ�
				}
				else {
					printf("%s", (map[r][c])?"��":"��");
				}
			}
			putchar('\n');
		}// end for
		// Ű���尡 ������ ��
		if (_kbhit()) { // ���ͷ�Ʈ... �̺�Ʈ....
			// �Էµ� ���� Ȯ�� ?
			char ch = _getch();// echo ����(ȭ�� �������ʴ´�)
			// ����Ű�� ���Ű�̴�... ���� ��ƴ�...
			// ���Ű �Է� �� 2byte ����, 
			if (ch == -32) {// 224 char �ִ� 127
				ch = _getch();
			}
			// �� ��° byte ���� Ű ��
			if (ch == '\r') {// <enter>
				break;// stop while
				// �Ʒ� return �ٷ� ��
			}
//			ch = tolower(ch); toupper(ch); <ctype.h>
			// ����Ű �̵� = 1;
			if (ch == 'w' || ch == 'W' || ch == 72) {// UP
				--iy;
			}
			if (ch == 's' || ch == 'S' || ch == 80) {// DOWN
				++iy;
			}
			if (ch == 'a' || ch == 'A' || ch == 75) {// LEFT
				--ix;
			}
			if (ch == 'd' || ch == 'D' || ch == 77) {// RIGHT
				++ix;
			}
			// ���� ��ġ ǥ��
			map[iy][ix] = 1;
//			map[iy][ix] = 1 - map[iy][ix];
		}
	}// end while
	printf("end drawMap()\n\n");
	return 0;
}
Coord* searchMap(void) {
	Coord *var;
	var = (Coord*)malloc(sizeof(Coord));
	var->length = 0;
	var->arr = NULL;// Position *
	for (int r = 0; r < H; ++r) { // �� : H
		for (int c = 0; c < W; ++c) { // �� : W
			Position pos = { 0 };
			pos.y = r;
			pos.x = c;
			if (r>0 && map[r - 1][c] == 1)	pos.u = 1;
			if (r<H-2 && map[r + 1][c] == 1)	pos.d = 1;
			if (c>0 && map[r][c - 1] == 1)	pos.l = 1;
			if (c<W-2 && map[r][c + 1] == 1)	pos.r = 1;
			var->length++;
			var->arr = (Position*)realloc(var->arr, var->length * sizeof(Position));
			if (var->arr == NULL) {
				printf("\n\nfatal errror : searchMap's reallocation\n\n");
				exit(1);
			}
			var->arr[var->length - 1] = pos;
		}
	}// end for

	return var;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {

	drawMapWinAPI();
	showMap();
	Coord* cp = searchMap();// �� ��ġ���� �̵��� �� �ִ� ���� ���
	// �ڵ带 ���� �ʿ��� ����ü�� ������ �� �ִ°�??
	for (int i = 0; i < cp->length; ++i) {
		int sum = cp->arr[i].u + cp->arr[i].d
				+ cp->arr[i].l + cp->arr[i].r;
		if (sum > 2) { // ���� ������ ���
			printf("(%d, %d){ %d %d %d %d } \n",
				cp->arr[i].x, cp->arr[i].y,
				cp->arr[i].u, cp->arr[i].d,
				cp->arr[i].l, cp->arr[i].r
			);
		}// end if
	}// end for

	return 0;
}
// end program
