#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ���
	�ݺ� : for while do-while
	�б� : if(��) switch(���, ���)
*/
int main(void) {
	// 1 ~25���� ���� �������� ���
	// 5 * 5 ����ϴ� �� ���� ���
	// ǥ : 2�� ���� ǥ��
	int v = 1;
	for (int r = 0; r < 5; ++r) {
		for (int c = 0; c < 5; ++c) {
			printf("%d\t", v);
			v++;//�����ϴ� ���� ��
			if (v > 25) {
				// ���� ����
				exit(1);
			}
		}
		printf("\n");
	}

	int cnt = 0;
	for (int v = 1; v < 26; ++v) {
		printf("%d", v);
		cnt++;
		// �� �ϳ��� 5���� ����ϸ� ���� ������
		if (cnt == 5) {
			printf("\n");
			cnt = 0;
		}
		
	}
}
int main_01(void) {
	// 1 ~ 25 ���� �����ϴ� �������� ��� ���� ������ ��Ȯ�� �ؾ� ��
	//printf(""); ������� �ڵ带 ���̰ų� ������ ���� ����� ����
	int min = 100;// �Է�
	int max = 25;// �Է�
	// ����� ������ �ݴ�� �Է��ϴ� ���
	// ����(�Ǵ�) - �б⹮ 
	if (min > max) {
		// �� ������ ���� ��ȯ�Ѵ�/ ���� �ϳ��� ����ؼ� ���� �ΰ� ��ȯ��
		int temp = min;
		min = max;
		max = temp;
		// ��Ʈ������ XOR ���� Ȱ�� ���� 
	}

	for (int n = min ;n <= max; n = n++ )
	{
		printf("%d", n);
	}
	printf("\n");
	return 0;
}