#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


int main(void){
	int W = 19;
	int H = 19;
	int omokpan[19 * 19] = { 1,0,1,1,0 };
	// ����� ���� 0 �̸� ��

	for (int r = 0; r < H; ++r) {
		for (int c = 0; c < W; ++c) {
			// ���� ���� �б� ó���� �� �ִ�
			int v = omokpan[r * W + c];
			if (v == 0) {
				printf("�� ");
			}
			else if (v == 1) {
				printf("��");
			}
			//printf("\n");
		}
		return 0;
	}
	
 }


int main_01(void) {
	int shape[40] = { 1 };
	int cur = 0;
	while (1) {
		system("cls"); // ������ ��� : ȭ�� �����
		for (int i = 0; i < 40; ++i) {
			//����� ���� ���� ����� ���ڿ��� �ٸ���
			printf("%s", (shape[i])?"��  ":"   ");// ���ǿ����� - ��� ��ġ���� ���԰���
			
		}
		printf("\n");
		// 1�� ��ĭ�� ���������� �ű��
		cur++;
		shape[cur-1] = 1;
		shape[cur] = 1;
		cur %= 40;// 0 ~ 39 ���� ����
	}
	return 0;
}