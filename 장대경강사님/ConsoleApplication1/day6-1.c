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
	// ���ڿ��� ������ ���� ����ϱ�
	char aStr[80] = "korea 2020";
	char* pStr;
	// = ������ ���� ������ �ڷ��� ��ġ��Ű��
	pStr = aStr;// [0]����� �ּ� char*
	pStr = &aStr[0]; // char �� ������ �ּ�
	// �����ͺ����� �迭�� ���� ����ϼ���
	pStr[0] = 'A';// aStr[0]
	pStr[1] = 'B';// aStr[1]

	printf("%s \n", aStr);// ���ڿ� ���

	char (*pp)[80];// �迭������ ����
	pp = &aStr;// �迭�� �ּ�
	printf("%s \n", (*pp)); // aStr
	printf("%s \n", pp[0]); // aStr
	printf("%s \n", 0[pp]); // aStr
//	printf(" %d \n", pp + 1);
	// �ּ� + ( 1 * sizeof(*�ּ�) )

	return 0;
}
int op4pointer() {
	// �迭 ��ҹ�ȣ�� ������ ������ ����
	char str[80] = { 'k','o','r','e','a','\n' };
	char* p = &str[0]; // str
	printf(" %p - %c \n", str +0, *(str+0));// �ּ�+���� == �ּ�
	printf(" %p - %c \n", p + 1, *(p + 1));// �ּ�+���� == �ּ�
	printf(" %p - %c \n", p + 2, *(p + 2));// �ּ�+���� == �ּ�
	printf(" %p - %c \n", p + 3, *(p + 3));// �ּ�+���� == �ּ�
	printf(" %p - %c \n", p + 4, *(p + 4));// �ּ�+���� == �ּ�

	printf(" %p - %c \n", &str[0], str[0]);
	printf(" %p - %c \n", &str[1], str[1]);
	printf(" %p - %c \n", &str[2], str[2]);
	printf(" %p - %c \n", &str[3], str[3]);
	printf(" %p - %c \n", &str[4], str[4]);
	return 0;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {

//	string_def();// ���. ���ڿ��� ���� �ִ�....
//	string_input();// �Է�. ���ڿ��� ���� �������� ??
//	ptr4string();// ���ڿ��� �ּҷ� �ٷ��...
//	string2pointer();// ���ڿ��� �����ͺ���
//	op4pointer();

	return 0;
}
// end program

/*
	���ڿ� : '\0' �� ������ �ϴ� ���� �迭
	���ڿ� ó���� ���� ������
	�����Ҵ� : �����͸� �̿��Ͽ� ���� �� �޸��� ������ ���� ����
		�迭, ����ü, ����ü �迭
*/
