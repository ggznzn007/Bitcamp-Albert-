#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
	int i, j;
	
	for (j = 2; j <= 9; j++) {
			for (i = 1; i <= 9; i++)
			printf("%d x %d = %d\n", j, i, j * i);
			
	}
	return 0;
}

//int main(void) {
//	int leftdan = 2;
//	int dan;
//	int v;
//	int unit = 3;// 한 줄에 몇개 단을 출력하겠는가?
//	for (int bl = 0; bl < 3; ++bl) {
//		leftdan += unit;
//		for (int row = 0; row < 9; ++row) {
//			v = row + 1;
//			for (int col = 0; col < unit; col++) {
//				dan = leftdan + col;
//				if (dan <= 9) {
//					printf("%d x %d = %d\n", dan, v, (dan * v));
//				}
//				printf("\n");
//			}
//			printf("-----\n");
//		}
//		return 0;
//	}
//}
