// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
char* toString() {
	// ���������� �Լ� ���� �� �������...
	// �����Ҵ� - ���� �����Ǿ �Լ��ʹ� ���� ���� ����
	char *name = (char*)malloc(80);
	// ���ڿ��� ����(����)
	//name = "jangs ma";// �迭���� �����... ���Կ��� �Ұ�
	strncpy(name, "jangs ma", 80);// ���ڿ� ���� ��
	return name;
}
int getString(char *param, int size) {
	int i;
	for (i = 0; i < size-1 ; ++i) {
		param[i] = '0' + i;
	}
	param[i-1] = 0;
	return 0;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {
	// ���ڿ��� �� ���� �־ ��ȯ ó�� ����
	//	 �� �ܿ��� �迭�� ��ȯ�ϴ� ó�� ���� �ʴ´�...
	char * p = toString();
	if (p == NULL) {// �� Ȯ���ϱ�....
		printf("���ڿ��� ����\n");
	}
	else {
		printf("%s \n", p);
		free(p);
	}
	
	char name[80];
	getString(name, 80);// �迭��, ����
	printf("%s \n", name);

	return 0;
}
// end program

