#include <stdio.h>

void viewMenu()
{
	printf("\t<주소록 관리 프로그램>\n");
	printf("1. 입력\n");
	printf("2. 검색\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 전체출력\n");
	printf("6. 종료\n");
}

int getSelNum()
{
	int selNum = 0;
	printf("\n번호를 선택하세요 >> ");
	scanf_s("%d", &selNum);

	return selNum;
}

void inputAddress()
{
	printf("입력처리하였습니다~\n");
}
void searchAddress()
{
	printf("검색처리하였습니다~\n");
}
void updateAddress()
{
	printf("수정처리하였습니다~\n");
}
void deleteAddress()
{
	printf("삭제처리하였습니다~\n");
}
void printAllAddress()
{
	printf("전체출력처리하였습니다~\n");
}
void exitApp() 
{
	printf("프로그램 종료하겠습니다~\n");
}

void processWork(int selNum)
{
	if (selNum == 1)
		inputAddress();
	else if (selNum == 2)
		searchAddress();
	else if (selNum == 3)
		updateAddress();
	else if (selNum == 4)
		deleteAddress();
	else if (selNum == 5)
		printAllAddress();
	else if (selNum == 6)
		exitApp();
		
}

void main()
{
	int selNum = 0;

	// 업무처리가 끝난 후 다시 메뉴가 나타날 수 
	// 있도록 무한 루프 처리를 한다.
	while (1)
	{
		viewMenu();				// 1. 메뉴 보여주기
		selNum = getSelNum();	// 2. 사용자 입력
		processWork(selNum);	// 3. 처리
	}
}