#include <stdio.h>//표준 입출력 처리
#include <stdlib.h>//라이브러리 처리
#include <string.h>//문자열 처리
#include <conio.h>//기능키 처리가능하게 하는 헤더 파일
/*
	선언 후 사용
@arg :	
	argc - 인자의 개수
	argv - 문자열(들) 인자
	env - 환경
	lnk - 함수의 실제 실행 내용을 찾는 것 {} 를 찾는다 있으면 연결시켜줌.
*/
// 함수 선언부////////////////////////////////////////////
// { } 뺀 앞부분만 작성한 것 , 함수의 선언을 미리 작성해놓은 것이 헤더
void fn(void); // 반환되는 것이 없다.라는 의미
int sum(int a, int b);// 전달 되는 값을 받을 변수 - 매개 변수()안에 (독립적으로 작성)하는 변수
int printIntArray(int ar[], int length/* 배열 길이*/);
/////////////////////////////////////////////////////////

int getvalue(void)
{
	int result = 0;
	return result;
}

int main(int argc, char** argv, char** env) {// char* argv[] = char** argv
/*
	fn();// 함수 호출(실행);  fn - 전달 반환이 없는 함수
	int rt = getvalue();// 실행 후 int 형 값을 반환한다
	// 함수의 반환은 1개만 가능, 전달은 여러 개 가능
	int hap = sum(2, 10);
*/
	// 1차 배열을 전달한다.(배열명, 길이)
	int score[10] = { 0 };// 객체 지향의 핵심 1. 소유권
	int nums = printIntArray(score, 10);


	return 0;
}

// 함수 정의부/////////////////////////////////////////////
void fn(void)
{
	//반환형 void 일 때  - return 생략 가능 쓸려면 return; 쓰면 됨.
	return; // 함수를 종료
}
int sum(int a, int b)
{
	// 매개변수가 있는 함수를 호출할 때는 반드시 전달해야 한다
	int s = a + b;
	return s;
}
// 배열을 전달받는 함수 만들기
int printIntArray(int ar[], int length)
{
	// Q. 매개변수이다 int [] 배열
	// ar = 포인터 변수라서 반드시 길이값이 있어야 한다
	int nums = 0;// 출력한 개수를 반환 = 변수를 0으로 만든 후 1씩증가 하게 해야함
	for (int i = 0; i < length; ++i) {
		printf("%d ", ar[i]);
		nums++;
	}
	printf("\n");// 화면 행 단위
	return nums;
}
// END day4-1.c ///////////////////////////////////////////