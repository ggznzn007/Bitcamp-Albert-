#include <stdio.h>
#include <stdlib.h>
#define PAN_SIZE 19

// �м� - �۳� ������Ʈ �ҽ���... 
int team01(int pan[][PAN_SIZE], int* px, int* py)
{
	// ���� �����Ѵ�... ����, ��������
	static int mystone;

	if (*px == -1) {// ~��, �� ��
		// ������ ���۵Ǿ���. : 1���� ���� �� ������ ����
		// �غ� : �������� �ʱⰪ, �迭 ����...
		if (*py == -1) {// ���� �浹�̴�.
			mystone = 0;
		}
		if (*py == 0) {			// ���� �鵹�̴�.
			mystone = 1;
		}
	}
	else {// -1�� �ƴ� ��
		int x = rand()%PAN_SIZE;
		int y = rand() % PAN_SIZE;
		// ��밡 ���� ��� �ξ��°�
		// ���� ������ �� ���� �ΰڴ�....
		//	���޵Ǵ� *px, *py ������ ��ġ
		x = *px;
		y = *py;
		// ��ġ �ֺ��� 8�ڸ�
		for (int dy = y - 1; dy <= (y + 1); ++dy) {
			for (int dx = x - 1; dx <= (x + 1); ++dx) {
				if (pan[dy][dx] > 1) {
					x = dx;
					y = dy;
//					break;// �ݺ� ���� - ù �ݺ��� ����
					goto out;// ��ø �ݺ��� �� ���� �����
				}
			}
		}
		// pan[19][19] : ���� �Ǵ�
out:
		*px = x ;
		*py = y ;
	}

	return 0;
}
