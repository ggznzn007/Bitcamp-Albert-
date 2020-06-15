#include <stdio.h>

void main()
{
	int cnt = 0;
	//for (cnt = 1; cnt <= 5; ++cnt)
	for (cnt = 1; cnt <= 10000; ++cnt)
	{
		printf("나무를 %d번 찍었습니다. 쿵~\n", cnt);
	}

	printf("나무를 캐었습니다!!\n");
}