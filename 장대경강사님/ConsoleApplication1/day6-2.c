// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////

// section function body //////////////////////////////////



// start program //////////////////////////////////////////
int main(void) {
	// 정적 배열 선언의 제한.... 동적 배열을 사용하는 이유 !!
	int nums[10];// 선언 시 길이를 변수를 사용할 수 없다..
	int len = 10;
	int* p = (int*)malloc(len * 4);// 동적 배열은 길이 변경 가능

	// 길이를 추가(늘린다)가 불가
	//	동적배열은 가변 길이로써 변경이 가능
	len += 12;
	p = (int*)realloc(p, len * 4 );// 이 함수는 동적할당으로 생성된 것만 사용 가능

	free(p);

	return 0;
}
int main_02(void) {
	// 동적할당 : 포인터변수, 함수 - 결국 배열
	int length = 60;
	char* p = (char*)malloc( length * sizeof(char)/*전체크기*/);// 동적할당 함수
	char arr[60];
	// p[0] ~ p[59]
	for (int i = 0; i < length; ++i) {
		p[i] = 'a' + i;// 배열이다....
	}
	
//	p = p + 20;// 주소 변경하면 안됩니다.

	// 동적할당으로 생성된 공간, 배열 은 반드시 해제한다...
	if (p != NULL) {
		free(p);// 이렇게 할당받은 주소를 다시 써야 한다...
		// p 를 변경하면 안된다....
		p = NULL;
	}
	return 0;
}
int main_01(int argc, char** argv) {
	// 배열 쪼개기 : 크기가 다른 여러 개의 처리
	char student[80] = { 0 };
	char* name = student;
	int* kor = student + 60;
	int* eng = student + 64;
	int* math = student + 68;
	int* score = (int*)(student + 60);// &student[60]
	// 포인터변수는 선언 시 지정된 자료형에 따라 동작한다...

	scanf_s("%s", name, 60);// 포인터변수의 크기 4byte
	scanf_s("%d %d %d", score + 0, score + 1, score + 2);
	printf("%s : { %d, %d, %d} \n", 
		name, *kor, *eng, *math);

	return 0;
}
// end program

