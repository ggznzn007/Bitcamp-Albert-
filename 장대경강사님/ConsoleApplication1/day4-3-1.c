#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
// ��ũ�� ��� : �̸��� �ִ� ���
#define ASIZE 5

// 2�� �迭 ����ϱ�
// step 2. 2���迭�� �����Ѵ�....
int display(int numbers[][ASIZE], int rows) {
	// ���̸� ��� ����
	// 1���迭 ���� ���� �ִ�... ���� 10�� 1�� �迭 5���� �ִ�...
	printf("\t");
	for (int i = 0; i < ASIZE; ++i) {
		printf("%d\t", i);
	}
	printf("\n");

	for (int row = 0; row < ASIZE; ++row) {
		// row�� ��, 1���迭
		printf("%d\t", row);
		for (int col = 0; col < ASIZE; ++col) {
			// col�� ��, ���� 10�� 
			printf("%d\t", numbers[row][col]);
		}
		printf("\n");
	}
	return 0;
}
int main(int argc, char** argv) {
	int pan[ASIZE][ASIZE] = { 0 };

	display(pan, ASIZE);// �迭��, ����

	return 0;
}
