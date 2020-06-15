
#include <stdio.h>
#include <conio.h>

int main(void) {

	printf("%d \n", 0xE0);

	char ch = _getch();
	printf("%d \n", ch);
	ch = _getch();
	printf("%d \n", ch);

	return 0;
}