// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////

int main(void) {
	// ���� �迭 ������ ����// ���� �迭�� ����ϴ� ���� !!
	int nums[10];// ���� �� ���̸� ������ ����� �� ����
	int len = 10;
	int* p = (int*)malloc(len * 4);// ���� �迭�� ���� ���氡��

	// ���̸� �߰��� �Ұ�
	// �����迭�� ���� ���̷ν� ���氡��
	len += 12;
	p = (int*)realloc(p, len * 4);// ���Ҵ��ϴ� �Լ�// �����Ҵ����� ������ �͸� ��밡��



	return 0;

}

	



struct _std {
	char name[60];
	int kor ;
	int eng ;
	int mat ;
};



int main_02(void) {
	// �����Ҵ� : �����ͺ���, �Լ� - �ᱹ �迭
	int length = 60; // int length = sizeof(p); // ���� ���� �������� ��
	char* p = (char*)malloc(60* sizeof(char)/*��üũ��*/);// �����Ҵ� �Լ�
	char arr[60];
	// == p[0] ~ p[59] �迭�� ���� ��
	for (int i = 0; i < length; ++i) {
		p[i] = 'a' + i; // �迭
	
	}
	// �����Ҵ����� ������ ����, �迭�� �ݵ�� �����Ѵ�.
	if (p != NULL) {
		free(p); // �Ҵ���� �ּҸ� �ٽ� ��� �ؼ� 
				// p�� �����ϸ� �ȵ� (�ּҸ� ����) �ٲ�� ����// ������ �����ð������ɸ�.
		p = NULL;
	}
	return 0;
}



// start program //////////////////////////////////////////
int main_01(int argc, char** argv) {
	// �迭 �ɰ���	: ũ�Ⱑ �ٸ� �������� ������ ó��
	char student[80];
	char* name = student;
	int* kor = student + 60;
	int* eng = student + 64;
	int* mat = student + 68;
	int* score = (int*)(student + 60);// == &student[60]
	// �����ͺ����� ����� ������ �ڷ����� ���� �����Ѵ�

	scanf_s("%s", name, 60);// ����Ʈ ���� ũ�� 4����Ʈ
	scanf_s("%d %d %d", score + 0, score + 1, score + 2);
	printf("%s : { %d, %d, %d} \n",
		name, *kor, *eng, *mat);
	



	return 0;
}



// end program