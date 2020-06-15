// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////


// section function body //////////////////////////////////
// ���� �����
// FILE �� ����ü, ������ ����
// �Լ��� ���� �˾��ּ���
// ����, �뵵�� ���� - ������, �׷�, �ܺ� - w���� r�б� x����
struct _data {
	int code;
	char name[80];
	int type;
};

int main(void){
	FILE* fp;
	// ���Ͽ� �����Ѵ�� �о���δ�
	// ���� ���Ŀ� ���缭 �Ѵ� 
	struct _data d = { 0 };
	d.code = 100;
	strncpy_s(d.name, 80, "���ǹ��ڿ�", strlen("���ǹ��ڿ�"));
	d.type = 1;

	fopen_s(&fp, "demo-user.dat", "wb");
	fwrite(&d, sizeof(d), 1, fp);

	fclose(fp);
	return 0;
}


int main_bio(void) {
	// �� ����� (���̳ʸ������)
	// ũ�� ������ �����
	FILE* fp;
	const char* fname = "demo-block.dat";
	char nums[5][20] = {"AK","BK","CK","DK"};
	//fopen_s(&fp, fname, "wb"); // ������
	fopen_s(&fp, fname, "rb");// �б���
	//fwrite(nums, sizeof(nums), 1, fp);// 80����Ʈ
	fread(nums, sizeof(nums), 1, fp);// 80����Ʈ
	//fwrite(nums, sizeof(int), 20, fp);// 80����Ʈ
	printf("%s \n", nums[0]);
	printf("%s \n", nums[1]);
	printf("%s \n", nums[2]);
	printf("%s \n", nums[3]);



	fclose(fp);
	return 0;
}


int main_write(void){
FILE* fp = NULL;
// ���� ����

fopen_s(&fp, "demo.txt", "w"); //���ϰ������� �Լ� char * == "" ���ڿ�
if (fp == NULL) {
	printf("not found error:%s\n", "demo.txt");
	return 0;
}
// �б� �Ǵ� ����(���)
// �ؽ�Ʈ ���� ���� �̹� ����Լ� �˰� �ִ�
fputc('A', fp);
fputc('\n', fp);
fputs("new world", fp); // ���ڿ� ��� // ���Ͽ� ���
// ��������, ���� ���� ������
fprintf(fp, "%d %s \n", 100, "korea");

// ���� �ݱ�
fclose(fp);




return 0;
}


// start program //////////////////////////////////////////
int main_append(void) {
	FILE* fp = NULL;
	fopen_s(&fp, "demo.txt", "a"); //���ϰ������� �Լ� char * == "" ���ڿ�
	if (fp == NULL) {
		printf("not found error:%s\n", "demo.txt");
		return 0;
	}
	fputc('A', fp);
	fputc('\n', fp);
	fputs("new world", fp); // ���ڿ� ��� // ���Ͽ� ���
	// ��������, ���� ���� ������
	fprintf(fp, "[LOG]%s : %d-%d-%d : %s \n",
		"192.168.0.1",2020,06,20, "bitcamp");

	// ���� �ݱ�
	fclose(fp);

	return 0;

}
// end program


