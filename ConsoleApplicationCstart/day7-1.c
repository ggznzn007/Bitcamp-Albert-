// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>// ���Ű ó�� ����


// global variables ///////////////////////////////////////
struct position {
	int x;
	int y;
	int u;
	int d;
	int l;
	int r;
};
struct _Coord {
	int length;// arr �迭�� ����(���� ����)
	//struct position arr[40*30]; //�����迭
	struct position* arr; // �����迭

};
typedef struct _coord Coord;
typedef struct position Position;

#define W 40//��ũ�� ��� ������ ���Կ��� �Ұ���
#define H 30//��ũ�� ��� ������ ���Կ��� �Ұ���
int map[H][W];//�����迭(��� �Լ����� ���� ����), �ڵ� 0 �ʱ�ȭ��

// section function body //////////////////////////////////
int showMap(void) {
	//Ű����� �̵��� ��Ű�� �̵���θ� ������ �����
	//�� �� �Է½� ȭ�� �׸��� ����ϰ� ����� ����
	// ����Ű ����
	for (int r = 0; r < H; ++r) { // �� ���� : H
		for (int c = 0; c < W; ++c) { // �� ���� : W
			map[r][c] = 1;
		}
	}
	return 0;

}
// �ܼ� ȭ�� �� ��ġ : gotoxy(); win32 api//
int drawMap(void) {
	//Ű����� �̵��� ��Ű�� �̵���θ� ������ �����
	//�� �� �Է½� ȭ�� �׸��� ����ϰ� ����� ����
	// ����Ű ����
	int iy, ix;
	iy = ix = 0;
	while (1) {//���ѷ���
		system("cls");//�ܼ� �󿡼� ������ �� �ִ� ���α׷�// ȭ�������
		for (int r = 0; r < H; ++r) { // �� ���� ���� : H
			for (int c = 0; c < W; ++c) { // �� ���� ���� : W	
				if (r==iy && c==ix) {
					printf("��");//�����ڸ� ������ Ÿ����� ���ڿ�
				}
				else {
				printf("%s", (map[r][c])?"��":"��");// ���� ������ ����
				}
				
			}
			putchar('\n');// ���̶�� ǥ���� �Ϸ��� ���๮�� ��� �ʿ�
		}// end for
		// Ű���尡 ������ ��
		if (_kbhit()) {// ���ͷ�Ʈ, �̺�Ʈ�߻�
			// �Էµ� ���� Ȯ��?
			char ch = _getch();//echo ����(ȭ�鿡 ����������)
			// ����Ű�� ���Ű - ���� ��ƴ�
			// ���Ű �Է� �� 2����Ʈ ����// ù1����Ʈ�� 0 �Ǵ� 0xE0
			
			if (ch == -32) {// 224 char ������ �ִ� 127
				ch = _getch();
				
			}			
			// �ι�° ����Ʈ ���� Ű�� == �ι� �о�� �Ѵ� 
			if (ch == '\r') {// <enter> = \r  �ν� conio.h��
				break;// stop while
				// �Ʒ� return �ٷ� ������
			} 
			//ch = tolower(ch); //�ҹ��ں����Լ� //ctype.h ��� �ʿ�
							  // ����Ű �̵� Ű���� Ű��
			//����Ű �̵� =1;
			if (ch == 'w'|| ch == 'W' || ch == 72 ) {// UP
				--iy; 
			}
			if (ch == 's' || ch == 'S' || ch == 80 ) {//DOWN
				++iy;
			}
			if (ch == 'a' || ch == 'A' || ch == 75 ) {//LEFT
				--ix;
			}
			if (ch == 'd' || ch == 'D' || ch == 77 ) {//RIGHT
				++ix;
			}
			//���� ��ġǥ��
			map[iy][ix] =  1;
			//map[iy][ix] =1 - map[iy][ix]; // ��� �Դ� ����
		}
	}// end while
	printf("end drawMap()\n\n");
	return 0;

}
// ���� ����ü ���� �迭 ���� ������

Coord* searchMap(void) {
//	map[][];
	Coord *var;
	var = (Coord*)malloc(sizeof(Coord));
	var->length = 0;
	var->arr = (Position*)malloc(var->length * sizeof(Position));
	return &var;
}
// start program //////////////////////////////////////////
int main(int argc, char** argv) {
	
	//drawMap();// ȣ���ϴ� ��ġ���� ���� �ݵ�� ���� �Ǵ� {����}�� �־����
	Coord* cp;
	cp = searchMap(); // map[][] Ž�� ���̸� �� �� ���� �迭 - �����迭 ����
	for (int i = 0; i < cp->length ; ++i) {
		printf("(%d, %d){ %d %d %d %d } \n",
			cp->arr[i].x,// �迭�� �����ϴ� ����
			cp->arr[i].y,// �迭�� �����ϴ� ����
			cp->arr[i].u,
			cp->arr[i].d,
			cp->arr[i].l,
			cp->arr[i].r
			);
	}

	return 0;
}



// end program


