#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <conio.h> 
#include <time.h>

int main() {
	int i;
	int j;
	int k;
		for (int i = 0; i <= 3; ++i) {
			for (int j = 1; j <= 9; ++j) {
				for (int k = (i * 3 + 2); k < (i * 3 + 2) + 3; k++) {
					printf("%2d x %2d = %2d", k, j, k * j);
			}
			printf("\n");
		}
		printf("-----------------------------------------------\n");
	}
}
