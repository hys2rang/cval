#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
#define MAX -400000;
int main()
{
	//스무고개

	srand((unsigned)time(NULL));
	int ans = rand() % 100 + 1;
	int cnt=0;
	int buf = 0; //이미 알려줬는지
	while (++cnt) {
		int n;
		printf("숫자를 입력해보세요 : ");
		scanf("%d", &n);
		if (cnt>=2 && ((buf<=n && ans<n)|| (buf>=n && ans>n))) {
			printf("아니라고\n");
		}
		else {					
			if (ans > n) {
				printf("그보단 크지요\n");
			}
			else if (ans < n) {
				printf("그보단 적지요\n");
			}
			else {
				printf("%d번만에 맞추셨습니다.", cnt);
				break;
			}
			
		}
		buf = n;
	}
	return 0;
}
