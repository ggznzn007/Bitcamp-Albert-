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
	int v = scanf_s("%s", str, sizeof(str)); // &변수명 : 단어로 나누어 받는다...
	printf("v : %d \n", v);
	// _s 함수들은 주소와 크기 전달해야 한다....
	fputs(str, stdout/*where*/); 

	v = scanf_s("%s", str, sizeof(str)); // &변수명 : 단어로 나누어 받는다...
	printf("v : %d \n", v);
	// _s 함수들은 주소와 크기 전달해야 한다....
	fputs(str, stdout/*where*/);

	return 0;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {

//	string_def();// 문자열의 끝이 있다....
	string_input();

	return 0;
}
// end program

/*
	문자열 : '\0' 을 끝으로 하는 문자 배열
	문자열 처리를 위한 포인터
	동적할당 : 포인터를 이용하여 실행 중 메모리의 생성과 삭제 관리
		배열, 구조체, 구조체 배열
*/
