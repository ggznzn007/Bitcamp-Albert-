#include <stdio.h>//ǥ�� ����� ó��
#include <stdlib.h>//���̺귯�� ó��
#include <string.h>//���ڿ� ó��
#include <conio.h>//���Ű ó�������ϰ� �ϴ� ��� ����

int drawLine(int x);

int main(int argc, char* argv[]) {
	drawLine(1);
	drawLine(2);
	drawLine(3);
	return 0;
}


int drawLine(int x) {
	int y;
//	int x = 5;
	y = (1 * x) + 5;
	for (int r = 0; r < 10; ++r) {
		printf("[%2d]", r);
		for (int c = 0; c < 10; ++c) {
			// �� ��ġ(r,c)
			if (r == y && c == x) {// x y ���� ���� �޶�����
				printf("�ڡ�");
			}
			else {
				printf(" ");
			}			
		}
		printf("\n");
	}
	return 0;
}