
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 파일 입출력 
//	FILE 형 구조체, 포인터변수
//		함수의 사용법 알아주세요
//	권한, 용도가 있다... 소유자,그룹,외부 - w r x
struct _data {
	int code;
	char name[80];
	int type;
};
int main(void) {
	FILE* fp;
	// 파일에 쓰기한대로 읽어들인다...
	// 파일에 쓰기한 형식이 뭐냐 : format
	struct _data d = { 0 };
	d.code = 100;
	strncpy_s(d.name, 80, " 임의문자열 ", strlen(" 임의문자열 ") );
	d.type = 1;

	fopen_s(&fp, "demo-user.dat", "wb");
	fwrite(&d, sizeof(d), 1, fp);
	fclose(fp);

	struct _data t;
	fopen_s(&fp, "demo-user.dat", "rb");
	fread(&t, sizeof(t), 1, fp);
	fclose(fp);
	printf("%d %s %d \n", t.code, t.name, t.type);

	return 0;
}
int main_binary(void) {
	// 블럭입출력(바이너리입출력)
	// 크기 단위로 입출력
	FILE* fp;
	const char* fname = "demo-block.dat";
	char nums[5][20] = { 0 };
	fopen_s(&fp, fname, "rb");
//	fwrite(nums, sizeof(nums), 1, fp);// 80바이트
	fread(nums, sizeof(nums), 1, fp);// 80바이트
	fclose(fp);
	printf("%s \n", nums[0]);
	printf("%s \n", nums[1]);
	printf("%s \n", nums[2]);
	printf("%s \n", nums[3]);
	return 0;
}
int main_append(void) {
	FILE* fp = NULL;
	fopen_s(&fp, "demo.txt", "a");
	// 파일이 있으면 기존 파일 끝에 추가
	//		  없으면 새로 생성
	if (fp == NULL) {
		printf("not found error : %s \n", "demo.txt");
		return 0;
	}
	fprintf(fp, "[LOG]%s: %d-%d-%d : %s\n", 
		"192.168.0.1", 2020,10,20, "bicamp");
	// 파일 닫기
	fclose(fp);
	return 0;
}
int main_write(void) {
	FILE* fp = NULL;
	// 파일 열기
	fopen_s(&fp,"demo.txt","w");// char * : ""
	if (fp == NULL) {
		printf("not found error : %s \n", "demo.txt");
		return 0;
	}
	// 읽기 또는 쓰기(출력)
	// 텍스트 파일 쉽다... 이미 출력함수 알고 있다...
	fputc('A', fp);
	fputc('\n', fp);
	fputs("new new new new", fp);
	// 여러 가지, 여러 개의 데이터
	fprintf(fp, "%d %s \n", 100, "korea");
	// 파일 닫기
	fclose(fp);
	return 0;
}