// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
char* toString() {
	// 지역변수는 함수 종료 시 사라진다
	// 동적할당 - 힙에 생성되어서 함수와는 관계 유지 가능
	char *name = (char*)malloc(80);
	// 문자열을 저장(대입)
	//name = "jang"; // 배열명은 상수 - 대입연산 불가
	strncpy(name, "jangs ma", 80);// 문자열 대입저장 함수//문자열 저장 포맷
	
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
	// 문자열은 그 끝이 있어서 반환 처리 가능
	// 그 외에는 배열을 반환하는 처리 하지 않는다
	char *p = toString();
	if (p == NULL) {// 널 확인하기
		printf("문자열이 없다\n");
	}
	else {
		printf("%s \n",p);
		free(p);// 사용이 끝나는 곳에서 해제한다
	}

	char name[80];
	getString(name, 80);// 배열명, 길이값
	printf("%s \n", name);

	return 0;
}

//문자열의 기본 정의를 기억
//NULL을 기억
//결국 문자열도 배열이다


//1. "{'name':'jangs', 'type':10}";  str
//  쉼표단위로 끊어서 문자열 저장
//2. 위의 저장내용을 : 단위로 나눠서 저장

// 숫자 수     수 세는 프로그램 EOF(ctal + z)
// 영문자 수
// 단어 수 



// end program