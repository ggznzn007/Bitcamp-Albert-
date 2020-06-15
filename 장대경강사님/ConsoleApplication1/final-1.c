// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // 기능키 처리 가능
#include <Windows.h>	// 콘솔 커서 이동

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
	int length;// arr 배열의 길이(점차 증가)
//	struct position arr[30*15];// 정적배열
	struct position *arr;// 동적배열
};
typedef struct _coord Coord;
typedef struct position Position;

#define W	30
#define H	15
int map[H][W];// 모든 함수 접근 가능, 0 초기화

// section function body //////////////////////////////////
int showMap(void) {
	// 키보드로 이동을 시키고 이동경로를 벽으로 만든다...
	// 한 번씩 입력 시 화면 그리고 출력하고 지우는 동작
	// <enter> 종료
	system("cls");
	for (int r = 0; r < H; ++r) { // 행 : H
		for (int c = 0; c < W; ++c) { // 열 : W
			printf("%s",	(map[r][c] == 2 )?"→":
							(map[r][c] == 1) ? "□":"■");
		}
		putchar('\n');
	}
	return 0;
}
// 콘솔 화면 내 위치 : gotoxy(); Win32 API ( C ), MFC C++
int drawMapWinAPI(void) {
	// 키보드로 이동을 시키고 이동경로를 벽으로 만든다...
	// 한 번씩 입력 시 화면 그리고 출력하고 지우는 동작
	// <enter> 종료
	COORD cursor = { 0 };
	map[cursor.Y][cursor.X] = 1;
	showMap();
	while (1) {// 무한반복
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		printf("☆");
		// 키보드가 눌렸을 때
		if (_kbhit()) { // 인터럽트... 이벤트....
			// 입력된 문자 확인 ?
			char ch = _getch();// echo 없음(화면 보이지않는다)
			// 방향키는 기능키이다... 아주 어렵다...
			// 기능키 입력 시 2byte 전달, 
			if (ch == -32) {// 224 char 최대 127
				ch = _getch();
			}
			// 두 번째 byte 실제 키 값
			if (ch == '\r') {// <enter>
				break;// stop while
				// 아래 return 바로 전
			}
			//			ch = tolower(ch); toupper(ch); <ctype.h>
						// 방향키 이동 = 1;
			if (ch == 'w' || ch == 'W' || ch == 72) {// UP
				cursor.Y--;
				if(cursor.Y<0)cursor.Y++;
			}
			if (ch == 's' || ch == 'S' || ch == 80) {// DOWN
				cursor.Y++;
				if (cursor.Y >= H)cursor.Y--;
			}
			if (ch == 'a' || ch == 'A' || ch == 75) {// LEFT
				// cursor 의 이동은 1글자 길이인데 
				// 화면 출력 시 글자는 2글자 길이로 출력
				cursor.X-=2;// 2글자 크기로 이동해야 함.
				if (cursor.X < 0)cursor.X+=2;
			}
			if (ch == 'd' || ch == 'D' || ch == 77) {// RIGHT
				cursor.X+=2;
				if (cursor.X >= W*2)cursor.X-=2;
			}
			// 현재 위치 표시
			map[cursor.Y][cursor.X/2] = 1;
		}
	}// end while
	map[cursor.Y][cursor.X / 2] = 2;
	printf("end drawMap()\n\n");
	return 0;
}

int drawMap(void) {
	// 키보드로 이동을 시키고 이동경로를 벽으로 만든다...
	// 한 번씩 입력 시 화면 그리고 출력하고 지우는 동작
	// <enter> 종료
	int iy, ix;
	iy = ix = 0;
	while (1) {// 무한반복
		system("cls");// 콘솔 상에서 실행할 수 있는 프로그램
		for (int r = 0; r < H; ++r) { // 행 : H
			for (int c = 0; c < W; ++c) { // 열 : W
				if (r==iy && c==ix) {
					printf("★");// 영문자를 제외한 타국어 문자열
				}
				else {
					printf("%s", (map[r][c])?"□":"■");
				}
			}
			putchar('\n');
		}// end for
		// 키보드가 눌렸을 때
		if (_kbhit()) { // 인터럽트... 이벤트....
			// 입력된 문자 확인 ?
			char ch = _getch();// echo 없음(화면 보이지않는다)
			// 방향키는 기능키이다... 아주 어렵다...
			// 기능키 입력 시 2byte 전달, 
			if (ch == -32) {// 224 char 최대 127
				ch = _getch();
			}
			// 두 번째 byte 실제 키 값
			if (ch == '\r') {// <enter>
				break;// stop while
				// 아래 return 바로 전
			}
//			ch = tolower(ch); toupper(ch); <ctype.h>
			// 방향키 이동 = 1;
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
			// 현재 위치 표시
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
	for (int r = 0; r < H; ++r) { // 행 : H
		for (int c = 0; c < W; ++c) { // 열 : W
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
	Coord* cp = searchMap();// 각 위치에서 이동할 수 있는 방향 기록
	// 코드를 보고 필요한 구조체를 정의할 수 있는가??
	for (int i = 0; i < cp->length; ++i) {
		int sum = cp->arr[i].u + cp->arr[i].d
				+ cp->arr[i].l + cp->arr[i].r;
		if (sum > 2) { // 교차 지점만 출력
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
