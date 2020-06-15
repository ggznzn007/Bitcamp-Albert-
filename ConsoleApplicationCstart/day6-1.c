// library headers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables



// section function body

int string_def() {
	//문자열 - 문자 배열 - char[] 문자열을 저장하기 위한것이 배열임을 기억!!!
	//배열명 - 주소(&[0])
	//문자열의 처리는 첫 글자로 부터 '\0'== null 까지 - 가변 길이(배열 길이를 초과할수없음)
	// '\0' 뒤로는 출력되지 않음 ****
	// NUL 문자// NULL 포인터 == 값은 0 == false
	char str[80] = { 0 };// 문자열이 필요시 무조건 char 배열을 잡아라
	//char str[80] = { "korea 2\0 20" };// 문자열 배열 가능// 단어 하나하나 배열로 들어감
	//문자열 출력 "%s", char*, for 
	printf("%s \n", str); //("%s \n", str) 배열명을 표기하면 된다 [0]번에서부터 널 문자 전까지 출력

	int v= ("%s", str, sizeof(str));// &[0] char 주소를 주세요
	printf("v:%d\n", v); // puts 쓰는 이유 짧아서 

	for (int i = 0; str[i] != '\0'; ++i) { // 널문자까지 1글자씩 출력 하라
		putchar(str[i]);

	}
	putchar('\n');

//	fputs() - f 는 파일을 의미 printf의 f는 포맷의 의미 
}

int string_input() {
	// 문자열을 저장하려면 char [] 필요
	char str[80] = { 0 };
	scanf_s("%s", str, sizeof(str));// &변수명 - 배열명에는 & 붙이지 않는다
	//_s 함수들은 주소와 크리를 전달해야한다 //  &변수명 : 단어로 나누어 받는다
					//  키보드 입력
	fputs(str, stdout/*where어디에서,어디로*/);
	return 0;
}





//start program

int main(int argc, char** argv) {

	string_def();
	strinf_input();

	return 0;
}


/*
문자열 : '\0' 을 끝으로 하는 문자 배열
문자열 처리를 위한 포인터
동적할당 : 포인터를 이용하여 실행 중 메모리의 생성과 삭제 관리 배열, 구조체, 구조체 배열
*/