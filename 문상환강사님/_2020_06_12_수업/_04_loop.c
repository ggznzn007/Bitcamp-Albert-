//<�ڵ� ����>
//1. ��ü ���� : Ctrl + A
//2. �ڵ� ���� : Ctrl + K, F

#include <stdio.h>
#include <conio.h>

void main()
{
	while (1)
	{
		printf("1. �ּ� �Է�\n");
		printf("2. �ּ� �˻�\n");
		printf("3. �ּ� ����\n");
		printf("4. �ּ� ����\n");
		printf("5. ���α׷� ����\n");

		printf("��ȣ�� �����ϼ��� >> \n");

		char sel = _getch();	// ���ڸ�
		printf("%c �� �����ϼ̽��ϴ�\n", sel);
		printf("������ ó���Ͽ����ϴ�~\n");
		printf("************************\n\n");
	}
}