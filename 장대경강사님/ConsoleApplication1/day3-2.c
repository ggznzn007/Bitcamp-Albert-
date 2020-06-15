#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


int run(void) {
	int on[15] = { 0 };
	srand((unsigned)time(NULL));
	for (int r = 0; r < 15; ++r) {
		on[r] = rand() % 40;
	}
	while (1) {
		system("cls");
		for (int r = 0; r < 15; ++r) {
			for (int c = 0; c < 40; ++c) {
				printf("%s", (c == on[r]) ? "��":"��" );
			}
			printf("\n");
		}
		for (int r = 0; r < 15; ++r) {
			on[r]++;
			on[r] %= 40;
		}

		if (_kbhit()) {
			if (_getch() == '\r') {
				break;
			}
		}
	}
	printf("terminated \n\n");
	return 0;
}
int shooters(void) {
	int first_line = 0;
	int last_line = 19;
	int width = 40;
	int p1[3];
	p1[0] = rand() % width;
	p1[1] = p1[0];
	p1[2] = first_line+1;

	int p2[3];
	p2[1] = p2[0] = rand() % width;
	p2[2] = last_line - 1;

	while (1) {
		system("cls");
		// first line
		for (int c = 0; c < width; ++c) {
			if (c == p1[0]) {
				printf("��");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");

		for (int r = first_line+1; r < last_line-1; ++r) {
			for (int c = 0; c < width; ++c) {
				if (p1[2] == r && p1[1] == c) {
					printf("��");
				}
				else if (p2[2] == r && p2[1] == c) {
					printf("��");
				}
				else {
					printf("  ");
				}
			}
			printf("\n");
		}
		// last line
		for (int c = 0; c < width; ++c) {
			if (c == p2[0]) {
				printf("��");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");

		p1[0] += rand()%3-1;
		if (p1[0] < 0) p1[0] = 0;
		if (p1[0] >= width) p1[0] = width-1;
		p1[2]++;
		if (p1[2] == last_line) {
			p1[2] = first_line + 1;
			p1[1] = p1[0];
		}

		p2[0] += rand() % 3 - 1;
		if (p2[0] < 0) p2[0] = 0;
		if (p2[0] >= width) p2[0] = width-1;
		p2[2]--;
		if (p2[2] == first_line) {
			p2[2] = last_line - 1;
			p2[1] = p2[0];
		}

		if (_kbhit()) {
			if (_getch() == '\r') {
				break;
			}
		}
	}
	printf("terminated \n\n");
	return 0;
}

int main(void) {
	int W = 19;
	int H = 19;
	int omokpan[ 19 * 19 ] = { 1,0,1,1,0 };
	// ����� ���� 0 �̸� �� +

	for (int r = 0; r < H; ++r) {
		for (int c = 0; c < W; ++c) {
			// ���� ���� �б� ó���� �� �ִ�...
			int v = omokpan[r * W + c];
			if ( v == 0) {
				printf("�� ");
			}
			else if ( v == 1) {
				printf("��");
			}
		}
		printf("\n");
	}

	return 0;
}

int main_02(void) {
	int shape[40] = { 1 };
	int cur = 1;
	while(1){
		system("cls");// ������ ���: ȭ�� �����
		for (int i = 0; i < 40; ++i) {
			// ����� ���� ���� ����� ���ڿ��� �ٸ���...
			printf("%s", (shape[i]) ?"@ " : "  ");
		}
		printf("\n");
		// 1�� �� ĭ�� ���������� �ű��....
		shape[cur-1] = 0;
		shape[cur] = 1;
		cur++;
		cur %= 40;// 0 ~ 39
	}

	return 0;
}
int main_01(void) {
	// ���� 15�� ������ 1�� �迭 �����ϱ�
	int numbers[15] = { 0 };
	int length = 15;// sizeof(�迭��)/sizeof(int);
	// ���� �߻� ���ذ� ����
	srand( (unsigned int)time(NULL));// �ð�
	// ��� ��ҿ� ���� ������ �����ϱ�
	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = rand();// 0 ~ 32656
	}
	for (int i = 0; i < length ; ++i) {
		printf("%6d", numbers[i]);
	}
	printf("\n");

	// �迭 ó�� �� �⺻ ���
	int min;
	int max;
	min = max = numbers[0];
	// ã�� : ��, ��ҹ�ȣ
	for (int i = 1; i < length; ++i) {
		if (min > numbers[i]) {
			min = numbers[i];
		}
		if (max < numbers[i]) {
			max = numbers[i];
		}
	}
	printf("Max : %d, Min : %d \n", max, min);
	// ��ҹ�ȣ
	min = max = 0;
	for (int i = 1; i < length; ++i) {
		if (numbers[min] > numbers[i]) {
			min = i;
		}
		if (numbers[max] < numbers[i]) {
			max = i;
		}
	}
	printf("Max : %d, Min : %d \n", numbers[max], numbers[min]);

	// �迭 ��ҵ��� ũ�� ������� ���ġ - ���� sort
	//	���� ��� - �˰���(�پ��ϴ�)
	//	�� - ��ȯ
	int first = 0; // ù ��° ��ҹ�ȣ
	int last = length - 1;// ������ ��ҹ�ȣ

	for (int k = 0; k < 8; ++k) {
		int min = first;
		int max = first;
		for (int i = first+1; i <= last; ++i) {
			if (numbers[min] > numbers[i]) {
				min = i;
			}
			if (numbers[max] < numbers[i]) {
				max = i;
			}
		}
		// ��ȯ
		int t = numbers[min];
		numbers[min] = numbers[first];
		numbers[first] = t;
		t = numbers[max];
		numbers[max] = numbers[last];
		numbers[last] = t;
		++first;
		--last;
	}
	// ���� �� ���
	for (int i = 0; i < length; ++i) {
		printf("%6d", numbers[i]);
	}
	printf("\n");


	return 0;
}
