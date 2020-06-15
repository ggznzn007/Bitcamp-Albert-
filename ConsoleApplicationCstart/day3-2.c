#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	// ���̰� 15�� ������ 1�� �迭 �����ϱ�
	int numbers[15] = { 0 };
	int length = 15;// sizeof(�迭��)/sizeof(int);
	// ���� �߻� ���ذ� ���� �� srand(); ���
	// ��� ��ҿ� ���� ������ �����ϱ�
	srand((unsigned int)time(NULL));// �ð��� ���ϱ� ������ �ð��� �����
	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = rand();// 0 ~ 32656 ���� ������ ǥ���ؼ� ���尡��

	}
	for (int i = 0; i < length; ++i) {
		printf("%6d", numbers[i]);

	}
	printf("\n");


	// �迭 ó�� �� �⺻ ���
	int min;
	int max;
	min = max = numbers[0]; // �迭 ��� �߿� �ϳ��� �ʱ�ȭ �ϴ� ��
	// ã�� : ��, ��ҹ�ȣ �� ��� ���� ã�� ������ Ȯ���� �� ��
	for (int i = 1; i < length; ++i) {
		if (min > numbers[i]) {// i ���� ���� min������ ����
			min = numbers[i];
		}
		if (max < numbers[i]) {// i ���� ���� max������ ����
			max = numbers[i];

		}
		printf("Max : %d, Min : %d \n", max, min);

		// ��ҹ�ȣ
		min = max = 0;
		for (int i = 1; i < length; ++i) {
			if (numbers[min] > numbers[i]) {// i ���� ���� min������ ����
				min = i;
			}
			if (numbers[max] < numbers[i]) {// i ���� ���� max������ ����
				max = i;
			}
		}
		printf("Max : %d, Min : %d \n", numbers[max], numbers[min]);

		// �迭 ��ҵ��� ũ�� ������� ���ġ - ���� sort
		// ���Ĺ�� - �˰��� �پ�
		// �� - ��ȯ 
		int first = 0; // ù ��° ��ҹ�ȣ
		int last = length - 1; // ������ ��ҹ�ȣ

		for(int k = 0; k < (length/2); ++k) {
			int min = first;
			int max = first;
			for (int i = first + 1; i <= last; ++i) {
				if (numbers[min] > numbers[i]) {
					min = i;
				}
				if (numbers[max] < numbers[i]) {
					max = i;
				}
			}
			//��ȯ
			int t = numbers[min];
			numbers[min] = numbers[first];
			numbers[first] = t;
			t = numbers[max];
			int t = numbers[max];
			numbers[max] = numbers[last];
			numbers[last] = t;
			



			printf("\n");
			++first;
			--last;
	}


	return 0;
}

	int main_01(void); {
	// ���̰� 15�� ������ 1�� �迭 �����ϱ�
	int numbers[15] = { 0 };
	int length = 15;// sizeof(�迭��)/sizeof(int);
	// ��� ��ҿ� ���� ������ �����ϱ�
	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = rand();// 0 ~ 32656 ���� ������ ǥ���ؼ� ���尡��

	}
	for (int i = 0; i<length; ++i) {
		printf("%6d",numbers[i]);

	}
	printf("\n");

	return 0;
}