// library headers ////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables ///////////////////////////////////////
#pragma pack(1)
typedef struct _fileheader {
	short id;//	"BM"	ID field(42h, 4Dh)
	int fsize;// Size of the BMP file
	short unused1;
	short unused2;
	int offset;//54 bytes(14 + 40) : Offset where the pixel array(bitmap data) can be found
}BFH;
typedef struct _infoheader {
	int hsize;		//40 bytes:	Number of bytes in the DIB header(from this point)
	int width;		//pixels(left to right order)	Width of the bitmap in pixels
	int height;		//pixels(bottom to top order)	Height of the bitmap in pixels.Positive for bottom to top pixel order.
	short planes;	//1 plane	Number of color planes being used
	short bits;		//24 bits	Number of bits per pixel
	int compressed;	//BI_RGB, no pixel array compression used
	int tableSize;	//Size of the raw bitmap data(including padding)
	int resHeight;	//pixels / metre horizontal	Print resolution of the image,
	int resWidth;	//pixels / metre vertical
	int colors;		//Number of colors in the palette
	int important;	//important colors	0 means all colors are important

}BIH;
typedef struct _rgb {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}RGB;
typedef struct _bmpImage {
	BFH fh;
	BIH ih;
	RGB* table;
}BMP;
// section function body //////////////////////////////////
//int drawBox(int fromx, int fromy, int tox, int toy, )
// start program //////////////////////////////////////////
int main(int argc, char** argv) {
	BMP bmp = { 0 };
	printf("%d \n", sizeof(BMP));
	printf("%d \n", sizeof(bmp));
	bmp.ih.hsize = 40;
	bmp.ih.planes = 1;
	bmp.ih.bits = 24;
	bmp.ih.height = 400;
	bmp.ih.width = 800;
	bmp.ih.tableSize = 800 * 400 * sizeof(RGB);
	bmp.table = (RGB*)malloc(bmp.ih.tableSize);
	RGB red = { 0,0,255 };
	for (int i = 0; i < 800; ++i)
	{
		bmp.table[(10 * 800) + i] = red;
		bmp.table[(11 * 800) + i] = red;
		bmp.table[(12 * 800) + i] = red;
		bmp.table[(13 * 800) + i] = red;
		bmp.table[(14 * 800) + i] = red;
		bmp.table[(15 * 800) + i] = red;
		bmp.table[(16 * 800) + i] = red;
		bmp.table[(17 * 800) + i] = red;
		bmp.table[(18 * 800) + i] = red;
		bmp.table[(19 * 800) + i] = red;
		bmp.table[(20 * 800) + i] = red;
		bmp.table[(21 * 800) + i] = red;
		bmp.table[(22 * 800) + i] = red;
		bmp.table[(23 * 800) + i] = red;
		bmp.table[(24 * 800) + i] = red;
		bmp.table[(25 * 800) + i] = red;
		bmp.table[(26 * 800) + i] = red;
		bmp.table[(27 * 800) + i] = red;
		bmp.table[(28 * 800) + i] = red;
		bmp.table[(29 * 800) + i] = red;
		bmp.table[(30 * 800) + i] = red;
		bmp.table[(31 * 800) + i] = red;
		bmp.table[(32 * 800) + i] = red;
		bmp.table[(33 * 800) + i] = red;
		bmp.table[(34 * 800) + i] = red;
		bmp.table[(35 * 800) + i] = red;
		bmp.table[(36 * 800) + i] = red;
		bmp.table[(37 * 800) + i] = red;
		bmp.table[(38 * 800) + i] = red;
		bmp.table[(39 * 800) + i] = red;
		bmp.table[(40 * 800) + i] = red;
		bmp.table[(41 * 800) + i] = red;
		bmp.table[(42 * 800) + i] = red;
		bmp.table[(43 * 800) + i] = red;
		bmp.table[(351 * 800) + i] = red;
		bmp.table[(352 * 800) + i] = red;
		bmp.table[(1<=300 * 800) + i] = red;
		bmp.table[(354 * 800) + i] = red;
		bmp.table[(355 * 800) + i] = red;
		bmp.table[(356 * 800) + i] = red;
		bmp.table[(357 * 800) + i] = red;
		bmp.table[(358 * 800) + i] = red;
		bmp.table[(359 * 800) + i] = red;
		bmp.table[(360 * 800) + i] = red;
		bmp.table[(361 * 800) + i] = red;
		bmp.table[(362 * 800) + i] = red;
		bmp.table[(363 * 800) + i] = red;
		bmp.table[(364 * 800) + i] = red;
		bmp.table[(350 * 800) + i] = red;
		bmp.table[(350 * 800) + i] = red;
		bmp.table[(350 * 800) + i] = red;

	}
	//drawBox(10, 10, 50, 50, bmp.table);
	bmp.fh.id = 0x4D42;
	bmp.fh.fsize = bmp.ih.tableSize + 54;
	bmp.fh.offset = 54;
	
	FILE* fp;
	fopen_s(&fp, "user.bmp", "wb");
	fwrite(&bmp.fh, sizeof(bmp.fh), 1, fp);
	fwrite(&bmp.ih, sizeof(bmp.ih), 1, fp);
	fwrite(bmp.table, bmp.ih.tableSize, 1, fp);
	fclose(fp);
	return 0;
}
// end program
