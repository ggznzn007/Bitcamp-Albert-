#include <stdio.h>

/*
		���� �� ���
*/

int main(void) {
	// ������ ũ�� �迭�� ������ ����ó�� ����ϴ� ���(�˰���)
	// 2 �� �̻��� ������� ������ �����ϴ� ��� 
	// ��� ��ȣ�� �����ϴ� ���̵� �ٽ� - ���� ť
	// ���� : ��������, ���Լ��� LIFO 
	int score[10] = { 0 };
	int sp = -1;// ������ ��ҿ� ���� ǥ���� �ǵ��� ������
	//�߰��ϱ�
	++sp;
	score[sp] = 1;
	// ������ ��Ҹ� ������
	int value = score[sp];
	--sp;
	return 0;
}





int main_05(void) {
	// ���� �迭 - �߰�
	// �߰� �� �ʱⰪ�� ���� ���� ������ �ٸ��� ��ȣ ������ �Ǵ��ϴ� ������ �ٸ���
	int score[10] = { 0 };
	int last = 0; // ������ �߰��� ��ҹ�ȣ
	score[last] = 1;// ó������ ������ ������ �� ���� 1�� ������ ����
	++last;
	score[last] = 2;// ó������ ������ ������ �� ���� 2�� ������ ����
	++last;
	score[last] = 3;// ó������ ������ ������ �� ���� 3�� ������ ����
	++last;
	// ��� �� �߰��� ����(������) ����϶�
	for (int i = 0; i < last; ++i) {
		printf("[%d] %d\n", i, score[i]);
	}

	if (last < 10 ) {// ���� ������ �߰� 
		score[last] = 3;
		++last;
	}
	else {
		printf("full\n");
	}

	return 0;
}





int main_04(void) {
	// ���� �迭 - �߰�
	int score[10] = { 0 };
	int last = -1; // ������ �߰��� ��ҹ�ȣ
	++last;
	score[last] = 1;// ó������ ������ ������ �� ���� 1�� ������ ����
	++last;
	score[last] = 2;// ó������ ������ ������ �� ���� 2�� ������ ����
	++last;
	score[last] = 3;// ó������ ������ ������ �� ���� 3�� ������ ����
	// ��� �� �߰��� ����(������) ����϶�
	for (int i = 0; i <= last; ++i) {
		printf("[%d] %d\n", i, score[i]);
	}

	if (last < 10-1) {// ���� ������ �߰� 
		++last;
		score[last] = 3;
	}
	else {
		printf("full\n");
	}

	return 0;
}




int main_03(void) {
	// ���� �迭
	int maxlength = 10;// �ִ밪 ���ϱ�
	int d2[2][5]; // ���ȣ * ����� + ����ȣ = 1�� �迭 Ȱ���Ͽ� = 2���迭�� ���� ȿ��
	// 5���� 2���� �迭�� �ִٴ� ���� = [2][5] // row * length of row + col = [row��] [col��]
	int score[2 * 5] = { 0 }; // 10�� ¥�� �迭�� ����� ��// {0} �ʱ�ȭ�� �迭 ����
	int index = 1*5 +2;
	score[7] = 1;
	printf("%d \n", score[index]);
	printf("%d \n", score[7]);

	return 0;
}


int main_02(void) {
	int score[] = { 1,2,3,4,5,6,7,8,9, };// ������ ���� - ������ �ʾƵ� �˾ƿ�
	int length = sizeof(score)/sizeof(score[0]);// �迭�� ���̸� ������ ���� ���� �� ��

	printf("%d \n", score);// �迭�� �����ּ�, [0]�� ����� �ּ�

	// sizeof() ���� - �޸� �������� ũ�� ����  = byte
	printf("size of array : %d \n", sizeof(score));// �迭��
	printf("size of element : %d \n", sizeof(score[0]));//��Ҹ�

	printf("long %d \n", sizeof(long));
	printf("long  int %d \n", sizeof(long int));
	printf("long long %d \n", sizeof(long long));


	return 0;
}

int main_01(void) {
	//�迭 ����, ���� - �ڷ��� ���� ��, �ִ� ���� ����(����)�� ����
	int arr[10]; // ����!!! [] �ϳ� �� ���� 1�� �迭 - ���� 
	char string[80]; // ���� �迭 -> ���ڿ� = ĳ���� �迭(�ܼ� �� �ϳ��� 80, �⺻)
	
	int length = 10;// �迭�� ����(length)�� ���� , ������̿� �ִ� ���� �׻� ��
	int curlength = 0;// �迭�� ������̸� ����  (�ִ� ���̸� ���)

	int index = 0;// �迭 ��ҹ�ȣ : �� ����� �Ϸ� ��ȣ (index)
	// �迭�� : arr - [0]�� ����� �ּҸ� �ǹ� = �ϱ� !!!
	// ��Ҹ� : �迭��[��ȣ]
	// ��Ұ� �迭�� ��� - 2��(����) �迭
	// ��Ҹ� == �迭�� 
	//arr �迭�� i�� ���
	// ó����� - �ݺ��� ��� 



	for (int i = 0; i < length; ++i) {
		arr[i] = (i + 1);// ��� ��ҿ� ���� ���� ����
	}
	for (int i = 0; i < length; ++i) {
		printf("%d,", arr[i]);// ��� ���� ���
	}

	return 0;
}