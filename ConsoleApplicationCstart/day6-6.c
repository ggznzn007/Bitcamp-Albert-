#include <stdio.h>
#include <ctype.h>
// �Է¹޴� ���ڿ� �߿� ������ ���� ����
	// �Է¹޴� ���ڿ� �߿� �������� ���� ����
	// �Է¹޴� ���ڿ� �߿� �ܾ��� ���� ����
	// = if??? count??? �������� �������� �Ǻ�
	// ������ ���⿡ ���� �ܾ� �Ǻ�


int main(void) {//���� ����???

	char ch;
	int digit = 0;// ���� 
	int alpha = 0;// ������
	int words = 0;// ����
	int numbers = 0;// ����
	
	
	while ((ch = getchar()) != EOF) {
		if (ch >= '0' && ch <= '9') digit++;
		if (ch >= 'A' && ch <= 'z') alpha++;
		if (ch ==  ' ') words++;
	}
	printf("digit : %d\n", digit);
	printf("alpha : %d\n", alpha);
	printf("words : %d\n", words);
	
	// word �ܾ� ���� ���ĺ��� �������� ī���� �غ��� 
	
	return 0;

}