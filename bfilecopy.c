#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	char buf[100];
	int count;
	int num = 0;
	FILE *frp, *fwp;
	frp = fopen("1.png", "rb");
	fwp = fopen("2.png", "wb");
	while (1) {
		count = fread(buf, 1, 100, frp); //frp로 부터 100개를 1byte씩 읽어 버퍼에 넣겠다.
		if (count < 100) { //깨졌거나 끝이거나
			if (feof(frp) != 0) {
				fwrite(buf, 1, count, fwp);
				num += count;
				puts("끝!");
				break;
			}
			else {
				puts("파일이 깨짐");
				break;
			}
		}
		fwrite(buf, 1, 100, fwp);
		num += 100;
	}

	printf("%d byte copied", num);
	fclose(frp);
	fclose(fwp);
	return 0;
}
