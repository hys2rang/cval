#include <stdio.h>
#pragma warning(disable:4996)
struct subject {
	int subname[5];//국,영,수,total, rank
};
struct sung {
	char name[10];
	float avg;
	struct subject sub;
};
int main(int argc, char** argv)
{
	struct sung Grade[3];
	for (int i = 0; i < 3; i++) {
		printf("%d번째 사람이름 : ", i + 1);
		scanf("%s", Grade[i].name);
		printf("국어점수 : ");
		scanf("%d", &Grade[i].sub.subname[0]);
		printf("영어점수 : ");
		scanf("%d", &Grade[i].sub.subname[1]);
		printf("수학점수 : ");
		scanf("%d", &Grade[i].sub.subname[2]);

		Grade[i].sub.subname[3] = 0;
		for (int j = 0; j < 3; j++) {
			Grade[i].sub.subname[3] += Grade[i].sub.subname[j];
		}
		Grade[i].avg = (float)Grade[i].sub.subname[3] / 3;
	}

	for (int i = 0; i < 3; i++) {
		int idx = 1;
		for (int j = i + 1; j < 3; j++) {
			if (Grade[i].avg < Grade[j].avg) {
				idx++;
			}
		}
		Grade[i].sub.subname[4] = idx;
	}

	printf("성명\t국어\t영어\t수학\t총점\t순위\t평균\n");
	printf("===============================================================\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\t", Grade[i].name);
		for (int j = 0; j < 5; j++) {
			printf("%d\t", Grade[i].sub.subname[j]);
		}
		printf("%.2f\n", Grade[i].avg);
	}
	return 0;
}
