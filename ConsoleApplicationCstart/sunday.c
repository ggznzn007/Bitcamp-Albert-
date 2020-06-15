/*
// 1. 문제가 뭐냐?
// 1-1. 프로그래밍 위해서 필요한 단어, 개념
// 1-2. 자료형, 함수
// 2. 제어문 실행할 순서, 절차에 따라 작성
// 반복 숙달 
// 주제부터 정하라(프로그램, 프로젝트 등)
// 주제에 필요한 함수들을 적절하게 이용해서 완성


// 선생님이 학생 점수를 입력하고 출력하는 프로그램
// 학생 점수 관리 프로그램 // 누가? User? // 기능(funtion) 영향
// 무엇을? what? want? needs?
// 점수 입력, 출력 (input, output) 목적어를 어떻게 (동사,명령어) 한다
// 점수 = 목적을 어떤 자료형으로 표현하는지(정수,실수) int  
// 정수(0~100) scanf(), printf() 함수를 찾아라
// - 함수 사용 시 반환, 전달을 파악하기 = 응용가능
// 점수의 표현은 어떻게 할 것인가?  범위는? 

// 코딩 : 첫 번째 실행되는게 무엇인가?
*/

/*
int main(void) {
	// 규칙에 따르면 머리는 단순해진다
	// 식을 만들때는 최대한 머리 사용
	// 식 : 연산자를 사용한 문장 : 산술, 관계, 논리
	// 100을 출력하고 싶어// 원하는 값을 변수 만들어서 일단 넣어라
	// 정수 1개를 화면에 출력하고 싶을 때 - 따로 저장해 놓아라
	int n = 100;
	printf("        %d\n", n);// LNK 이름을 찾을 수 없다면? header 파일 찾고
	printf("\n");
	printf("        %d\n", n);// 만약 헤더가 없다면 함수를 자체를 바꿔라
	char ch = 'A';
	printf("%s", &ch);//단, 문자열의 시작주소
	// 마지막 문자는 널문자여야 한다// 함수를 찾아서 공부를 해보라

	return 0;
}
*/

#include <stdio.h>


int step01() {
	// 점수 : 정수(int)
	int score = 0;
	printf("score >");
	scanf_s("%d", &score); // 입력받아라,저장한다 &붙여서 ~에 
	// 변수에 값을 다른 함수가 저장하게 하려면 변수 주소를 준다

	printf("입력받은 점수 :  %d \n", score);
	// 변수의 값을 전달
	return 0;
}

int step02() {
	// 점수 1개, 3과목 : 국 영 수
	// 변수에는 1개의 값을 저장할 수 있다
	int k, e, m;// 변수 여러개 사용 시, 각각의 변수 의미 인지하라(용도)

	// scanf, printf 한번 실행 시 여러 개 입출력 함수
	printf("국어 영어 수학 점수 순서로 입력 > ");
	scanf_s("%d %d %d", &k, &e, &m);	// 순서 중요

	printf("%d %d %d \n", k, e, m);	
	return 0;
}

int step03() {
	// 학생 5명, 각 학생마다 국,영,수 점수를 가진다
	// 총 15개의 점수들
	// 여러개의 데이터를 처리하는 프로그램 만드는 연습
	// 1반 5명, 12반, 3학년, 행정 구 학교 5개, 시 6개의 구 점점
	int k1, e1, m1; // 변수를 선언하는 개수가 많아진다.
	int k2, e2, m2; // 다수의 변수를 다루는게 필요한다
	// 자료구조 : 다수의 변수를 다루는 방법
	int score[15] = { 0 }; //배열 요소(변수) 각 0~ 번호 == 요소번호
	// 첫번째 학생의 3과목 점수로 보겠으
	score[0];
	score[1];
	score[2];
	// 두번째 학생의 3과목 점수
	score[3];
	score[4];
	score[5];
	// 세번째 학생의 3과목 점수
	score[6];
	score[7];
	score[8];
	// 네번째 학생의 3과목 점수
	score[9];
	score[10];
	score[11];
	// 다섯번째 학생의 3과목 점수
	score[12];
	score[13];
	score[14];

	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[0], &score[1], &score[2]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[3], &score[4], &score[5]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[6], &score[7], &score[8]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[9], &score[10], &score[11]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[12], &score[13], &score[14]);

	printf("%d %d %d\n", &score[0], &score[1], &score[2]);
	printf("%d %d %d\n", &score[3], &score[4], &score[5]);
	printf("%d %d %d\n", &score[6], &score[7], &score[8]);
	printf("%d %d %d\n", &score[9], &score[10], &score[11]);
	printf("%d %d %d\n", &score[12], &score[13], &score[14]);

	
	return 0;
}

int step04() {
	// 총 15개의 학생의 점수들 모두 입력,저장,출력은 끝
	// 변수들의 개수가 많아짐에 따라 제어문 활용
	// 배열과 for문 한쌍으로 
	int score[15] = { 0 };

	for (int i = 0; i < 15; ++i) {
		int v;
		scanf_s("%d", &v);
		score[i] = v; // 키보드 입력값 

	}
	// 1~25 까지 5행 5열
	for (int i = 0; i < 15; ++i) {
		printf("%d", score[i]);
		

	}
	return 0;
}


int step05() {
	// 5 * 3 == 15개 정수들을 입출력 저장
	// 출력, 추가적 계산(합,평균)
	// 구분 : 학생과 점수의 구분 방법이 필요 - 사람의 입장에서 필요
	int score[5 * 3] = { 0 };// 5행 3열 [5] [3]

	for (int i = 0; i < 13; i+=3) {
		printf("[0]번 학생의 점수 >"); // 학생 구분 출력
		scanf_s("%d %d %d",
			&score[i + 0], &score[i + 1], &score[i + 2]); // 3개씩 
			
	}
	// 입력한 방법에 따라 출력하세요
	int no = 1;
	for (int i = 0; i < 13; i += 3) {
		printf("[%d]번 학생의 점수 >",no); // 학생 구분 출력
		no++;// no+=1 1씩 증가된다 그리고 어디에서 실행되는지
		printf("%d %d %d\n",
			&score[i + 0], &score[i + 1], &score[i + 2]); // 3개씩 
		
}
	return 0;
}

/*
학생 점수 입출력 프로그램 구현(기초학습)
각 단계별로 문법 적용해보기
*/



int main(void) {
	step05();

	return 0;
}