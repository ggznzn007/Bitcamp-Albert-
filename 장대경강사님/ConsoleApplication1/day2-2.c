#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printBits(int n){
	for (int b = 31; b >= 0; --b) {
		// ����ŷ :  Ư�� ��Ʈ�� ���¸� �ľ�, 0 !0
		if (n & (1 << b)) {// b�� ��Ʈ�� ���� 1�̸�
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");
}
/*
	�ߺ����� 3�ڸ� ������ 10�� �̻� ����Ͻÿ�
	- ������ ����� ���� �ִ°��� ���� ���� ǥ�� ���(2����)
*/
int main(void) {
	// ���� ���� : 10���� ����, �� �ڸ� ���� ��ģ��...
	// 2���� �������� �� �ڸ� ���� ��� ���� ǥ���Ѵ�...
	int num = 0;
	int flag = 0;// ���¿� ����,,,,
	for (int i = 0; i < 10; ++i) {
		flag = 0;
		num = rand()%9+1;
		flag = flag | (1 << num);// �ذ� ��� . �ٽ�
		for (int k = 1; k < 3; ++k) {
			int d;
			do {// ������ �켱�ϰ�
				// ����� ����� ���� �ݺ� ���� ����
				d = rand() % 10;// 0 ~ 9 10�� 1�ڸ� ��
			} while ( flag & ( 1<<d) );
			num = num * 10 + d;
			// ��� ǥ��
			flag = flag | (1 << d);
		}
		printf("%d \n", num);
	}


	return 0;
}

int main_03(void) {
	unsigned int n = 0xA5; //2�������� �� �� ����
	printBits(n);// ������ -> 2������ ����ϴ� �Լ�

	// n ������ [2]�� ��Ʈ�� 0 ���� ���弼��
	unsigned int a = (1 << 2);
	unsigned int c = ~(1 << 2);// [2]���� ������ �������� 1
	n = n & c;// c������ 1�� ��Ʈ �ڸ��� ��� n �� ���� �״��
	printBits(n);

	return 0;
}
