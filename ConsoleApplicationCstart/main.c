#include <stdio.h>
#include <windows.h>


int badukdol[30][30] = { 0 };
int dol = 1;
char key;
int x = 20, y = 10;
void draw_badukpan(); //�ٵ��Ǳ׸����Լ� ����
void gotoxy(int x, int y); //Ŀ���̵��Լ� ���� 
void draw_dol(); // �ٵϵ��׸����Լ� ����
void erase_dol(int x, int y); // �ٵϵ�������Լ� ����
void insert_key(char key, int *x, int *y); // Ű�Է¹޴� �Լ� ����
void put_spacebar(int badukdol[][30], int x, int y); // �ٵϵ������Լ�����
void draw_badukdol(int badukdol[][30]); // �ٵϵ��׸����Լ� ����
int winner(int badukdol[][30]);
void play();

void main() {
	printf("\n");
	printf("\t\t\t #2�ο� �������#\n\n");

	printf("@���Ӽ��� : �ٵϰ� ���� ����� ���� �ٵ��� ���� ����/����/�밢�� \n\t    ��� �����γ� ���� 5���� ������ ���� ����� �̱�� �ٵϳ���\n\n");

	printf("@���۹�� : ��(�����ĭ�̵�)\t��(�·���ĭ�̵�)\n\t   ��(������ĭ�̵�)\t��(�Ʒ�����ĭ�̵�)\n\t   space bar(�ٵϵ�����)\n\n");

	printf("\t\t ==========================================\n");
	printf("\t\t�� EnterŰ�� �Է��Ͻø� ������ ���۵˴ϴ� ��\n");
	printf("\t\t ==========================================\n\n");

	printf("@������ : �ӽ���\n@����������¥ : 2016-10-09 ");
	char ch = getch(); // ����Ű �Է¹޴� ����

	if (ch == 13) {
		system("cls");
		play();

	}

}

void play() {

	draw_badukpan(); // �ٵ��� ����20 ���� 20 ����
	gotoxy(x, y);
	draw_dol();

	do {
		key = getch();
		erase_dol(x, y);
		insert_key(key, &x, &y);
		draw_badukdol(badukdol);
		if (winner(badukdol))
		{
			return;
		}
		gotoxy(x, y);
		draw_dol();
	} while (key != 27);

};

void draw_badukpan() {
	int i, j;
	printf("��");
	for (i = 0; i < 20; i++)
	{
		printf("��");
	}
	printf("��\n");
	for (i = 0; i < 20; i++)
	{
		printf("��");
		for (j = 0; j < 20; j++)
		{
			printf("��");
		}
		printf("��\n");
	}
	printf("��");
	for (i = 0; i < 20; i++)
	{
		printf("��");
	}
	printf("��\n");
}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_dol() {
	if (dol == 1)
	{
		printf("��");
	}
	else {
		printf("��");
	}
};

void erase_dol(int x, int y) {

	gotoxy(x, y);
	if (x == 0 && y == 0)
	{
		printf("��");
	}
	else if (x == 42 && y == 0)
	{
		printf("��");
	}
	else if (x == 0 && y == 21)
	{
		printf("��");
	}
	else if (x == 42 && y == 21)
	{
		printf("��");
	}
	else if (x == 0)
	{
		printf("��");
	}
	else if (y == 0)
	{
		printf("��");
	}
	else if (x == 42)
	{
		printf("��");
	}
	else if (y == 21)
	{
		printf("��");
	}
	else
	{
		printf("��");
	}

};

void insert_key(char key, int *x, int *y) {

	switch (key) {
	case 75: if (*x - 2 < 0) {
		break;
	}
			 else { *x -= 2; }

			 break; // ����
	case 77: if (*x + 2 > 42)
	{
		break;
	}
			 else {
				 *x += 2;
			 }

			 break; // ������
	case 72: if (*y - 1 < 0)
	{
		break;
	}
			 else {
				 *y -= 1;
			 }
			 break; // ����
	case 80: if (*y + 1 > 21)
	{
		break;
	}
			 else {
				 *y += 1;
			 }
			 break; // �Ʒ���
	case 32: put_spacebar(badukdol, *x, *y); // �����̽���
		break;

	default:
		break;
	}
}

void put_spacebar(int badukdol[][30], int x, int y) {
	if (badukdol[y][x / 2] == 0)
	{
		if (dol == 1)
		{
			badukdol[y][x / 2] = 1;
			dol = 2;
		}
		else
		{
			badukdol[y][x / 2] = 2;
			dol = 1;
		}
	}



};

void draw_badukdol(int badukdol[][30])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (badukdol[j][i] == 1)
			{
				gotoxy(i * 2, j);
				printf("��");
			}
			else if (badukdol[j][i] == 2)
			{
				gotoxy(i * 2, j);
				printf("��");
			}
		}
	}
};

int winner(int badukdol[][30])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (badukdol[i][j] == 1 && badukdol[i][j + 1] == 1 && badukdol[i][j + 2] == 1 && badukdol[i][j + 3] == 1 && badukdol[i][j + 4] == 1)
			{
				gotoxy(20, 10);
				printf("�浹 �¸�");
				getch();
				return 1;
			}// �浹 ����
			else if (badukdol[i][j] == 2 && badukdol[i][j + 1] == 2 && badukdol[i][j + 2] == 2 && badukdol[i][j + 3] == 2 && badukdol[i][j + 4] == 2)
			{
				gotoxy(20, 10);
				printf("�鵹 �¸�");
				getch();
				return 1;
			}//�鵹 ����

			else if (badukdol[j][i] == 1 && badukdol[j + 1][i] == 1 && badukdol[j + 2][i] == 1 && badukdol[j + 3][i] == 1 && badukdol[j + 4][i] == 1)
			{
				gotoxy(20, 10);
				printf("�浹 �¸�");
				getch();
				return 1;
			} //�浹 ����
			else if (badukdol[j][i] == 2 && badukdol[j + 1][i] == 2 && badukdol[j + 2][i] == 2 && badukdol[j + 3][i] == 2 && badukdol[j + 4][i] == 2)
			{
				gotoxy(20, 10);
				printf("�鵹 �¸�");
				getch();
				return 1;
			}//�鵹 ����

			else if (badukdol[i][j] == 1 && badukdol[i + 1][j + 1] == 1 && badukdol[i + 2][j + 2] == 1 && badukdol[i + 3][j + 3] == 1 && badukdol[i + 4][j + 4] == 1)
			{
				gotoxy(20, 10);
				printf("�浹 �¸�");
				getch();
				return 1;
			}// �浹 �������밢��

			else if (badukdol[i][j] == 2 && badukdol[i + 1][j + 1] == 2 && badukdol[i + 2][j + 2] == 2 && badukdol[i + 3][j + 3] == 2 && badukdol[i + 4][j + 4] == 2)
			{
				gotoxy(20, 10);
				printf("�鵹 �¸�");
				getch();
				return 1;
			}// �鵹 ����������

			else if (badukdol[19 - j][i] == 1 && badukdol[18 - j][i + 1] == 1 && badukdol[17 - j][i + 2] == 1 && badukdol[16 - j][i + 3] == 1 && badukdol[15 - j][i + 4] == 1)
			{
				gotoxy(20, 10);
				printf("�浹 �¸�");
				getch();
				return 1;
			} //�浹 �Ʒ��ʴ밢��

			else if (badukdol[19 - j][i] == 2 && badukdol[18 - j][i + 1] == 2 && badukdol[17 - j][i + 2] == 2 && badukdol[16 - j][i + 3] == 2 && badukdol[15 - j][i + 4] == 2)
			{
				gotoxy(20, 10);
				printf("�鵹 �¸�");
				getch();
				return 1;
			} //�鵹 �Ʒ��ʴ밢��

		}
	}

	return 0;
};