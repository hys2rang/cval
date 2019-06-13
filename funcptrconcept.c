#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void cold(void) {
	puts("cold");
}
void hot(void) {
	puts("hot");
}

void aircon(void(*p)(void)) {
	p();
}
int main(int argc, char** argv)
{
	aircon(cold);
	aircon(hot);
	return 0;
}


