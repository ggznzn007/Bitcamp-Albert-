/*
// 1. ������ ����?
// 1-1. ���α׷��� ���ؼ� �ʿ��� �ܾ�, ����
// 1-2. �ڷ���, �Լ�
// 2. ��� ������ ����, ������ ���� �ۼ�
// �ݺ� ���� 
// �������� ���϶�(���α׷�, ������Ʈ ��)
// ������ �ʿ��� �Լ����� �����ϰ� �̿��ؼ� �ϼ�


// �������� �л� ������ �Է��ϰ� ����ϴ� ���α׷�
// �л� ���� ���� ���α׷� // ����? User? // ���(funtion) ����
// ������? what? want? needs?
// ���� �Է�, ��� (input, output) ����� ��� (����,���ɾ�) �Ѵ�
// ���� = ������ � �ڷ������� ǥ���ϴ���(����,�Ǽ�) int  
// ����(0~100) scanf(), printf() �Լ��� ã�ƶ�
// - �Լ� ��� �� ��ȯ, ������ �ľ��ϱ� = ���밡��
// ������ ǥ���� ��� �� ���ΰ�?  ������? 

// �ڵ� : ù ��° ����Ǵ°� �����ΰ�?
*/

/*
int main(void) {
	// ��Ģ�� ������ �Ӹ��� �ܼ�������
	// ���� ���鶧�� �ִ��� �Ӹ� ���
	// �� : �����ڸ� ����� ���� : ���, ����, ����
	// 100�� ����ϰ� �;�// ���ϴ� ���� ���� ���� �ϴ� �־��
	// ���� 1���� ȭ�鿡 ����ϰ� ���� �� - ���� ������ ���ƶ�
	int n = 100;
	printf("        %d\n", n);// LNK �̸��� ã�� �� ���ٸ�? header ���� ã��
	printf("\n");
	printf("        %d\n", n);// ���� ����� ���ٸ� �Լ��� ��ü�� �ٲ��
	char ch = 'A';
	printf("%s", &ch);//��, ���ڿ��� �����ּ�
	// ������ ���ڴ� �ι��ڿ��� �Ѵ�// �Լ��� ã�Ƽ� ���θ� �غ���

	return 0;
}
*/

#include <stdio.h>


int step01() {
	// ���� : ����(int)
	int score = 0;
	printf("score >");
	scanf_s("%d", &score); // �Է¹޾ƶ�,�����Ѵ� &�ٿ��� ~�� 
	// ������ ���� �ٸ� �Լ��� �����ϰ� �Ϸ��� ���� �ּҸ� �ش�

	printf("�Է¹��� ���� :  %d \n", score);
	// ������ ���� ����
	return 0;
}

int step02() {
	// ���� 1��, 3���� : �� �� ��
	// �������� 1���� ���� ������ �� �ִ�
	int k, e, m;// ���� ������ ��� ��, ������ ���� �ǹ� �����϶�(�뵵)

	// scanf, printf �ѹ� ���� �� ���� �� ����� �Լ�
	printf("���� ���� ���� ���� ������ �Է� > ");
	scanf_s("%d %d %d", &k, &e, &m);	// ���� �߿�

	printf("%d %d %d \n", k, e, m);	
	return 0;
}

int step03() {
	// �л� 5��, �� �л����� ��,��,�� ������ ������
	// �� 15���� ������
	// �������� �����͸� ó���ϴ� ���α׷� ����� ����
	// 1�� 5��, 12��, 3�г�, ���� �� �б� 5��, �� 6���� �� ����
	int k1, e1, m1; // ������ �����ϴ� ������ ��������.
	int k2, e2, m2; // �ټ��� ������ �ٷ�°� �ʿ��Ѵ�
	// �ڷᱸ�� : �ټ��� ������ �ٷ�� ���
	int score[15] = { 0 }; //�迭 ���(����) �� 0~ ��ȣ == ��ҹ�ȣ
	// ù��° �л��� 3���� ������ ������
	score[0];
	score[1];
	score[2];
	// �ι�° �л��� 3���� ����
	score[3];
	score[4];
	score[5];
	// ����° �л��� 3���� ����
	score[6];
	score[7];
	score[8];
	// �׹�° �л��� 3���� ����
	score[9];
	score[10];
	score[11];
	// �ټ���° �л��� 3���� ����
	score[12];
	score[13];
	score[14];

	printf("ù��° ���� > ");
	scanf_s("%d %d %d", &score[0], &score[1], &score[2]);
	printf("ù��° ���� > ");
	scanf_s("%d %d %d", &score[3], &score[4], &score[5]);
	printf("ù��° ���� > ");
	scanf_s("%d %d %d", &score[6], &score[7], &score[8]);
	printf("ù��° ���� > ");
	scanf_s("%d %d %d", &score[9], &score[10], &score[11]);
	printf("ù��° ���� > ");
	scanf_s("%d %d %d", &score[12], &score[13], &score[14]);

	printf("%d %d %d\n", &score[0], &score[1], &score[2]);
	printf("%d %d %d\n", &score[3], &score[4], &score[5]);
	printf("%d %d %d\n", &score[6], &score[7], &score[8]);
	printf("%d %d %d\n", &score[9], &score[10], &score[11]);
	printf("%d %d %d\n", &score[12], &score[13], &score[14]);

	
	return 0;
}

int step04() {
	// �� 15���� �л��� ������ ��� �Է�,����,����� ��
	// �������� ������ �������� ���� ��� Ȱ��
	// �迭�� for�� �ѽ����� 
	int score[15] = { 0 };

	for (int i = 0; i < 15; ++i) {
		int v;
		scanf_s("%d", &v);
		score[i] = v; // Ű���� �Է°� 

	}
	// 1~25 ���� 5�� 5��
	for (int i = 0; i < 15; ++i) {
		printf("%d", score[i]);
		

	}
	return 0;
}


int step05() {
	// 5 * 3 == 15�� �������� ����� ����
	// ���, �߰��� ���(��,���)
	// ���� : �л��� ������ ���� ����� �ʿ� - ����� ���忡�� �ʿ�
	int score[5 * 3] = { 0 };// 5�� 3�� [5] [3]

	for (int i = 0; i < 13; i+=3) {
		printf("[0]�� �л��� ���� >"); // �л� ���� ���
		scanf_s("%d %d %d",
			&score[i + 0], &score[i + 1], &score[i + 2]); // 3���� 
			
	}
	// �Է��� ����� ���� ����ϼ���
	int no = 1;
	for (int i = 0; i < 13; i += 3) {
		printf("[%d]�� �л��� ���� >",no); // �л� ���� ���
		no++;// no+=1 1�� �����ȴ� �׸��� ��𿡼� ����Ǵ���
		printf("%d %d %d\n",
			&score[i + 0], &score[i + 1], &score[i + 2]); // 3���� 
		
}
	return 0;
}

/*
�л� ���� ����� ���α׷� ����(�����н�)
�� �ܰ躰�� ���� �����غ���
*/



int main(void) {
	step05();

	return 0;
}