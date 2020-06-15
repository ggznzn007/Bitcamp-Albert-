#include <stdio.h>

/*
		선언 후 사용
*/

int main(void) {
	// 일정한 크기 배열을 무한한 공간처럼 사용하는 방법(알고리즘)
	// 2 개 이상의 변수들로 공간을 제어하는 방법 
	// 요소 번호로 제어하는 아이디어가 핵심 - 원형 큐
	// 스택 : 선입후출, 후입선출 LIFO 
	int score[10] = { 0 };
	int sp = -1;// 마지막 요소에 대한 표현이 되도록 만들어라
	//추가하기
	++sp;
	score[sp] = 1;
	// 마지막 요소를 꺼내기
	int value = score[sp];
	--sp;
	return 0;
}





int main_05(void) {
	// 정수 배열 - 추가
	// 추가 시 초기값에 따라 증감 순서가 다르고 번호 범위를 판단하는 조건이 다르다
	int score[10] = { 0 };
	int last = 0; // 마지막 추가된 요소번호
	score[last] = 1;// 처음이자 마지막 데이터 총 개의 1개 데이터 저장
	++last;
	score[last] = 2;// 처음이자 마지막 데이터 총 개의 2개 데이터 저장
	++last;
	score[last] = 3;// 처음이자 마지막 데이터 총 개의 3개 데이터 저장
	++last;
	// 출력 시 추가된 값들(저장한) 출력하라
	for (int i = 0; i < last; ++i) {
		printf("[%d] %d\n", i, score[i]);
	}

	if (last < 10 ) {// 범위 내에서 추가 
		score[last] = 3;
		++last;
	}
	else {
		printf("full\n");
	}

	return 0;
}





int main_04(void) {
	// 정수 배열 - 추가
	int score[10] = { 0 };
	int last = -1; // 마지막 추가된 요소번호
	++last;
	score[last] = 1;// 처음이자 마지막 데이터 총 개의 1개 데이터 저장
	++last;
	score[last] = 2;// 처음이자 마지막 데이터 총 개의 2개 데이터 저장
	++last;
	score[last] = 3;// 처음이자 마지막 데이터 총 개의 3개 데이터 저장
	// 출력 시 추가된 값들(저장한) 출력하라
	for (int i = 0; i <= last; ++i) {
		printf("[%d] %d\n", i, score[i]);
	}

	if (last < 10-1) {// 범위 내에서 추가 
		++last;
		score[last] = 3;
	}
	else {
		printf("full\n");
	}

	return 0;
}




int main_03(void) {
	// 정수 배열
	int maxlength = 10;// 최대값 정하기
	int d2[2][5]; // 행번호 * 행길이 + 열번호 = 1차 배열 활용하여 = 2차배열과 같은 효과
	// 5개씩 2개의 배열이 있다는 정의 = [2][5] // row * length of row + col = [row행] [col열]
	int score[2 * 5] = { 0 }; // 10개 짜리 배열을 만드는 것// {0} 초기화된 배열 생성
	int index = 1*5 +2;
	score[7] = 1;
	printf("%d \n", score[index]);
	printf("%d \n", score[7]);

	return 0;
}


int main_02(void) {
	int score[] = { 1,2,3,4,5,6,7,8,9, };// 묵시적 선언 - 말하지 않아도 알아요
	int length = sizeof(score)/sizeof(score[0]);// 배열의 길이를 변수에 따로 저장 할 것

	printf("%d \n", score);// 배열의 시작주소, [0]번 요소의 주소

	// sizeof() 연산 - 메모리 내에서의 크기 연산  = byte
	printf("size of array : %d \n", sizeof(score));// 배열명
	printf("size of element : %d \n", sizeof(score[0]));//요소명

	printf("long %d \n", sizeof(long));
	printf("long  int %d \n", sizeof(long int));
	printf("long long %d \n", sizeof(long long));


	return 0;
}

int main_01(void) {
	//배열 선언, 생성 - 자료형 결정 후, 최대 저장 개수(길이)를 정함
	int arr[10]; // 선언!!! [] 하나 인 것을 1차 배열 - 선형 
	char string[80]; // 문자 배열 -> 문자열 = 캐릭형 배열(콘솔 행 하나값 80, 기본)
	
	int length = 10;// 배열의 길이(length)를 선언 , 현재길이와 최대 길이 항상 비교
	int curlength = 0;// 배열의 현재길이를 선언  (최대 길이를 기억)

	int index = 0;// 배열 요소번호 : 각 요소의 일련 번호 (index)
	// 배열명 : arr - [0]번 요소의 주소를 의미 = 암기 !!!
	// 요소명 : 배열명[번호]
	// 요소가 배열인 경우 - 2차(다차) 배열
	// 요소명 == 배열명 
	//arr 배열에 i번 요소
	// 처리방법 - 반복문 사용 



	for (int i = 0; i < length; ++i) {
		arr[i] = (i + 1);// 모든 요소에 임의 값을 저장
	}
	for (int i = 0; i < length; ++i) {
		printf("%d,", arr[i]);// 요소 값을 출력
	}

	return 0;
}