#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 5;
	int i, j, k;
	clrscr();
	for (i = 0; i < n; i++)// i�� n���� 1�� �����ϴµ���
	{
		for (j = n - 1; j > i; j--)// j�� n-1�϶� i���� Ŀ�������� 1�� �����ϴµ���
		{
			printf(" ");// ������ ����ϰ�

		}
		for (k = 0; k <= i; k++)// k�� i�� ������������ 1�������ϴ� ����
		{
			printf("%c", k + 65);//ASCII CODE// k+65���� ���ڿ��� ����ϰ�
		}
		printf("\n");// �����϶�
	}
	getchar();
}