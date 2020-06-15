// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////

int string_array() {
	// ���ڿ� 3���� �Է¹޾� ����ϼ���
	char s1[80];
	char s2[80];
	char s3[80];
	printf("string > ");
	fgets(s1, sizeof(s1), stdin);
	printf("string > ");
	fgets(s2, sizeof(s2), stdin);
	printf("string > ");
	fgets(s3, sizeof(s3), stdin);

	fputs(s1, stdout);//f = file(file stream);
	fputs(s2, stdout);
	fputs(s3, stdout);

	return 0;
}

int string_loop() {
	// ���ڿ� 5���� �����ϴ� �迭
	//char list[���ڿ� ����][�� ���ڿ� ����];
	char list[5][80];
	for (int i = 0; i < 5; ++i) {
		printf("string >");
		fgets(list[i], 80, stdin);

	}
	for (int i = 0; i < 5; ++i) {
		fputs(list[i], stdin);
	}

	return 0;
}

int string_points() {
	// ������ �迭 : ������ �������� ������ ������ �ִ�
	char* pl[5];// pl�� �迭�� = �������� �ּ� = �������� ������ ����  == **
	for (int i = 0; i < 5; ++i) {
		printf("string >");
		pl[i] = (char*)malloc(80);// char[80] �迭(����)�� �ʿ��ؼ� ����
		fgets(pl[i], 80, stdin);

	}

	for (int i = 0; i < 5; ++i) {
		fputs(pl[i], stdin);
	}
	// �����Ҵ� ��� �� 
	for (int i = 0; i < 5; ++i) {
		free(pl[i]); // �Ҵ���� ��ŭ �����ؾ� �Ѵ�
	}

	return 0;
}

int string_dynamic() {
	char** ap = NULL;// �����͹迭 (����)
	int count;
	printf("���ڿ� �Է°��� : ");
	scanf_s("%d", &count);
	ap = (char**)malloc(count*sizeof(*ap));
	for (int i = 0; i < count; ++i) {
		printf("string >");
		ap[i] = (char*)malloc(80);
		fgets(ap[i], 80, stdin);		
	}
	for (int i = 0; i < count; ++i) {
		fputs(ap[i], stdout);
	}
	for (int i = 0; i < count; ++i) {
		free(ap[i]); // �Ҵ���� ��ŭ �����ؾ� �Ѵ�
	}
	free(ap);// ������� �����ؾ� �Ѵ�
	// ���α׷��� -> ����

	return 0;
}




// start program //////////////////////////////////////////
int main(int argc, char** argv) {
	//string_array();
	//string_loop();
	//string_points();
	string_dynamic();

	return 0;
}



// end program