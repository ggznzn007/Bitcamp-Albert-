// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
int string_array() {
	// 문자열 3개를 입력받아 출력하세요
	char s1[80];
	char s2[80];
	char s3[80];
	printf("string > ");
	fgets(s1, sizeof(s1), stdin);
	printf("string > ");
	fgets(s2, sizeof(s2), stdin);
	printf("string > ");
	fgets(s3, sizeof(s3), stdin);

	fputs(s1, stdout);// file (, FILE stream);
	fputs(s2, stdout);
	fputs(s3, stdout);

	return 0;
}
int string_loop() {
	// 문자열 5개를 저장하는 배열
//	char list[문자열 개수][각 문자열 길이];
	char list[5][80];
	for (int i = 0; i < 5; ++i) {
		printf("string >");
		fgets(list[i], 80, stdin);
	}
	for (int i = 0; i < 5; ++i) {
		fputs(list[i], stdout);
	}

	return 0;
}
int string_points() {
	// 포인터 배열 : 포인터 변수들을 여러 가지고 있다...
	char* pl[5];// pl 은 배열명이다....
	for (int i = 0; i < 5; ++i) {
		printf("string >");
	//	char t[80];
		pl[i] = (char*)malloc(80);// char[80]
		fgets(pl[i], 80, stdin);
	}
	for (int i = 0; i < 5; ++i) {
		fputs(pl[i], stdout);
	}
	// 엇 동적할당함수 사용했네
	for (int i = 0; i < 5; ++i) {
		free(pl[i]);
	}

	return 0;
}
int string_dynamic() {
	char** ap = NULL;// 포인터배열 (동적)
	int count;
	printf("문자열 입력개수 : ");
	scanf_s("%d", &count);
	ap = (char**)malloc( count * sizeof(*ap) );
	for (int i = 0; i < count; ++i) {
		printf("string > ");
		ap[i] = (char*)malloc(80);
		fgets(ap[i], 80, stdin);
	}
	for (int i = 0; i < count; ++i) {
		fputs(ap[i], stdout);
	}

	for (int i = 0; i < count; ++i) {
		free(ap[i]);
	}
	free(ap);
	// 프로그래밍 -> 순서

	return 0;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {
//	string_array();
//	string_loop();
//	string_points();
	string_dynamic();

	return 0;
}
// end program
