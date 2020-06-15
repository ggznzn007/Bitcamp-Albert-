// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////

int main(void) {
	// 정적 배열 선언의 제한// 동적 배열을 사용하는 이유 !!
	int nums[10];// 선언 시 길이를 변수로 사용할 수 없다
	int len = 10;
	int* p = (int*)malloc(len * 4);// 동적 배열은 길이 변경가능

	// 길이를 추가가 불가
	// 동적배열은 가변 길이로써 변경가능
	len += 12;
	p = (int*)realloc(p, len * 4);// 재할당하는 함수// 동적할당으로 생성된 것만 사용가능



	return 0;

}

	



struct _std {
	char name[60];
	int kor ;
	int eng ;
	int mat ;
};



int main_02(void) {
	// 동적할당 : 포인터변수, 함수 - 결국 배열
	int length = 60; // int length = sizeof(p); // 길이 값을 만들어줘야 함
	char* p = (char*)malloc(60* sizeof(char)/*전체크기*/);// 동적할당 함수
	char arr[60];
	// == p[0] ~ p[59] 배열을 만든 것
	for (int i = 0; i < length; ++i) {
		p[i] = 'a' + i; // 배열
	
	}
	// 동적할당으로 생성된 공간, 배열은 반드시 해제한다.
	if (p != NULL) {
		free(p); // 할당받은 주소를 다시 써야 해서 
				// p를 변경하면 안됨 (주소를 유지) 바뀌면 에러// 에러시 복구시간오래걸림.
		p = NULL;
	}
	return 0;
}



// start program //////////////////////////////////////////
int main_01(int argc, char** argv) {
	// 배열 쪼개기	: 크기가 다른 여러개의 데이터 처리
	char student[80];
	char* name = student;
	int* kor = student + 60;
	int* eng = student + 64;
	int* mat = student + 68;
	int* score = (int*)(student + 60);// == &student[60]
	// 포인터변수는 선언시 지정된 자료형에 따라 동작한다

	scanf_s("%s", name, 60);// 포인트 변수 크기 4바이트
	scanf_s("%d %d %d", score + 0, score + 1, score + 2);
	printf("%s : { %d, %d, %d} \n",
		name, *kor, *eng, *mat);
	



	return 0;
}



// end program