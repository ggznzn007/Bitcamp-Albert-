// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
char* toString() {
	// 지역변수는 함수 종료 시 사라진다...
	// 동적할당 - 힙에 생성되어서 함수와는 관계 유지 가능
	char *name = (char*)malloc(80);
	// 문자열을 저장(대입)
	//name = "jangs ma";// 배열명은 상수다... 대입연산 불가
	strncpy(name, "jangs ma", 80);// 문자열 저장 시
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
	// 문자열은 그 끝이 있어서 반환 처리 가능
	//	 그 외에는 배열을 반환하는 처리 하지 않는다...
	char * p = toString();
	if (p == NULL) {// 널 확인하기....
		printf("문자열이 없다\n");
	}
	else {
		printf("%s \n", p);
		free(p);
	}
	
	char name[80];
	getString(name, 80);// 배열명, 길이
	printf("%s \n", name);

	return 0;
}
// end program

