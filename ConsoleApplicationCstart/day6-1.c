// library headers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables



// section function body

int string_def() {
	//���ڿ� - ���� �迭 - char[] ���ڿ��� �����ϱ� ���Ѱ��� �迭���� ���!!!
	//�迭�� - �ּ�(&[0])
	//���ڿ��� ó���� ù ���ڷ� ���� '\0'== null ���� - ���� ����(�迭 ���̸� �ʰ��Ҽ�����)
	// '\0' �ڷδ� ��µ��� ���� ****
	// NUL ����// NULL ������ == ���� 0 == false
	char str[80] = { 0 };// ���ڿ��� �ʿ�� ������ char �迭�� ��ƶ�
	//char str[80] = { "korea 2\0 20" };// ���ڿ� �迭 ����// �ܾ� �ϳ��ϳ� �迭�� ��
	//���ڿ� ��� "%s", char*, for 
	printf("%s \n", str); //("%s \n", str) �迭���� ǥ���ϸ� �ȴ� [0]���������� �� ���� ������ ���

	int v= ("%s", str, sizeof(str));// &[0] char �ּҸ� �ּ���
	printf("v:%d\n", v); // puts ���� ���� ª�Ƽ� 

	for (int i = 0; str[i] != '\0'; ++i) { // �ι��ڱ��� 1���ھ� ��� �϶�
		putchar(str[i]);

	}
	putchar('\n');

//	fputs() - f �� ������ �ǹ� printf�� f�� ������ �ǹ� 
}

int string_input() {
	// ���ڿ��� �����Ϸ��� char [] �ʿ�
	char str[80] = { 0 };
	scanf_s("%s", str, sizeof(str));// &������ - �迭���� & ������ �ʴ´�
	//_s �Լ����� �ּҿ� ũ���� �����ؾ��Ѵ� //  &������ : �ܾ�� ������ �޴´�
					//  Ű���� �Է�
	fputs(str, stdout/*where��𿡼�,����*/);
	return 0;
}





//start program

int main(int argc, char** argv) {

	string_def();
	strinf_input();

	return 0;
}


/*
���ڿ� : '\0' �� ������ �ϴ� ���� �迭
���ڿ� ó���� ���� ������
�����Ҵ� : �����͸� �̿��Ͽ� ���� �� �޸��� ������ ���� ���� �迭, ����ü, ����ü �迭
*/