// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
char* toString() {
	// ���������� �Լ� ���� �� �������
	// �����Ҵ� - ���� �����Ǿ �Լ��ʹ� ���� ���� ����
	char *name = (char*)malloc(80);
	// ���ڿ��� ����(����)
	//name = "jang"; // �迭���� ��� - ���Կ��� �Ұ�
	strncpy(name, "jangs ma", 80);// ���ڿ� �������� �Լ�//���ڿ� ���� ����
	
	return name;
}

int getString(char* param, int size) {
	int i;
	for (int i = 0; i < size-1 ; ++i) {
		param[i] = '0' + i;
	}
	param[i] = 0;
	return 0;
}


// start program //////////////////////////////////////////
int main(int argc, char** argv) {
	// ���ڿ��� �� ���� �־ ��ȯ ó�� ����
	// �� �ܿ��� �迭�� ��ȯ�ϴ� ó�� ���� �ʴ´�
	char *p = toString();
	if (p == NULL) {// �� Ȯ���ϱ�
		printf("���ڿ��� ����\n");
	}
	else {
		printf("%s \n",p);
		free(p);// ����� ������ ������ �����Ѵ�
	}

	char name[80];
	getString(name, 80);// �迭��, ���̰�
	printf("%s \n", name);

	return 0;
}

//���ڿ��� �⺻ ���Ǹ� ���
//NULL�� ���
//�ᱹ ���ڿ��� �迭�̴�


//1. "{'name':'jangs', 'type':10}";  str
//  ��ǥ������ ��� ���ڿ� ����
//2. ���� ���峻���� : ������ ������ ����

// ���� ��     �� ���� ���α׷� EOF(ctal + z)
// ������ ��
// �ܾ� �� 



// end program