
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ���� ����� 
//	FILE �� ����ü, �����ͺ���
//		�Լ��� ���� �˾��ּ���
//	����, �뵵�� �ִ�... ������,�׷�,�ܺ� - w r x
struct _data {
	int code;
	char name[80];
	int type;
};
int main(void) {
	FILE* fp;
	// ���Ͽ� �����Ѵ�� �о���δ�...
	// ���Ͽ� ������ ������ ���� : format
	struct _data d = { 0 };
	d.code = 100;
	strncpy_s(d.name, 80, " ���ǹ��ڿ� ", strlen(" ���ǹ��ڿ� ") );
	d.type = 1;

	fopen_s(&fp, "demo-user.dat", "wb");
	fwrite(&d, sizeof(d), 1, fp);
	fclose(fp);

	struct _data t;
	fopen_s(&fp, "demo-user.dat", "rb");
	fread(&t, sizeof(t), 1, fp);
	fclose(fp);
	printf("%d %s %d \n", t.code, t.name, t.type);

	return 0;
}
int main_binary(void) {
	// �������(���̳ʸ������)
	// ũ�� ������ �����
	FILE* fp;
	const char* fname = "demo-block.dat";
	char nums[5][20] = { 0 };
	fopen_s(&fp, fname, "rb");
//	fwrite(nums, sizeof(nums), 1, fp);// 80����Ʈ
	fread(nums, sizeof(nums), 1, fp);// 80����Ʈ
	fclose(fp);
	printf("%s \n", nums[0]);
	printf("%s \n", nums[1]);
	printf("%s \n", nums[2]);
	printf("%s \n", nums[3]);
	return 0;
}
int main_append(void) {
	FILE* fp = NULL;
	fopen_s(&fp, "demo.txt", "a");
	// ������ ������ ���� ���� ���� �߰�
	//		  ������ ���� ����
	if (fp == NULL) {
		printf("not found error : %s \n", "demo.txt");
		return 0;
	}
	fprintf(fp, "[LOG]%s: %d-%d-%d : %s\n", 
		"192.168.0.1", 2020,10,20, "bicamp");
	// ���� �ݱ�
	fclose(fp);
	return 0;
}
int main_write(void) {
	FILE* fp = NULL;
	// ���� ����
	fopen_s(&fp,"demo.txt","w");// char * : ""
	if (fp == NULL) {
		printf("not found error : %s \n", "demo.txt");
		return 0;
	}
	// �б� �Ǵ� ����(���)
	// �ؽ�Ʈ ���� ����... �̹� ����Լ� �˰� �ִ�...
	fputc('A', fp);
	fputc('\n', fp);
	fputs("new new new new", fp);
	// ���� ����, ���� ���� ������
	fprintf(fp, "%d %s \n", 100, "korea");
	// ���� �ݱ�
	fclose(fp);
	return 0;
}