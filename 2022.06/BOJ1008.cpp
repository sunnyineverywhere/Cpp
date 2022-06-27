#include <stdio.h>

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%.9f\n", (double)a / b);
	return 0;
}
