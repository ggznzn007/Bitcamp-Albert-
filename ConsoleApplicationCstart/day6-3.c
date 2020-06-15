// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////
#pragma pack(1)
typedef struct _fileheader {
	char date[14];
}BFH;
typedef struct _infoheader {
	char date[40];
}BIH;
typedef struct _rgb {
	char date[3];
}RGB;
typedef struct _bmpImage {
	BFH fh;
	BIH ih;
	RGB* table;
}BMP;
// section function body //////////////////////////////////




// start program //////////////////////////////////////////
int main(int argc, char** argv) {
	BMP bmp = { 0 };
	printf("%d \n", sizeof(BMP));
	printf("%d \n", sizeof(bmp));
	// bmp�� ��� table�� RGB�� ��ҷ� �ϴ� ���� 512�� �迭 �����϶�
	RGB pixel[512];
	bmp.table = pixel;// pixel + 0 == &pixel[0]

	// �����Ҵ�
	int countsOfpixel = 1024 * 768 * 3;// ���� * ���� * �ȼ�����
	bmp.table = (RGB*)malloc(countsOfpixel * sizeof(RGB));
	// �����Լ� ������ ���� ����
	free(bmp.table);



	return 0;
}






// end program






















