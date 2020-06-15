// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
// 파일 입출력
// FILE 형 구조체, 포인터 변수
// 함수의 사용법 알아주세요
// 권한, 용도가 있음 - 소유자, 그룹, 외부 - w쓰기 r읽기 x실행
struct _data {
	int code;
	char name[80];
	int type;
};

int main(void){
	FILE* fp;
	// 파일에 쓰기한대로 읽어들인다
	// 파일 형식에 맞춰서 한다 
	struct _data d = { 0 };
	d.code = 100;
	strncpy_s(d.name, 80, "임의문자열", strlen("임의문자열"));
	d.type = 1;

	fopen_s(&fp, "demo-user.dat", "wb");
	fwrite(&d, sizeof(d), 1, fp);

	fclose(fp);
	return 0;
}


int main_bio(void) {
	// 블럭 입출력 (바이너리입출력)
	// 크기 단위로 입출력
	FILE* fp;
	const char* fname = "demo-block.dat";
	char nums[5][20] = {"AK","BK","CK","DK"};
	//fopen_s(&fp, fname, "wb"); // 쓰기모드
	fopen_s(&fp, fname, "rb");// 읽기모드
	//fwrite(nums, sizeof(nums), 1, fp);// 80바이트
	fread(nums, sizeof(nums), 1, fp);// 80바이트
	//fwrite(nums, sizeof(int), 20, fp);// 80바이트
	printf("%s \n", nums[0]);
	printf("%s \n", nums[1]);
	printf("%s \n", nums[2]);
	printf("%s \n", nums[3]);



	fclose(fp);
	return 0;
}


int main_write(void){
FILE* fp = NULL;
// 파일 열기

fopen_s(&fp, "demo.txt", "w"); //파일가져오는 함수 char * == "" 문자열
if (fp == NULL) {
	printf("not found error:%s\n", "demo.txt");
	return 0;
}
// 읽기 또는 쓰기(출력)
// 텍스트 파일 쉽다 이미 출력함수 알고 있다
fputc('A', fp);
fputc('\n', fp);
fputs("new world", fp); // 문자열 출력 // 파일에 출력
// 여러가지, 여러 개의 데이터
fprintf(fp, "%d %s \n", 100, "korea");

// 파일 닫기
fclose(fp);




return 0;
}


// start program //////////////////////////////////////////
int main_append(void) {
	FILE* fp = NULL;
	fopen_s(&fp, "demo.txt", "a"); //파일가져오는 함수 char * == "" 문자열
	if (fp == NULL) {
		printf("not found error:%s\n", "demo.txt");
		return 0;
	}
	fputc('A', fp);
	fputc('\n', fp);
	fputs("new world", fp); // 문자열 출력 // 파일에 출력
	// 여러가지, 여러 개의 데이터
	fprintf(fp, "[LOG]%s : %d-%d-%d : %s \n",
		"192.168.0.1",2020,06,20, "bitcamp");

	// 파일 닫기
	fclose(fp);

	return 0;

}
// end program


