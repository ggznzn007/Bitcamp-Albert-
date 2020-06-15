// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
int string_def() {
	// 문자열 - 문자 배열 - char []
	// 배열명 - 주소(&[0])
	// 문자열의 처리는 첫 글자로부터 '\0' 까지 - 가변 길이
	char str[80] = { "korea 2020 fi" };
	// 문자열 출력 "%s", char *, for
	printf("%s \n", str);// 배열명 [0]번에서부터 널문자 전까지 
	int v = puts(str);// &[0]
	printf(" v : %d \n", v);

	for (int i = 0; str[i] != '\0'; ++i) {
		// 화면에 1 글자 출력
		putchar(str[i]);
	}
	putchar('\n');

//	fputs();
	return 0;
}
int string_input() {
	// 문자열을 저장하려면 char [] 필요
	char str[80] = { 0 };
	// 키보드
	char ch;
	int i = 0; // 글자 단위로 변경, 확인처리
	while (( ch = getchar() ) != '\n' ) {
		if (i == 0) {
			if ('a'<=ch&&ch<='z') {// 소문자이면....
				ch -= 32;// 대문자로 바꾼다...
			}
		}
		str[i] = ch;
		++i;
	}
	// 반드시 널문자로 끝나야한다....
	str[i] = 0;//'\0'

//	gets_s(str, sizeof(str));
//	fgets(str, 80, stdin);
	printf("%s \n", str);

	while (0) {
		int v = scanf_s("%s", str, sizeof(str)); // &변수명 : 단어로 나누어 받는다...
		if (v == 0) { break; }
		// _s 함수들은 주소와 크기 전달해야 한다....
//		fputs(str, stdout/*where*/);
//		fputs("\n", stdout);
		puts(str);
	}// 반복을 종료 시키려면 어찌해야합니까?


	return 0;
}
int ptr4string() {
	char* p; // 포인터변수 - char 형 변수의 주소
	// const : 변경하지 않는다....
	const char* cp;	// 문자값을 변경하지 않음. 주소는 변경 가능

	p = "korea 2020";// 문자열의 시작주소를 저장하는 p
	*p = 'K'; // p 가 가리키는 곳에 값을 저장
	// " " 문자열 상수는 변경할 수 없다....

//	char* const ccp;
//	ccp = 1004;
//	*ccp = 'A';
	//	const char* const ccp;

	return 0;
}

int string2pointer() {
	// 문자열과 포인터 같이 사용하기
	char aStr[80] = "korea 2020";
	char* pStr;
	// = 연산의 왼쪽 오른쪽 자료형 일치시키기
	pStr = aStr;// [0]요소의 주소 char*
	pStr = &aStr[0]; // char 형 변수의 주소
	// 포인터변수를 배열명 생각 사용하세요
	pStr[0] = 'A';// aStr[0]
	pStr[1] = 'B';// aStr[1]

	printf("%s \n", aStr);// 문자열 출력

	char (*pp)[80];// 배열포인터 변수
	pp = &aStr;// 배열의 주소
	printf("%s \n", (*pp)); // aStr
	printf("%s \n", pp[0]); // aStr
	printf("%s \n", 0[pp]); // aStr
//	printf(" %d \n", pp + 1);
	// 주소 + ( 1 * sizeof(*주소) )

	return 0;
}
int op4pointer() {
	// 배열 요소번호와 포인터 연산의 관계
	char str[80] = { 'k','o','r','e','a','\n' };
	char* p = &str[0]; // str
	printf(" %p - %c \n", str +0, *(str+0));// 주소+정수 == 주소
	printf(" %p - %c \n", p + 1, *(p + 1));// 주소+정수 == 주소
	printf(" %p - %c \n", p + 2, *(p + 2));// 주소+정수 == 주소
	printf(" %p - %c \n", p + 3, *(p + 3));// 주소+정수 == 주소
	printf(" %p - %c \n", p + 4, *(p + 4));// 주소+정수 == 주소

	printf(" %p - %c \n", &str[0], str[0]);
	printf(" %p - %c \n", &str[1], str[1]);
	printf(" %p - %c \n", &str[2], str[2]);
	printf(" %p - %c \n", &str[3], str[3]);
	printf(" %p - %c \n", &str[4], str[4]);
	return 0;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {

//	string_def();// 출력. 문자열의 끝이 있다....
//	string_input();// 입력. 문자열의 끝이 무엇인지 ??
//	ptr4string();// 문자열은 주소로 다룬다...
//	string2pointer();// 문자열과 포인터변수
//	op4pointer();

	return 0;
}
// end program

/*
	문자열 : '\0' 을 끝으로 하는 문자 배열
	문자열 처리를 위한 포인터
	동적할당 : 포인터를 이용하여 실행 중 메모리의 생성과 삭제 관리
		배열, 구조체, 구조체 배열
*/
