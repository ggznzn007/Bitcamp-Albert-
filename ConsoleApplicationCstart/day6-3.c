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
	// bmp의 멤버 table에 RGB를 요소로 하는 길이 512인 배열 생성하라
	RGB pixel[512];
	bmp.table = pixel;// pixel + 0 == &pixel[0]

	// 동적할당
	int countsOfpixel = 1024 * 768 * 3;// 가로 * 세로 * 픽셀개수
	bmp.table = (RGB*)malloc(countsOfpixel * sizeof(RGB));
	// 메인함수 끝나기 전에 해제
	free(bmp.table);



	return 0;
}






// end program






















