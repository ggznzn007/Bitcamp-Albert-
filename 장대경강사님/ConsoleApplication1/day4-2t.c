
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int drawLine(int x);

int main(void) {
	int y, x;
	int a, b;

	a = -1;
	b = 19;
	for (x = 0; x < 20; ++x) {
		y = (a * x) + b;
		system("cls");// ��� ���� ȭ�� �����
		for (int r = 0; r < 20; ++r) {
			for (int c = 0; c < 20; ++c) {
				(r == y && c == x) ?
					printf("��") : printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}

int main_01(int argc, char* argv[]) {
	int a = 1;
	int b = -5;// y�� �̵�
	int x = 0;
	int y = (a * x) + b;// �������� ����(��)
	y = 5;	// ����
	x = 5;	// ������
	for (x = 0; x < 10; ++x) {// 0 ~ 9 -> y
		y = (a * x) + b;// �������� ����(��)
		printf("{%d,%d}\n", x, y);
	}
	
	return 0;
}

int drawLine(int x) {
	// ȭ�� ���� �׸��� ���α׷� ����
	int y;
//	int x = 5;
	// ��, �� ǥ�� �� �ݺ��� 2�� ���ļ� ����� �ڵ�
	y = (1 * x) + 5;
	for (int r = 0; r < 10; ++r) {
		printf("[%2d]", r);
		for (int c = 0; c < 10; ++c) {
			// �� ��ġ(r,c)
			if (r == y && c == x) {
				printf("##");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}

	return 0;
}