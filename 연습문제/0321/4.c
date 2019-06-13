#include <stdio.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int celcius;

	printf("온도(C)를 입력하세요 : ");
	scanf("%d", &celcius);
	printf("화씨(F)온도는 %d입니다.", (int)(celcius*1.8) + 32);
	return 0;
}
