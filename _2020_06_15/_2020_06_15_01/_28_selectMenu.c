#include <stdio.h>

void viewMenu()
{
	printf("\t<�ּҷ� ���� ���α׷�>\n");
	printf("1. �Է�\n");
	printf("2. �˻�\n");
	printf("3. ����\n");
	printf("4. ����\n");
	printf("5. ��ü���\n");
	printf("6. ����\n");
}

int getSelNum()
{
	int selNum = 0;
	printf("\n��ȣ�� �����ϼ��� >> ");
	scanf_s("%d", &selNum);

	return selNum;
}

void processWork(int selNum)
{
	if (selNum == 1)
		printf("�Է�ó���Ͽ����ϴ�~\n");
	else if (selNum == 2)
		printf("�˻�ó���Ͽ����ϴ�~\n");
	else if (selNum == 3)
		printf("����ó���Ͽ����ϴ�~\n");
	else if (selNum == 4)
		printf("����ó���Ͽ����ϴ�~\n");
	else if (selNum == 5)
		printf("��ü���ó���Ͽ����ϴ�~\n");
	else if (selNum == 6)
		printf("���α׷� �����ϰڽ��ϴ�~\n");
}

void main()
{
	int selNum = 0;

	// ����ó���� ���� �� �ٽ� �޴��� ��Ÿ�� �� 
	// �ֵ��� ���� ���� ó���� �Ѵ�.
	while (1)
	{
		viewMenu();				// 1. �޴� �����ֱ�
		selNum = getSelNum();	// 2. ����� �Է�
		processWork(selNum);	// 3. ó��
	}
}