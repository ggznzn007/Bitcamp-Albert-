/*
	1. �ҽ� ���� ����� .c
	2. ��� ���� ���̱� .h
	3. main �Լ� ����� int main() { return 0;}
	4. main �Լ� �ȿ� ���� ���� �ۼ��ϱ�
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*	���� �� ���
	@arg : 
		argc - ������ ����
		argv - ���ڿ�(��) ����
*/
// �Լ� ����� //////////////////////////////////
// { } �� �պκи� ���� ��
void fn(void);
int Sum(int a, int b);// ���޵Ǵ� ���� ���� ���� - �Ű�����
int printIntArray(int ar[], int length/* �迭 ����*/ );

////////////////////////////////////////////////
int getValue(void)
{
	int result = 0;
	return result;
}

int main(int argc, char** argv) {// char* argv[]
/*
	fn();// �Լ� ȣ��(����);
	int rt = getValue(); // ���� �� int �� ���� ��ȯ�Ѵ�..
	// �Լ��� ��ȯ�� 1���� ����, ������ ���� �� ����
	int hap = Sum(2, 10);
*/
	// 1�� �迭�� �����Ѵ�... (�迭��, ����)
	int score[10] = { 0 };// ��ü ������ �ٽ� 1. ������
	int nums = printIntArray(score, 10);

	return 0;
}

// �Լ� ���Ǻ� /////////////////////////////////////
void fn(void)
{
	// ��ȯ��  void �� ��
	// return ���� ����
	return; // �Լ��� ����
}
int Sum(int a, int b)
{
	// �Ű������� �ִ� �Լ��� ȣ���� ����
	//	�ݵ�� �����ؾ� �Ѵ�....
	int s = a + b;
	return s;
}
// �迭�� ���޹޴� �Լ� �����
int printIntArray(int ar[], int length)
{
	// Q. �Ű����� �̴�..... �ٵ� int [] �迭
	int nums = 0;// ����� ������ ��ȯ
	for (int i = 0; i < length; ++i) {
		printf("%d ", ar[i]);
		nums++;
	}
	printf("\n");// ȭ�� �� ����
	return nums;
}
// END day4-1.c ///////////////////////////////////




