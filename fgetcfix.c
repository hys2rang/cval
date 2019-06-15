#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
/*
 FILE* in = NULL;
 FILE* out = NULL;

 int a;
 int i = 0;

 in = fopen("a.txt", "r");
 out = fopen("b.txt", "w");

 a = fgetc(in);
 while ((a != EOF)) {

  if (a == '\n')
   fprintf(out, "%d : ", i++);
  fputc(a, out);
  a = fgetc(in);

 }
 fclose(in);
 fclose(out);
*/
	FILE* in = NULL;
	FILE* out = NULL;

	int a;
	int i = 1;

	in = fopen("a.txt", "r");
	out = fopen("b.txt", "w");

	fprintf(out, "%d : ", i++);
	a = fgetc(in);
	while ((a != EOF)) {
		fputc(a, out);
		if (a == '\n') {
			fprintf(out, "%d : ", i++);
		}
		a = fgetc(in);

	}
	fclose(in);
	fclose(out);
	return 0;
}
