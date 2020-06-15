// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>// 기능키 처리 가능


// global variables ///////////////////////////////////////
struct position {
	int x;
	int y;
	int u;
	int d;
	int l;
	int r;
};
struct _Coord {
	int length;// arr 배열의 길이(점차 증가)
	//struct position arr[40*30]; //정적배열
	struct position* arr; // 동적배열

};
typedef struct _coord Coord;
typedef struct position Position;

#define W 40//매크로 상수 정의함 대입연산 불가능
#define H 30//매크로 상수 정의함 대입연산 불가능
int map[H][W];//전역배열(모든 함수에서 접근 가능), 자동 0 초기화됨

// section function body //////////////////////////////////
int showMap(void) {
	//키보드로 이동을 시키고 이동경로를 벽으로 만든다
	//한 번 입력시 화면 그리고 출력하고 지우는 동작
	// 엔터키 종료
	for (int r = 0; r < H; ++r) { // 행 개념 : H
		for (int c = 0; c < W; ++c) { // 열 개념 : W
			map[r][c] = 1;
		}
	}
	return 0;

}
// 콘솔 화면 내 위치 : gotoxy(); win32 api//
int drawMap(void) {
	//키보드로 이동을 시키고 이동경로를 벽으로 만든다
	//한 번 입력시 화면 그리고 출력하고 지우는 동작
	// 엔터키 종료
	int iy, ix;
	iy = ix = 0;
	while (1) {//무한루프
		system("cls");//콘솔 상에서 실행할 수 있는 프로그램// 화면지우기
		for (int r = 0; r < H; ++r) { // 행 개수 개념 : H
			for (int c = 0; c < W; ++c) { // 열 개수 개념 : W	
				if (r==iy && c==ix) {
					printf("★");//영문자를 제외한 타국어는 문자열
				}
				else {
				printf("%s", (map[r][c])?"□":"■");// 조건 연산자 형식
				}
				
			}
			putchar('\n');// 행이라는 표현을 하려면 개행문자 출력 필요
		}// end for
		// 키보드가 눌렸을 때
		if (_kbhit()) {// 인터럽트, 이벤트발생
			// 입력된 문자 확인?
			char ch = _getch();//echo 없음(화면에 보이지않음)
			// 방향키는 기능키 - 아주 어렵다
			// 기능키 입력 시 2바이트 전달// 첫1바이트는 0 또는 0xE0
			
			if (ch == -32) {// 224 char 변수는 최대 127
				ch = _getch();
				
			}			
			// 두번째 바이트 실제 키값 == 두번 읽어야 한다 
			if (ch == '\r') {// <enter> = \r  인식 conio.h시
				break;// stop while
				// 아래 return 바로 전으로
			} 
			//ch = tolower(ch); //소문자변형함수 //ctype.h 헤더 필요
							  // 방향키 이동 키보드 키로
			//방향키 이동 =1;
			if (ch == 'w'|| ch == 'W' || ch == 72 ) {// UP
				--iy; 
			}
			if (ch == 's' || ch == 'S' || ch == 80 ) {//DOWN
				++iy;
			}
			if (ch == 'a' || ch == 'A' || ch == 75 ) {//LEFT
				--ix;
			}
			if (ch == 'd' || ch == 'D' || ch == 77 ) {//RIGHT
				++ix;
			}
			//현재 위치표시
			map[iy][ix] =  1;
			//map[iy][ix] =1 - map[iy][ix]; // 토글 왔다 갔다
		}
	}// end while
	printf("end drawMap()\n\n");
	return 0;

}
// 망할 구조체 망할 배열 망할 포인터

Coord* searchMap(void) {
//	map[][];
	Coord *var;
	var = (Coord*)malloc(sizeof(Coord));
	var->length = 0;
	var->arr = (Position*)malloc(var->length * sizeof(Position));
	return &var;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {
	
	//drawMap();// 호출하는 위치보다 위에 반드시 선언 또는 {정의}가 있어야함
	Coord* cp;
	cp = searchMap(); // map[][] 탐색 길이를 알 수 없는 배열 - 동적배열 생성
	for (int i = 0; i < cp->length ; ++i) {
		printf("(%d, %d){ %d %d %d %d } \n",
			cp->arr[i].x,// 배열을 포장하는 개념
			cp->arr[i].y,// 배열을 포장하는 개념
			cp->arr[i].u,
			cp->arr[i].d,
			cp->arr[i].l,
			cp->arr[i].r
			);
	}

	return 0;
}



// end program


