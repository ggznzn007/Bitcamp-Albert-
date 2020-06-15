#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	// 길이가 15인 정수형 1차 배열 선언하기
	int numbers[15] = { 0 };
	int length = 15;// sizeof(배열명)/sizeof(int);
	// 난수 발생 기준값 변경 시 srand(); 사용
	// 모든 요소에 임의 정수를 저장하기
	srand((unsigned int)time(NULL));// 시간은 변하기 때문에 시간을 적어라
	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = rand();// 0 ~ 32656 임의 정수를 표현해서 저장가능

	}
	for (int i = 0; i < length; ++i) {
		printf("%6d", numbers[i]);

	}
	printf("\n");


	// 배열 처리 시 기본 기능
	int min;
	int max;
	min = max = numbers[0]; // 배열 요소 중에 하나로 초기화 하는 것
	// 찾기 : 값, 요소번호 중 어느 것을 찾는 것인지 확실히 할 것
	for (int i = 1; i < length; ++i) {
		if (min > numbers[i]) {// i 변수 값을 min변수에 저장
			min = numbers[i];
		}
		if (max < numbers[i]) {// i 변수 값을 max변수에 저장
			max = numbers[i];

		}
		printf("Max : %d, Min : %d \n", max, min);

		// 요소번호
		min = max = 0;
		for (int i = 1; i < length; ++i) {
			if (numbers[min] > numbers[i]) {// i 변수 값을 min변수에 저장
				min = i;
			}
			if (numbers[max] < numbers[i]) {// i 변수 값을 max변수에 저장
				max = i;
			}
		}
		printf("Max : %d, Min : %d \n", numbers[max], numbers[min]);

		// 배열 요소들을 크기 순서대로 재배치 - 정렬 sort
		// 정렬방법 - 알고리즘 다양
		// 비교 - 교환 
		int first = 0; // 첫 번째 요소번호
		int last = length - 1; // 마지막 요소번호

		for(int k = 0; k < (length/2); ++k) {
			int min = first;
			int max = first;
			for (int i = first + 1; i <= last; ++i) {
				if (numbers[min] > numbers[i]) {
					min = i;
				}
				if (numbers[max] < numbers[i]) {
					max = i;
				}
			}
			//교환
			int t = numbers[min];
			numbers[min] = numbers[first];
			numbers[first] = t;
			t = numbers[max];
			int t = numbers[max];
			numbers[max] = numbers[last];
			numbers[last] = t;
			



			printf("\n");
			++first;
			--last;
	}


	return 0;
}

	int main_01(void); {
	// 길이가 15인 정수형 1차 배열 선언하기
	int numbers[15] = { 0 };
	int length = 15;// sizeof(배열명)/sizeof(int);
	// 모든 요소에 임의 정수를 저장하기
	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = rand();// 0 ~ 32656 임의 정수를 표현해서 저장가능

	}
	for (int i = 0; i<length; ++i) {
		printf("%6d",numbers[i]);

	}
	printf("\n");

	return 0;
}