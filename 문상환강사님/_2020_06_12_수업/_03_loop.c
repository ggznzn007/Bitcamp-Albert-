#include <stdio.h>
#include <conio.h>

void main()
{
	printf("1. 주소 입력\n");
	printf("2. 주소 검색\n");
	printf("3. 주소 수정\n");
	printf("4. 주소 삭제\n");
	printf("5. 프로그램 종료\n");

	printf("번호를 선택하세요 >> \n");
	char sel = getchar();	// 문자 Enter
	//char sel = _getch();	// 문자만
	printf("%c 번 선택하셨습니다\n", sel);
}