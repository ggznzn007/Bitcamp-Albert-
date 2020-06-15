// 1. 문제가 뭐냐 ??? 
// 1-1. 프로그래밍 위해서 필요한 단어, 개념
// 1-2. 자료형, 함수
// 2. 제어문 실행할 순서, 절차에 따라 작성
// 반복 숙달만이 살아남는 방법이다...

// 선생님이 학생 점수를 입력하고 출력하는 프로그램
// 누가 ? 무엇을 ? 
// 점수를 입력, 출력
// 정수(0~100) scanf(), printf()
//	- 함수 사용 시 반환, 전달 파악하기

#include <stdio.h>

int step01() {
	// 점수 : 정수 (int)
	int score = 0;
	printf("Score > ");
	scanf_s("%d", &score); // 입력받아라... 저장한다...
	// 변수에 값을 다른 함수가 저장하게 하려면 변수 주소를 준다...
	printf(" 입력받은 점수 : %d \n", score);
	// 변수의 값을 전달

	return 0;
}
int step02() {
	// 점수 3개, 3과목 : 국어, 영어, 수학
	//	변수에는 1개의 값을 저장할 수 있다...
	int kor, eng, math;// 변수 여러 개 사용 시, 각각 변수 의미(용도)

	// scanf, printf 한 번 실행 시 여러 개 입출력 함수
	printf("국어 영어 수학 점수 순서로 입력 > ");
	scanf_s("%d %d %d", &kor, &eng, &math); // 순서가 중요

	printf("%d %d %d \n", kor, eng, math);

	return 0;
}
int step03() {
	// 학생이 5명 있음, 각 학생마다 국,영,수 점수를 가진다...
	//	총 15 개의 점수들
	// 여러 개의 데이터를 처리하는 프로그램 만드는 연습
	// 자료구조 : 여러 개 변수 다루는 방법 
	int score[15] = { 0 };
	// 배열 요소(변수) 각 0~ 번호 == 요소번호
	// 첫번째 학생의 3과목 점수로 보겠다...
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[0],&score[1],&score[2]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[3], &score[4], &score[5]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[6], &score[7], &score[8]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[9], &score[10], &score[11]);
	printf("첫번째 점수 > ");
	scanf_s("%d %d %d", &score[12], &score[13], &score[14]);

	printf("%d %d %d \n", score[0], score[1], score[2]);
	printf("%d %d %d \n", score[3], score[4], score[5]);
	printf("%d %d %d \n", score[6], score[7], score[8]);
	printf("%d %d %d \n", score[9], score[10], score[11]);
	printf("%d %d %d \n", score[12], score[13], score[14]);


	return 0;
}

int step04() {
	// 총 15개의 학생의 점수들 모두 입력,저장,출력 완료

	// 변수들의 개수 많아지면 제어문 활용
	// 배열 과 for 거의 한 쌍
	int score[15] = { 0 };

	for (int i = 0; i < 15; ++i) {
		int v;
		scanf_s("%d", &v);
		score[i] = v ;
	}
	// 1 ~ 25 까지 5행 5열
	for (int i = 0; i < 15; ++i) {
		printf("%d..", score[i]);
	}
	return 0;
}
int step05() {
	// 5 x 3 == 15개 정수들을 입력,저장,출력
	// 출력,추가적 계산(합,평균)
	//	구분 : 학생과 점수의 구분 방법이 필요
	int score[5 * 3] = { 0 };// [5][3]

	for (int i = 0; i < 13; i+=3) {
		printf("[0]번 학생의 점수 > ");
		scanf_s("%d %d %d",
			&score[i + 0], &score[i + 1], &score[i + 2]);
	}
	// 입력한 방법에 따라서 출력하세요
	int no = 1;
	for (int i = 0; i < 13; i += 3) {
		printf("[%d]번 학생의 점수 > ", no);
		no++;// no+=1
		printf("%d %d %d \n",
			score[i + 0], score[i + 1], score[i + 2]);
	}
	return 0;
}
/* 학생 점수 입출력 프로그램 구현(기초학습)
	각 단계별로 문법 적용해보기
*/
int main(void) {
	step05();

	return 0;
}



int main_01(void) {
	// 규칙에 따르면 머리는 단순해진다...
	// 식을 만들때는 최대한 머리를 사용하라...
	// 식 : 연산자를 사용한 문장 : 산술, 관계, 논리
	// 정수 1개를 화면에 출력하고 싶을 때
	int n = 100;
	printf("%d", n);// LNK 이름을 찾을 수 없다는 ? header file
	// 만약 헤더가 없다면 ... 함수 자체를 바꿔라...

	char ch = 'A';
	printf("%s", &ch);// 단, 문자열의 시작주소
	// 마지막 문자는 널문자여야 한다........

	return 0;
}



