#include <stdio.h>
#include <stdlib.h>
#define PAN_SIZE 19

// 분석 - 작년 프로젝트 소스들... 
int team01(int pan[][PAN_SIZE], int* px, int* py)
{
	// 값을 유지한다... 전역, 정적변수
	static int mystone;

	if (*px == -1) {// ~면, 할 때
		// 게임이 시작되었다. : 1팀이 여러 번 게임을 진행
		// 준비 : 변수들을 초기값, 배열 비운다...
		if (*py == -1) {// 나는 흑돌이다.
			mystone = 0;
		}
		if (*py == 0) {			// 나는 백돌이다.
			mystone = 1;
		}
	}
	else {// -1이 아닐 때
		int x = rand()%PAN_SIZE;
		int y = rand() % PAN_SIZE;
		// 상대가 돌을 어디에 두었는가
		// 나는 상대방의 돌 옆에 두겠다....
		//	전달되는 *px, *py 상대방의 위치
		x = *px;
		y = *py;
		// 위치 주변에 8자리
		for (int dy = y - 1; dy <= (y + 1); ++dy) {
			for (int dx = x - 1; dx <= (x + 1); ++dx) {
				if (pan[dy][dx] > 1) {
					x = dx;
					y = dy;
//					break;// 반복 멈춤 - 첫 반복만 나감
					goto out;// 중첩 반복을 한 번에 벗어나기
				}
			}
		}
		// pan[19][19] : 범위 판단
out:
		*px = x ;
		*py = y ;
	}

	return 0;
}
