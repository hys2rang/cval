#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
void get_sub_name(char sub_name[]);
int get_exm_cnt();
void get_exm_rlt(float exm_rlt[], int exm_cnt);
float get_total(float exm_rlt[], int exm_cnt);
float get_average(float total,int exm_cnt);
char get_grade(float average);
void print_result(char sub_name[],int exm_cnt, float exm_rlt[],float total,float average,char grade);
int main()
{
	char sub_name[15]; /* 과목 이름 */
	float exm_rlt[10]; /* 시험 점수 */
	int exm_cnt = 0; /* 시험 회수 */
	float total; /* 총점 */
	float average; /* 평균 */
	char grade; /* 학점 */

	get_sub_name(sub_name); /* 과목 이름 */

	exm_cnt = get_exm_cnt(); /* 시험 회수 */

	get_exm_rlt(exm_rlt, exm_cnt);/* 시험 점수*/

	total = get_total(exm_rlt, exm_cnt); /* 총점 계산 */

	average = get_average(total, exm_cnt); /* 평균 계산 */
	grade = get_grade(average); /* 학점을 계산합니다. */
	print_result(sub_name, exm_cnt, exm_rlt,
		total, average, grade); /* 모든 결과 */

	return 0;
}
void get_sub_name(char sub_name[])
{
	printf("과목의 이름을 입력하세요 : ");
	scanf("%s", sub_name);
}
int get_exm_cnt()
{
	int n;
	printf("시험 횟수를 입력하세요 : ");
	scanf("%d", &n);
	return n;
}
void get_exm_rlt(float exm_rlt[], int exm_cnt)
{
	for (int i = 0; i < exm_cnt; i++) {
		printf("%d차 시험 점수는 : ",i+1);
		scanf("%f", &exm_rlt[i]);
	}
}
float get_total(float exm_rlt[], int exm_cnt)
{
	float sum = 0;
	for (int i = 0; i < exm_cnt; i++) {
		sum += exm_rlt[i];
	}
	return sum;
}
float get_average(float total, int exm_cnt)
{
	return total / exm_cnt;
}
char get_grade(float average)
{
	char res = 'F';
	switch ((int)average/10)
	{
	case 10:
	case 9:
	case 8:
	case 7:
	case 6:
	case 5:
		res = 'A';
		break;
	case 4:
		res = 'B';
		break;
	case 3:
		res = 'C';
		break;
	default:
		res = 'F';
		break;
	}
	return res;
}
void print_result(char sub_name[], int exm_cnt, float exm_rlt[], float total, float average, char grade)
{
	printf("---결과---\n");
	printf("과목이름 : %s\n", sub_name);
	for (int i = 0; i < exm_cnt; i++) {
		printf("%d차 시험점수 : %d\n", i + 1, (int)exm_rlt[i]);
	}
	printf("총점 : %.2f\n", total);
	printf("평균 : %.2f\n", average);
	printf("학점 : %c", grade);
}
