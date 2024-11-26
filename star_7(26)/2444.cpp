#include<stdio.h>

int main(void) {
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < n - i; k++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n - 1; i > 0; i--) {
		for (int k = 0; k < n - i; k++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n"); //»©¸ÔÁö ¾Ê°Ô ÁÖÀÇ

	}
	return 0;
}