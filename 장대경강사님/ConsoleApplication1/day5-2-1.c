#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// data ??? ���� ���� ������ó�� �� �ݵ�� �ϳ��� �����ϴ� ���
struct _car {
	int number;
	double price;
	time_t in;
	time_t out;
};
typedef struct _car Car;

// Car �� ���� �� ����(����)�ؾߴϱ� �迭�� ���
Car list[20];
int seq;
int hasEmpty(void) {
	// ����ִ� ? ���¸� ��� ǥ���� ���ΰ�>
	// 1��~ 19��
	for (int i = 0; i < 20; ++i) {
		if (list[i].number == 0) {
			return i;
		}
	}
	return -1;// �� �ڸ��� ����...
}
int goHome() {
	time_t now = time(NULL);
	// �ð� ��� ���
	struct tm tm;
	localtime_s(&tm, &now);
	int h = tm.tm_hour;
	int m = tm.tm_min;
	if ( (h*100+m) > 1800) {
		return 0;// ��ٽð��̴�...
	}
	return 1;
}
int main(int argc, char** argv) {
	printf("// �������Դϴ�.... ���� ������ �������Դϴ�.\n");
	do {
		printf("[1]IN [2]OUT > ");
		// Ű�����Է� : 
		char key = getchar(); getchar();
		if (key == '1') {
			printf("// ���� ������ �ִ�...\n");
			printf("// ������ �� �� ������ ������?");
			if (hasEmpty() != -1) {
				printf("������ �� �ִ�...\n");
				Car car;
				printf("������ȣ > ");
				scanf_s("%d", &car.number);
				car.price = 1000.0;
				car.in = time(NULL);
				// ������Ű��
				list[seq] = car;
				++seq;
			}
			else {
				printf("//	�� �ڸ� ��������\n");
			}
		}
		if (key == '2') {
			printf("// ���� ������ �ִ�.... \n");
			printf("������ȣ > ");
			int num;
			scanf_s("%d", &num);
			Car car;
			car.number = 0;
			for (int i = 0; i < 20; ++i) {
				if (num == list[i].number) {
					car = list[i];
					printf("// ���� �������� �� �ڸ��� �����...\n");
					list[i].number = 0;// �� �ڸ� 
					break;
				}
			}
			if (car.number != 0) {
				printf("//	��ݳ�����~\n");
				car.out = time(NULL);
				// �ð� ����(������ �ð�)
				car.price += 5000.0;
				printf("��� : %lf \n", car.price);
			}

		}
	} while ( goHome() );
	printf("// ��� �ð��� �Ǿ ������ ���Թ� ��װ� ���� ����...\n");

	return 0;
}
/*

int main_02(int argc, char** argv) {
	ACar list;			// struct _car list[12];
	PCar now = &list[0];//	struct _car *now;
	Car temp;

	printf("%d \n", sizeof(list));

	temp = list[0];// ����ü ������ ����... 
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

	// �ּ�->�����
	(&t)->number = 2003;

	// ������ ������ �ּҴ�...
	struct _car* cp;
	cp = &t;
	cp->price = 2000.0;

	(*cp).number = 3003;

	// ���� �򰥸��ٸ� -> �� ���� ���Ŷ�....


	return 0;
}
*/