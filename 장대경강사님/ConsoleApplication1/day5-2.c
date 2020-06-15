#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// data ??? 여러 개의 데이터처리 시 반드시 하나를 지정하는 방법
struct _car {
	int number;
	double price;
	time_t in;
	time_t out;
};
typedef struct _car Car;

// Car 를 여러 개 저장(주차)해야니까 배열을 사용
Car list[20];
int seq;
int hasEmpty(void) {
	// 비어있다 ? 상태를 어떻게 표현할 것인가>
	// 1번~ 19번
	for (int i = 0; i < 20; ++i) {
		if (list[i].number == 0) {
			return i;
		}
	}
	return -1;// 빈 자리가 없다...
}
int goHome() {
	time_t now = time(NULL);
	// 시간 계산 방법
	struct tm tm;
	localtime_s(&tm, &now);
	int h = tm.tm_hour;
	int m = tm.tm_min;
	if ( (h*100+m) > 1800) {
		return 0;// 퇴근시간이다...
	}
	return 1;
}
int main(int argc, char** argv) {
	printf("// 주차장입니다.... 저는 주차장 관리자입니다.\n");
	do {
		printf("[1]IN [2]OUT > ");
		// 키보드입력 : 
		char key = getchar(); getchar();
		if (key == '1') {
			printf("// 차가 들어오고 있다...\n");
			printf("// 주차장 내 빈 공간이 있으면?");
			if (hasEmpty() != -1) {
				printf("주차할 수 있다...\n");
				Car car;
				printf("차량번호 > ");
				scanf_s("%d", &car.number);
				car.price = 1000.0;
				car.in = time(NULL);
				// 주차시키기
				list[seq] = car;
				++seq;
			}
			else {
				printf("//	빈 자리 나가세요\n");
			}
		}
		if (key == '2') {
			printf("// 차가 나가고 있다.... \n");
			printf("차량번호 > ");
			int num;
			scanf_s("%d", &num);
			Car car;
			car.number = 0;
			for (int i = 0; i < 20; ++i) {
				if (num == list[i].number) {
					car = list[i];
					printf("// 차가 나갔으니 빈 자리가 생겼다...\n");
					list[i].number = 0;// 빈 자리 
					break;
				}
			}
			if (car.number != 0) {
				printf("//	요금내야죠~\n");
				car.out = time(NULL);
				// 시간 차이(주차한 시간)
				car.price += 5000.0;
				printf("요금 : %lf \n", car.price);
			}

		}
	} while ( goHome() );
	printf("// 퇴근 시간이 되어서 주차장 출입문 잠그고 집에 간다...\n");

	return 0;
}
/*

int main_02(int argc, char** argv) {
	ACar list;			// struct _car list[12];
	PCar now = &list[0];//	struct _car *now;
	Car temp;

	printf("%d \n", sizeof(list));

	temp = list[0];// 구조체 변수의 복사... 
	temp.number = 11;
	temp.price = 1000.0;

	printf("%d, %lf\n", now->number, now->price);
	now = &temp;
	printf("%d, %lf\n", now->number, now->price);

	return 0;
}
int main_01(int argc, char** argv) {
	struct _car t;
	t.number = 1003;
	t.price = 1000.0;

	// 주소->멤버명
	(&t)->number = 2003;

	// 포인터 변수는 주소다...
	struct _car* cp;
	cp = &t;
	cp->price = 2000.0;

	(*cp).number = 3003;

	// 만약 헷갈린다면 -> 를 많이 쓰셔라....


	return 0;
}
*/