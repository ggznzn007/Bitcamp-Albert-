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
	char ch;
	int i = 0; // ���� ������ ����, Ȯ��ó��
	while (( ch = getchar() ) != '\n' ) {
		if (i == 0) {
			if ('a'<=ch&&ch<='z') {// �ҹ����̸�....
				ch -= 32;// �빮�ڷ� �ٲ۴�...
			}
		}
		str[i] = ch;
		++i;
	}
	// �ݵ�� �ι��ڷ� �������Ѵ�....
	str[i] = 0;//'\0'

//	gets_s(str, sizeof(str));
//	fgets(str, 80, stdin);
	printf("%s \n", str);

	while (0) {
		int v = scanf_s("%s", str, sizeof(str)); // &������ : �ܾ�� ������ �޴´�...
		if (v == 0) { break; }
		// _s �Լ����� �ּҿ� ũ�� �����ؾ� �Ѵ�....
//		fputs(str, stdout/*where*/);
//		fputs("\n", stdout);
		puts(str);
	}// �ݺ��� ���� ��Ű���� �����ؾ��մϱ�?


	return 0;
}
int ptr4string() {
	char* p; // �����ͺ��� - char �� ������ �ּ�
	// const : �������� �ʴ´�....
	const char* cp;	// ���ڰ��� �������� ����. �ּҴ� ���� ����

	p = "korea 2020";// ���ڿ��� �����ּҸ� �����ϴ� p
	*p = 'K'; // p �� ����Ű�� ���� ���� ����
	// " " ���ڿ� ����� ������ �� ����....

//	char* const ccp;
//	ccp = 1004;
//	*ccp = 'A';
	//	const char* const ccp;

	return 0;
}

int string2pointer() {

	return 0;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {

//	string_def();// ���ڿ��� ���� �ִ�....
//	string_input();// ���ڿ��� ���� �������� ??
//	ptr4string();// ���ڿ��� �ּҷ� �ٷ��...
	string2pointer();

	return 0;
}
// end program

/*
	���ڿ� : '\0' �� ������ �ϴ� ���� �迭
	���ڿ� ó���� ���� ������
	�����Ҵ� : �����͸� �̿��Ͽ� ���� �� �޸��� ������ ���� ����
		�迭, ����ü, ����ü �迭
*/
