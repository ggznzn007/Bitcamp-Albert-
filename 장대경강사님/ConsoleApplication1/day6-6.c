

#include <stdio.h>

int main(void) {

	char ch;
	char prev;
	int digit = 0;// ����
	int alpha = 0;// ������ 
	int words = 0;// ����
	int numbers = 0;// �������� ����
	int n = 0;// �� �Է� ��
	while ( (ch = getchar() ) != EOF ) {
		// �Է¹��� ���ڿ�


		if (n > 0 && prev == ch) {
		}
		n++;
		prev = ch;
	}
	printf("\n");

	return 0;
}