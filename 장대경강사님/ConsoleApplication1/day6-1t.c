// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
int string_def() {
	// ���ڿ� - ���� �迭 - char []
	// �迭�� - �ּ�(&[0])
	// ���ڿ��� ó���� ù ���ڷκ��� '\0' ���� - ���� ����
	char str[80] = { "korea 2020 fi" };
	// ���ڿ� ��� "%s", char *, for
	printf("%s \n", str);// �迭�� [0]���������� �ι��� ������ 
	int v = puts(str);// &[0]
	printf(" v : %d \n", v);

	for (int i = 0; str[i] != '\0'; ++i) {
		// ȭ�鿡 1 ���� ���
		putchar(str[i]);
	}
	putchar('\n');

//	fputs();
	return 0;
}
int string_input() {
	// ���ڿ��� �����Ϸ��� char [] �ʿ�
	char str[80] = { 0 };
	// Ű����
	int v = scanf_s("%s", str, sizeof(str)); // &������ : �ܾ�� ������ �޴´�...
	printf("v : %d \n", v);
	// _s �Լ����� �ּҿ� ũ�� �����ؾ� �Ѵ�....
	fputs(str, stdout/*where*/); 

	v = scanf_s("%s", str, sizeof(str)); // &������ : �ܾ�� ������ �޴´�...
	printf("v : %d \n", v);
	// _s �Լ����� �ּҿ� ũ�� �����ؾ� �Ѵ�....
	fputs(str, stdout/*where*/);

	return 0;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {

//	string_def();// ���ڿ��� ���� �ִ�....
	string_input();

	return 0;
}
// end program

/*
	���ڿ� : '\0' �� ������ �ϴ� ���� �迭
	���ڿ� ó���� ���� ������
	�����Ҵ� : �����͸� �̿��Ͽ� ���� �� �޸��� ������ ���� ����
		�迭, ����ü, ����ü �迭
*/
