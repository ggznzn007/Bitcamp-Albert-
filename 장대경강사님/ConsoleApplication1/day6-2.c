// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////

// section function body //////////////////////////////////



// start program //////////////////////////////////////////
int main(void) {
	// ���� �迭 ������ ����.... ���� �迭�� ����ϴ� ���� !!
	int nums[10];// ���� �� ���̸� ������ ����� �� ����..
	int len = 10;
	int* p = (int*)malloc(len * 4);// ���� �迭�� ���� ���� ����

	// ���̸� �߰�(�ø���)�� �Ұ�
	//	�����迭�� ���� ���̷ν� ������ ����
	len += 12;
	p = (int*)realloc(p, len * 4 );// �� �Լ��� �����Ҵ����� ������ �͸� ��� ����

	free(p);

	return 0;
}
int main_02(void) {
	// �����Ҵ� : �����ͺ���, �Լ� - �ᱹ �迭
	int length = 60;
	char* p = (char*)malloc( length * sizeof(char)/*��üũ��*/);// �����Ҵ� �Լ�
	char arr[60];
	// p[0] ~ p[59]
	for (int i = 0; i < length; ++i) {
		p[i] = 'a' + i;// �迭�̴�....
	}
	
//	p = p + 20;// �ּ� �����ϸ� �ȵ˴ϴ�.

	// �����Ҵ����� ������ ����, �迭 �� �ݵ�� �����Ѵ�...
	if (p != NULL) {
		free(p);// �̷��� �Ҵ���� �ּҸ� �ٽ� ��� �Ѵ�...
		// p �� �����ϸ� �ȵȴ�....
		p = NULL;
	}
	return 0;
}
int main_01(int argc, char** argv) {
	// �迭 �ɰ��� : ũ�Ⱑ �ٸ� ���� ���� ó��
	char student[80] = { 0 };
	char* name = student;
	int* kor = student + 60;
	int* eng = student + 64;
	int* math = student + 68;
	int* score = (int*)(student + 60);// &student[60]
	// �����ͺ����� ���� �� ������ �ڷ����� ���� �����Ѵ�...

	scanf_s("%s", name, 60);// �����ͺ����� ũ�� 4byte
	scanf_s("%d %d %d", score + 0, score + 1, score + 2);
	printf("%s : { %d, %d, %d} \n", 
		name, *kor, *eng, *math);

	return 0;
}
// end program

